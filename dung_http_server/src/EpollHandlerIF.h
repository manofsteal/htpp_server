

#ifndef EPOLL_HANDLER_IF_H_
#define EPOLL_HANDLER_IF_H_


#include <sys/epoll.h>
#include <vector>
#include <optional>
class IOEpoll;

class EpollHandlerIF {
public:
    virtual ~EpollHandlerIF() = default;
    virtual void handle(const epoll_event&, IOEpoll*) = 0;
    virtual void recv(const std::vector<uint8_t>& msgIn, std::vector<uint8_t>& msgWriteBack) = 0;
};

#endif 