#ifndef SERVICE_H
#define SERVICE_H

#include <ServiceIF.h>

class Service: public ServiceIF {
public:
    virtual ~Service();
    void handle(const Event& ev) override;
};

#endif 
