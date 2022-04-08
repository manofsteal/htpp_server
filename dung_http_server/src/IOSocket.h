#ifndef IOEPOLL_FD_H_
#define IOEPOLL_FD_H_

#include <Linux.h>
#include <IORWriterIF.h>
#include <memory>

class IOSocket: public IOWriterIF {
public:

    IOSocket(os::FileDesc fd);
    virtual ~IOSocket();

    std::optional<int> read(std::vector<uint8_t>& buffer) override;  
    std::optional<int> write(const std::vector<uint8_t>& buffer) override;

private:
    os::FileDesc fd;
};

#endif