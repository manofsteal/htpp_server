

#ifndef EPOLL_HANDLER_IF_H_
#define EPOLL_HANDLER_IF_H_


#include <vector>


class EpollHandlerIF {
public:
    virtual ~EpollHandlerIF() = default;
    virtual void recv(const std::vector<uint8_t>& msgIn, std::vector<uint8_t>& msgWriteBack) = 0;
};

#endif 