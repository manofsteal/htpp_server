

#include <atomic>
#include <memory>

#include "Utils.h"

#include "Application.h"
#include "IOSocketSrv.h"
#include "IOEpoll.h"
#include "HttpService.h"
#include "EpollPool.h"
#include "IOSocketCli.h"


struct Application::Data {

    std::shared_ptr<IOSocketSrv> MIOSocketSrv;

    std::shared_ptr<EpollPool>   MEpolls;
    std::shared_ptr<HttpService> MHttpService;

    std::atomic<bool>            MExited;

};

Application::Application(): mData(std::make_unique<Data>()) {

}
Application::~Application()
{
    this->clean();
}

Status Application::setup() {
    //TODO: add os signal (SIGINT, SIGTERM...) handler here;

    static const std::string host = "0.0.0.0";
    static constexpr  std::uint16_t port = 8080;


    auto htppServiceBuilder = []() {
        auto service = std::make_shared<HttpService>();

    // Register a few endpoints for demo and benchmarking
        auto sayHello = [](const HttpRequest& request) -> HttpResponse {
            HttpResponse response(HttpStatusCode::Ok);
            response.setHeader("Content-Type", "text/plain");
            response.setContent("Hello, world\n");
            return response;
        };
        auto sendHtml = [](const HttpRequest& request) -> HttpResponse {
            HttpResponse response(HttpStatusCode::Ok);
            std::string content;
            content += "<!doctype html>\n";
            content += "<html>\n<body>\n\n";
            content += "<h1>Hello, world in an Html page</h1>\n";
            content += "<p>A Paragraph</p>\n\n";
            content += "</body>\n</html>\n";

            response.setHeader("Content-Type", "text/html");
            response.setContent(content);
            return response;
        };

        service->registerHandler("/", HttpMethod::HEAD, sayHello);
        service->registerHandler("/", HttpMethod::GET, sayHello);
        service->registerHandler("/hello.html", HttpMethod::HEAD, sendHtml);
        service->registerHandler("/hello.html", HttpMethod::GET, sendHtml);

        return service;

    };

    
    mData->MIOSocketSrv = std::make_shared<IOSocketSrv>(host, port);

    mData->MEpolls   = std::make_shared<EpollPool>(std::thread::hardware_concurrency(), (int)EpollConst::TimeoutInfinite);
    
    mData->MHttpService = htppServiceBuilder();
    

    auto status = mData->MIOSocketSrv->setup();
    if (status != Status::OK) {
        LOG() << "IOSocketSrv setup failed" << ENDL;
        return status;
    }

    LOG() << "Server is listening at " << host << ":" << port << std::endl;

    status = mData->MEpolls->setup();
    if (status != Status::OK) {
        // LOG() << "Epolls setup failed";
        return status;
    }

    return Status::OK;

}
Status Application::exec() {


    while(!mData->MExited) {
        
        auto clientFD = mData->MIOSocketSrv->listen();

        if (!clientFD)
            continue;

        auto ioSockCli  = std::make_shared<IOSocketCli>(*clientFD, mData->MHttpService);
        auto status = mData->MEpolls->add(*clientFD, EPOLLIN, ioSockCli);
        if (status != Status::OK) {
            LOG() << "Can not handle new socket client: " << *clientFD << ENDL;
        }

    };

    return Status::OK;
}
    
Status Application::clean() {
    //TODO: clean memory, other resource

    return Status::OK;
}
