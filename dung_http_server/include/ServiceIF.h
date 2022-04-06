#ifndef SERVICE_H
#define SERVICE_H

#include <optional>
#include <Request.h>
#include <Reponse.h>

class ServiceIF {
public:
    virtual ~ServiceIF() = default;
    virtual std::optional<Reponse> handle(const Request& req) = 0;
};

#endif 
