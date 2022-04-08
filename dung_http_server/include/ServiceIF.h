#ifndef SERVICE_IF_H
#define SERVICE_IF_H

#include <optional>
#include <Event.h>

class ServiceIF {
public:
    virtual ~ServiceIF() = default;
    virtual void handle(const Event& ev) = 0;
};

#endif 
