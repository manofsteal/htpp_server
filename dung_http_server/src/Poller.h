#ifndef POLLER_H
#define POLLER_H

#include <PollerIF.h>
#include <Linux.h>

class Poller: public PollerIF {
public:
    virtual ~Poller();
    std::optional<Event> poll(const os::FileDesc& fd) override;

private:
    os::FileDesc mEpollFD;
};

#endif 

