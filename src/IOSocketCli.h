#ifndef IO_SOCKET_CLI_H_
#define IO_SOCKET_CLI_H_

#include "Linux.h"
#include <memory>

#include "EpollHandlerIF.h"

class HttpServiceIF;

class IOSocketCli: public EpollHandlerIF {
public:

    IOSocketCli(os::FileDesc fd, std::shared_ptr<HttpServiceIF> service = nullptr);
    virtual ~IOSocketCli();

    void recv(const std::vector<uint8_t>& msgIn, std::vector<uint8_t>& msgWriteBack) override;

private:
    os::FileDesc mFD;
    std::shared_ptr<HttpServiceIF> mService;
};

#endif