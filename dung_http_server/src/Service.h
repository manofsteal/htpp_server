#ifndef SERVICE_H
#define SERVICE_H

#include <ServiceIF.h>

class Service: public ServiceIF {
public:
    virtual ~Service();
    std::optional<Reponse> handle(const Request& req) override;
};

#endif 
