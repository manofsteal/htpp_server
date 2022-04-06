#ifndef POLLER_H
#define POLLER_H

#include <PollerIF.h>

class Poller: public PollerIF {
public:
    virtual ~Poller();
    std::optional<Event> poll(const os::FileDesc& fd) override;
};

#endif 

