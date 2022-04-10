// Defines the HTTP server object with some constants and structs
// useful for request handling and improving performance

#ifndef HTTP_SERVICE_H_
#define HTTP_SERVICE_H_

#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <chrono>
#include <functional>
#include <map>
#include <string>
#include <thread>
#include <utility>

#include "Uri.h"
#include "HttpServiceIF.h"


using HttpRequestHandler = std::function<HttpResponse(const HttpRequest&)>;

class HttpService: public HttpServiceIF {
public:

  virtual  ~HttpService();

  HttpResponse handle(const HttpRequest& request) override;

  void registerHandler(const std::string& path, HttpMethod method, const HttpRequestHandler callback);
  void registerHandler(const Uri& uri, HttpMethod method, const HttpRequestHandler callback);


private:

  std::map<Uri, std::map<HttpMethod, HttpRequestHandler>> mHandlers;


};



#endif  // HTTP_SERVICE_H_

