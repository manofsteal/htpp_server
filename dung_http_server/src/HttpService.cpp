#include "HttpService.h"

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <chrono>
#include <cerrno>
#include <cstring>
#include <functional>
#include <map>
#include <stdexcept>
#include <string>
#include <sstream>

#include "HttpMessage.h"
#include "Uri.h"


HttpService::~HttpService() {

}

HttpResponse HttpService::handle(const HttpRequest& request) {
  auto it = request_handlers_.find(request.uri());
  if (it == request_handlers_.end()) {    // this uri is not registered
    return HttpResponse(HttpStatusCode::NotFound);
  }
  auto callback_it = it->second.find(request.method());
  if (callback_it == it->second.end()) {  // no handler for this method
    return HttpResponse(HttpStatusCode::MethodNotAllowed);
  }
  return callback_it->second(request);    // call handler to process the request
}



