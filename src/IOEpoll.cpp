//
// Created by marvinle on 2019/2/26 8:08 PM.
//

#include "IOEpoll.h"

#include <iostream>
#include <vector>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
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


Status IOEpoll::add(os::FileDesc fd, uint32_t events, std::shared_ptr<ReceiverIF> handler) {
    epoll_event event;
    event.events = (EPOLLIN|EPOLLET);
    event.data.fd = fd;
    auto eventData = std::make_shared<EventData>(fd, this);
    event.data.ptr = eventData.get();

    int ret = ::epoll_ctl(mEpollFD, EPOLL_CTL_ADD, fd, &event);
    if (ret < 0) {
        LOG() << "epoll add error" << endl;
        return Status::N_OK;
    }

    mIOHandler[fd] = handler;
    mEventDatas[fd] = eventData;

    return Status::OK;
}

Status IOEpoll::mod(os::FileDesc fd, uint32_t events, std::shared_ptr<ReceiverIF> handler) {
    epoll_event event;
    event.events = events;
    event.data.fd = fd;

    auto it = mEventDatas.find(fd);
    if (it == mEventDatas.end()) {
        auto eventData = std::make_shared<EventData>(fd, this);
        mEventDatas[fd] = eventData;
        event.data.ptr = eventData.get();
    } else {
        event.data.ptr = it->second.get();
    }

    int ret = ::epoll_ctl(mEpollFD, EPOLL_CTL_MOD, fd, &event);
    if (ret < 0) {
        LOG() << "epoll mod error" << endl;
        return Status::N_OK;
    }

    mIOHandler[fd] = handler;
    
    return Status::OK;
}

Status IOEpoll::mod(os::FileDesc fd, uint32_t events) {
    epoll_event event;
    event.events = events;
    event.data.fd = fd;

    auto it = mEventDatas.find(fd);
    if (it == mEventDatas.end()) {
        auto eventData = std::make_shared<EventData>(fd, this);
        mEventDatas[fd] = eventData;
        event.data.ptr = eventData.get();
    } else {
        event.data.ptr = it->second.get();
    }

    int ret = ::epoll_ctl(mEpollFD, EPOLL_CTL_MOD, fd, &event);
    if (ret < 0) {
        LOG() << "epoll mod error" << endl;
        return Status::N_OK;
    }

    return Status::OK;
}

Status IOEpoll::del(os::FileDesc fd) {

    int ret = epoll_ctl(mEpollFD, EPOLL_CTL_DEL, fd, nullptr);
    if (ret < 0) {
        std::cout << "epoll del error" << endl;
        return Status::N_OK;
    }
    ::close(fd);

    auto it = mIOHandler.find(fd);
    if (it != mIOHandler.end()) {
        mIOHandler.erase(it);
    }

    auto it2 = mEventDatas.find(fd);
    if (it2 != mEventDatas.end()) {
        mEventDatas.erase(it2);
    }
    return Status::OK;
}


