#ifndef HTTP_SERVICE_IF_H_
#define HTTP_SERVICE_IF_H_


#include "HttpMessage.h"

class HttpServiceIF {
public:

  virtual  ~HttpServiceIF() = default;
  virtual  HttpResponse handle(const HttpRequest& request) = 0;

};


#endif 