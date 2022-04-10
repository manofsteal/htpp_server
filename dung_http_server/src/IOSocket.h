#ifndef IO_SOCKET_H_
#define IO_SOCKET_H_

#include <Linux.h>
#include <memory>

#include "EpollHandlerIF.h"


class HttpServiceIF;

class IOSocket: public EpollHandlerIF {
public:

    IOSocket(os::FileDesc fd, std::shared_ptr<HttpServiceIF> service = nullptr);
    virtual ~IOSocket();

    void handle(const epoll_event&, IOEpoll*) override;

    void recv(const std::vector<uint8_t>& msgIn, std::vector<uint8_t>& msgWriteBack) override;

private:
    os::FileDesc mFD;
    std::shared_ptr<HttpServiceIF> mService;
};

#endif