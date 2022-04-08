#ifndef HTTP_CLIENT_H_
#define HTTP_CLIENT_H_

#include <HttpClientIF.h>
#include <memory>
#include "IOSocketet.h"

class HttpClient: public HttpClientIF {
public:
    virtual ~HttpClient(); 
    HttpClient(std::shared_ptr<IOSocket>);
    
    Status handle(const Request& req, Reponse& res) override;

private:
   std::shared_ptr<IOSocket> mSockClient;
};


#endif 