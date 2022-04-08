#ifndef IOREADER_IF_H_
#define IOREADER_IF_H_


#include <Utils.h>
#include <Request.h>
#include <Reponse.h>

class HttpClientIF {
public:
    virtual ~HttpClientIF() = default;        
    virtual Status handle(const Request& req, Reponse& res) = 0;
};

#endif 