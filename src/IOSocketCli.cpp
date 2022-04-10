#include "IOSocketCli.h"
#include "Utils.h"
#include "HttpService.h"
#include "IOEpoll.h"


IOSocketCli::IOSocketCli(os::FileDesc fd, std::shared_ptr<HttpServiceIF> service)
    : mFD(fd), mService(service) {
    
}
IOSocketCli::~IOSocketCli() {

}

void IOSocketCli::recv(const std::vector<uint8_t>& msgIn, std::vector<uint8_t>& msgWriteBack) {
    LOG() << "IOSocketCli::recv msgIn: " << msgIn.size() << ENDL;
    msgWriteBack.clear();

    std::string reqStr((char*)msgIn.data(), msgIn.size());
    HttpRequest req = utils::ReqFromString(reqStr);
    HttpResponse res;

    if (!mService) {
        res = HttpResponse(HttpStatusCode::InternalServerError);
        res.setContent(utils::CodeToString(HttpStatusCode::InternalServerError));
    } else if (!req.code()) {
        res = mService->handle(req);
    } else {
        auto code = *(req.code());
        res = HttpResponse(code);
        res.setContent(utils::CodeToString(code));
    }
    
  // Set response to write to client
    auto resStr = utils::ResToString(res, req.method() != HttpMethod::HEAD);
    LOG() << "IOSocketCli::res: " << resStr;
    std::copy(resStr.begin(), resStr.end(), std::back_inserter(msgWriteBack));

}