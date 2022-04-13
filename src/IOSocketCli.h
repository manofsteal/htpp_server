#ifndef IO_SOCKET_CLI_H_
#define IO_SOCKET_CLI_H_

#include "Linux.h"
#include <memory>
#include "ReceiverIF.h"
#include "SenderIF.h"

class HttpServiceIF;
class ExecutorIF;
class IOWriterIF;



class IOSocketCli: public ReceiverIF, SenderIF, std::enable_shared_from_this<IOSocketCli> {
public:

    IOSocketCli(os::FileDesc fd, std::shared_ptr<HttpServiceIF> service, std::shared_ptr<IOWriterIF> ioWriter, std::shared_ptr<ExecutorIF> executor);
    virtual ~IOSocketCli();

    void recv(const std::vector<uint8_t>& msgIn) override;
    Status send(const std::vector<uint8_t>& buffer ) override;

private:
    os::FileDesc mFD;
    std::shared_ptr<HttpServiceIF> mService;
    std::shared_ptr<ExecutorIF>    mExecutor;
    std::shared_ptr<IOWriterIF>       mIOWriter;

};

#endif