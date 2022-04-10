#include "IOSocket.h"
#include <Utils.h>
#include "HttpService.h"
#include "IOEpoll.h"


IOSocket::IOSocket(os::FileDesc fd, std::shared_ptr<HttpServiceIF> service)
    : mFD(fd), mService(service) {
    
}
IOSocket::~IOSocket() {

}

void IOSocket::handle(const epoll_event&, IOEpoll* ioEpoll) {
  LOG() << "IOSocket: handle()" << ENDL;
}


void IOSocket::recv(const std::vector<uint8_t>& msgIn, std::vector<uint8_t>& msgWriteBack) {
    LOG() << "IOSocket::recv msgIn: " << msgIn.size() << ENDL;
    msgWriteBack.clear();
    // msgWriteBack.push_back(1);
    // msgWriteBack.push_back(2);

    //TODO parse req, resx

    std::string reqStr((char*)msgIn.data(), msgIn.size());
    HttpRequest req = string_to_request(reqStr);
    HttpResponse res;

    if (!mService) {
        res = HttpResponse(HttpStatusCode::InternalServerError);
        res.SetContent(code_to_string(HttpStatusCode::InternalServerError));
    } else if (!req.code()) {
        res = mService->handle(req);
    } else {
        auto code = *(req.code());
        res = HttpResponse(code);
        res.SetContent(code_to_string(code));
    }
    
  // Set response to write to client
    auto resStr = to_string(res, req.method() != HttpMethod::HEAD);
    LOG() << "IOSocket::res: " << resStr;
    std::copy(resStr.begin(), resStr.end(), std::back_inserter(msgWriteBack));

}