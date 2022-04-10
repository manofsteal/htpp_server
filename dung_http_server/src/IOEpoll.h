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
#include "EpollHandlerIF.h"


enum class EpollConst {
    TimeoutInfinite = -1,
    MaxBufferSize = 4096,
};


class IOEpoll {

public:

    IOEpoll(int timeout);


    Status setup();

    Status add(os::FileDesc fd, uint32_t events, std::shared_ptr<EpollHandlerIF> handler);

    Status mod(os::FileDesc fd, uint32_t events, std::shared_ptr<EpollHandlerIF> handler);
    Status mod(os::FileDesc fd, uint32_t events);

    Status del(os::FileDesc fd);

    Status write(os::FileDesc fd, const std::vector<uint8_t>& buffer);

    Status poll();


public:

    struct EventData {
        EventData(os::FileDesc fd, IOEpoll*epoll = nullptr):
            MFD(fd), MIOEpoll(epoll) {

            }

        enum Direction {
            IN, 
            OUT,
        };
        
        os::FileDesc MFD;
        IOEpoll* MIOEpoll;

        Direction MBufDir;
        std::vector<uint8_t> MBuffer;
        size_t MBufIndex{0};
        size_t MBufLen{0}; // remaining length of data to send
    };

    static constexpr int MAX_EVENTS = 10000;

    static constexpr uint32_t DEFAULT_EVENTS = EPOLLIN | EPOLLET | EPOLLONESHOT;

    os::FileDesc mEpollFD;
    std::unordered_map<os::FileDesc, std::shared_ptr<EpollHandlerIF>> mIOHandler;
    std::unordered_map<os::FileDesc, std::shared_ptr<EventData>>      mEventDatas;
    // std::unordered_map<os::FileDesc, std::shared_ptr<EpollData>> mEventData;

    epoll_event mEvents[MAX_EVENTS];
    int mTimeout;

};

#endif //WEBSERVER_EPOLL_H