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

// A request handler should expect a request as argument and returns a response
using HttpRequestHandler_t = std::function<HttpResponse(const HttpRequest&)>;

class HttpService: public HttpServiceIF {
public:

  virtual  ~HttpService();

  HttpResponse handle(const HttpRequest& request) override;

  void RegisterHttpRequestHandler(const std::string& path, HttpMethod method, const HttpRequestHandler_t callback) {
    Uri uri(path);
    request_handlers_[uri].insert(std::make_pair(method, std::move(callback)));
  }
  void RegisterHttpRequestHandler(const Uri& uri, HttpMethod method, const HttpRequestHandler_t callback) {
    request_handlers_[uri].insert(std::make_pair(method, std::move(callback)));
  }


private:

  std::map<Uri, std::map<HttpMethod, HttpRequestHandler_t>> request_handlers_;


};



#endif  // HTTP_SERVICE_H_

