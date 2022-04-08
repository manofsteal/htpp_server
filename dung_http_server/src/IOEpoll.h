//
// Created by marvinle on 2019/2/26 5:11 PM.
//

#ifndef IO_EPOLL_H_
#define IO_EPOLL_H_


#include <sys/epoll.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <Linux.h>
#include <IORWriterIF.h>
#include <Utils.h>
#include <functional>

class IOEpoll {

public:

    IOEpoll(int timeout);

    using Handler = std::function<void(const epoll_event&, IOEpoll*)>;

    Status setup();

    Status add(os::FileDesc fd, uint32_t events, Handler handler);

    Status mod(os::FileDesc fd, uint32_t events, Handler handler);

    Status del(os::FileDesc fd, uint32_t events);

    Status poll();


public:

    struct EventData {
        EventData(os::FileDesc fd, IOEpoll*epoll):
            MFD(fd), MIOEpoll(epoll) {
                
            }
        os::FileDesc MFD;
        IOEpoll* MIOEpoll;
    };

    static constexpr int MAX_EVENTS = 10000;

    static constexpr uint32_t DEFAULT_EVENTS = EPOLLIN | EPOLLET | EPOLLONESHOT;

    os::FileDesc mEpollFD;
    std::unordered_map<os::FileDesc, Handler> mIOHandler;
    // std::unordered_map<os::FileDesc, std::shared_ptr<EpollData>> mEventData;

    epoll_event mEvents[MAX_EVENTS];
    int mTimeout;

};

#endif //WEBSERVER_EPOLL_H