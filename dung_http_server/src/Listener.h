#ifndef LISTENER_H
#define LISTENER_H

#include <ListenerIF.h>

class Listener: public ListenerIF{
public:
    virtual ~Listener();
    os::FileDesc listen() override;
};

#endif 
