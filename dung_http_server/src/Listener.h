#ifndef LISTENER_H
#define LISTENER_H

#include <ListenerIF.h>
#include <string>


class Listener: public ListenerIF {
public:
    virtual ~Listener();
    Listener(std::string host, std::uint16_t port);

    virtual Status setup() override;
    std::optional<os::FileDesc> listen() override;

private:

    static constexpr int kBacklogSize = 1000;
    static constexpr int kMaxConnections = 10000;
    static constexpr int kMaxEvents = 10000;
    static constexpr int kThreadPoolSize = 5;

    os::FileDesc mSockFD;
    std::string mHost;
    std::uint16_t mPort;

};

#endif 
