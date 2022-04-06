#ifndef LISTENER_IF_H
#define LISTENER_IF_H

#include <Linux.h>

class ListenerIF {
public:
    virtual ~ListenerIF() = default;
    virtual linux::FileDesc listen() = 0;
};

#endif 
