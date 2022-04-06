#ifndef POLLER_IF_H
#define POLLER_IF_H

#include <optional>

#include <Linux.h>
#include <Event.h>

class PollerIF {
public:
    virtual ~PollerIF() = default;
    virtual  std::optional<Event> poll(const linux::FileDesc& fd) = 0;
};

#endif 

