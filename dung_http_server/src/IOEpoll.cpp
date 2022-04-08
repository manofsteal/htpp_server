//
// Created by marvinle on 2019/2/26 8:08 PM.
//

#include "IOEpoll.h"

#include <iostream>
#include <vector>
#include <sys/epoll.h>
#include <cstdio>

using namespace std;

IOEpoll::IOEpoll(int timeout): mTimeout(timeout) {

}

Status IOEpoll::setup() {
    mEpollFD = ::epoll_create1(0);
    if (mEpollFD < 0) {
        LOG() << "epoll create error" << std::endl;
        return Status::N_OK;
    }
    return Status::OK;
}


Status IOEpoll::add(os::FileDesc fd, uint32_t events, Handler handler) {
    epoll_event event;
    event.events = (EPOLLIN|EPOLLET);
    event.data.fd = fd;
    auto epollData = std::make_shared<EventData>(fd, this);
    event.data.ptr = epollData.get();

    int ret = ::epoll_ctl(mEpollFD, EPOLL_CTL_ADD, fd, &event);
    if (ret < 0) {
        LOG() << "epoll add error" << endl;
        return Status::N_OK;
    }

    mIOHandler[fd] = handler;

    return Status::OK;
}

Status IOEpoll::mod(os::FileDesc fd, uint32_t events, Handler handler) {
    epoll_event event;
    event.events = events;
    event.data.fd = fd;

    auto epollData = std::make_shared<EventData>(fd, this);
    event.data.ptr = epollData.get();

    int ret = ::epoll_ctl(mEpollFD, EPOLL_CTL_MOD, fd, &event);
    if (ret < 0) {
        LOG() << "epoll mod error" << endl;
        return Status::N_OK;
    }

    mIOHandler[fd] = handler;

    return Status::OK;
}

Status IOEpoll::del(os::FileDesc fd, uint32_t events) {

    epoll_event event;
    event.events = events;
    event.data.fd = fd;
    event.data.ptr = this;

    int ret = epoll_ctl(mEpollFD, EPOLL_CTL_DEL, fd, &event);
    if (ret < 0) {
        std::cout << "epoll del error" << endl;
        return Status::N_OK;
    }
    auto it = mIOHandler.find(fd);
    if (it != mIOHandler.end()) {
        mIOHandler.erase(it);
    }
    return Status::OK;
}


Status IOEpoll::poll() {

    LOG() << "epoll_wait: blocked" << ENDL;
    int nfds = epoll_wait(mEpollFD, mEvents, MAX_EVENTS, mTimeout);
    if (nfds < 0) {
      return Status::N_OK;
    }

    LOG() << "epoll events: " << nfds << ENDL;

    for (int i = 0; i < nfds; i++) {
      
      const epoll_event& event = mEvents[i];

      auto eventData = reinterpret_cast<EventData*>(event.data.ptr);
      
      auto fd = eventData->MFD;

      auto& handlers = eventData->MIOEpoll->mIOHandler;

      if ((event.events == EPOLLIN) || (event.events == EPOLLOUT)) {

           LOG() << "event: EPOLLIN || EPOLLOUT" << ENDL;

          auto it = handlers.find(fd);
          if (it == handlers.end()) {
            LOG() << "FD: " << fd << " not found handler" << ENDL;
            continue;
          }
          Handler& handler = it->second;
          handler(event, this);
      } else {
          //TODO: remove this fd
          LOG() << "event: something else" << ENDL;
      }
    }

    return Status::OK;
    
}