Status IOEpoll::write(os::FileDesc fd, const std::vector<uint8_t>& buffer) {
    
    auto it = mEventDatas.find(fd);
    if (it == mEventDatas.end())
        return Status::N_OK;
    
    auto eventData = it->second;

    this->mod(eventData->MFD, EPOLLOUT);

    eventData->MBuffer = buffer;
    eventData->MBufLen = buffer.size();
    eventData->MBufIndex = 0;

    LOG() << "epoll::write " << ENDL;
    ssize_t byteCount = ::write(eventData->MFD, (void*)(&eventData->MBuffer[eventData->MBufIndex]), eventData->MBufLen);
    if (byteCount >= 0) {
        LOG() << "epoll::write OK" << ENDL;
        return Status::OK;
    }

    LOG() << "epoll::write N_OK" << ENDL;
    return Status::N_OK;

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

      if (eventData->MIOEpoll == nullptr)
        continue;
  
      if ((event.events == EPOLLIN) || (event.events == EPOLLOUT)) {

    
        auto it = mIOHandler.find(eventData->MFD);
        if (it == mIOHandler.end()) {
            // LOG() << "FD: " << fd << " not found handler" << ENDL;
            
        } else {
            // LOG() << "FD: " << fd << " found" << ENDL;
            auto handler = it->second;

            if (event.events == EPOLLIN) {

                // LOG() << "epoll::event: EPOLLIN" << ENDL;

                eventData->MBufDir = EventData::IN;
    
                char buffer[(size_t)EpollConst::MaxBufferSize];
                // auto reponse = std::make_shared<EventData>(fd, this);
                ssize_t byteCount = recv(eventData->MFD, buffer, (size_t)EpollConst::MaxBufferSize, 0);
                if (byteCount > 0) {         
                      // we have fully received the message
                    // LOG() << "epoll::recv: byteCount: " << byteCount  << ENDL;
                    std::vector<uint8_t> msgIn(byteCount);
                    std::copy(buffer, buffer + byteCount, std::back_inserter(msgIn));
                    
                    handler->recv(msgIn);
                    // if (eventData->MBuffer.size() > 0) {
                    //     LOG() << "epoll::writeback: byteCount: " << eventData->MBuffer.size()  << ENDL;
                    //     eventData->MBufLen = eventData->MBuffer.size();
                    //     eventData->MBufIndex = 0;
                    //     this->mod(eventData->MFD, EPOLLOUT);
                    // }
              
                } else if (byteCount == 0) {   // client has closed connection
                    
                    // LOG() << "epoll::recv: byteCount = 0, client has closed connection" << ENDL;
                    this->del(eventData->MFD);
                } else {
                    if (os::SystemError() == EAGAIN || os::SystemError() == EWOULDBLOCK) {  // retry
                       
                        // LOG() << "epoll::recv: system error, retry" << ENDL;
                        this->mod(eventData->MFD, EPOLLIN);
                    } else {                                        // other error
                        
                        // LOG() << "epoll::recv: unknown case, del" << ENDL;
                        this->del(eventData->MFD);
                    }
                }
            } else {
         
                // LOG() << "epoll::event: EPOLLOUT" << ENDL;

                eventData->MBufDir = EventData::OUT;

                if (eventData->MBufLen > 0) {
                    ssize_t byteCount = send(eventData->MFD, &eventData->MBuffer[eventData->MBufIndex] , eventData->MBufLen, 0);
                    if (byteCount >= 0) {
                        if (byteCount < eventData->MBuffer.size()) {  // there are still bytes to write
                            eventData->MBufIndex += byteCount;
                            if (eventData->MBufLen < byteCount)
                                eventData->MBufLen = 0;
                            else 
                                eventData->MBufLen   -= byteCount;
                
                            LOG() << "epoll::send: byteCount: " << byteCount << ENDL;
                            this->mod(eventData->MFD, EPOLLOUT);

                        } else {                              // we have written the complete message

                            eventData->MBufDir = EventData::IN;
                        
                            LOG() << "epoll::send: completed" << ENDL;
                            this->mod(eventData->MFD, EPOLLIN);

                        }
                    } else {
                        if (os::SystemError() == EAGAIN || os::SystemError() == EWOULDBLOCK) {  // retry
                        
                            // LOG() << "epoll::write: system error, retry" << ENDL;
                            this->mod(eventData->MFD, EPOLLOUT);
                        } else {                                        // other error
                        
                            // LOG() << "epoll::write: unknown case, del" << ENDL;
                            this->del(eventData->MFD);
    
                        }
                    }
                } else {
                    // LOG() << "epoll::write: unknown case, del" << ENDL;
                    // this->del(eventData->MFD);
                    this->mod(eventData->MFD, EPOLLIN);

                }
            }
        }
      } else {

        // LOG() << "event: something else" << ENDL;
        this->del(eventData->MFD);
      }
    }

    return Status::OK;
    
}

IOEpoll::~IOEpoll() {
    
}