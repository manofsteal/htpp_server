#include "IOSocketCli.h"
#include "Utils.h"
#include "HttpService.h"
#include "IOEpoll.h"
#include "ExecutorIF.h"
#include "IOWriterIF.h"



IOSocketCli::IOSocketCli(os::FileDesc fd, std::shared_ptr<HttpServiceIF> service, std::shared_ptr<IOWriterIF> ioWriter, std::shared_ptr<ExecutorIF> executor)
    : mFD(fd), mService(service), mIOWriter(ioWriter), mExecutor(executor) {
    
}
IOSocketCli::~IOSocketCli() {

}

void IOSocketCli::recv(const std::vector<uint8_t>& msgIn) {
    LOG() << "IOSocketCli::recv msgIn: " << msgIn.size() << ENDL;


    auto task = std::make_shared<Task>([sockCli = shared_from_this(), msgIn, service = mService]() {
        
        std::string reqStr((char*)msgIn.data(), msgIn.size());
        HttpRequest req = utils::ReqFromString(reqStr);
        HttpResponse res;

        if (service) {
            res = HttpResponse(HttpStatusCode::InternalServerError);
            res.setContent(utils::CodeToString(HttpStatusCode::InternalServerError));
        } else if (!req.code()) {
            res = service->handle(req);
        } else {
            auto code = *(req.code());
            res = HttpResponse(code);
            res.setContent(utils::CodeToString(code));
        }
    
        auto resStr = utils::ResToString(res, req.method() != HttpMethod::HEAD);
        LOG() << "IOSocketCli::res: " << resStr;

        if (sockCli) {
            std::vector<uint8_t> buffer;
            std::copy(resStr.begin(), resStr.end(), std::back_inserter(buffer));
            return sockCli->send(buffer);
        } else {
            LOG() << "IOSocketCli = nullptr";
            return Status::N_OK;
        }

        
    });
    
    mExecutor->exec(task);

}

Status IOSocketCli::send(const std::vector<uint8_t>& buffer) {
    return mIOWriter->write(mFD, buffer);
}

