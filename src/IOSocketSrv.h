#ifndef IO_SOCKET_SRV_H
#define IO_SOCKET_SRV_H

#include "ListenerIF.h"
#include <string>


class IOSocketSrv: public ListenerIF {
public:

    enum Const {
        BacklogSize = 1000,
    };

    virtual ~IOSocketSrv();
    IOSocketSrv(std::string host, std::uint16_t port);

    virtual Status setup() override;
    std::optional<os::FileDesc> listen() override;

private:

    os::FileDesc mSockFD;
    std::string mHost;
    std::uint16_t mPort;

};

#endif 
