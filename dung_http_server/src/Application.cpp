#include "Application.h"
#include "Listener.h"

#include <atomic>
#include <memory>
#include "IOEpoll.h"
#include "HttpService.h"
#include "EpollPool.h"
#include "IOSocket.h"

struct Application::Data {

    std::shared_ptr<Listener>    MListener;

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
        auto say_hello = [](const HttpRequest& request) -> HttpResponse {
            HttpResponse response(HttpStatusCode::Ok);
            response.SetHeader("Content-Type", "text/plain");
            response.SetContent("Hello, world\n");
            return response;
        };
        auto send_html = [](const HttpRequest& request) -> HttpResponse {
            HttpResponse response(HttpStatusCode::Ok);
            std::string content;
            content += "<!doctype html>\n";
            content += "<html>\n<body>\n\n";
            content += "<h1>Hello, world in an Html page</h1>\n";
            content += "<p>A Paragraph</p>\n\n";
            content += "</body>\n</html>\n";

            response.SetHeader("Content-Type", "text/html");
            response.SetContent(content);
            return response;
        };

        service->RegisterHttpRequestHandler("/", HttpMethod::HEAD, say_hello);
        service->RegisterHttpRequestHandler("/", HttpMethod::GET, say_hello);
        service->RegisterHttpRequestHandler("/hello.html", HttpMethod::HEAD, send_html);
        service->RegisterHttpRequestHandler("/hello.html", HttpMethod::GET, send_html);

        return service;

    };

    
    mData->MListener = std::make_shared<Listener>(host, port);
    mData->MEpolls   = std::make_shared<EpollPool>(8, (int)EpollConst::TimeoutInfinite);
    
    mData->MHttpService = htppServiceBuilder();
    

    auto status = mData->MListener->setup();
    if (status != Status::OK) {
        LOG() << "Listener setup failed";
        return status;
    }

    LOG() << "Server is listening at " << host << ":" << port << std::endl;

    status = mData->MEpolls->setup();
    if (status != Status::OK) {
        LOG() << "Epolls setup failed";
        return status;
    }


    return Status::OK;


}
Status Application::exec() {


    while(!mData->MExited) {
        
        auto clientFD = mData->MListener->listen();

        if (!clientFD)
            continue;

        auto ioSocket  = std::make_shared<IOSocket>(*clientFD, mData->MHttpService);
        auto status = mData->MEpolls->add(*clientFD, EPOLLIN, ioSocket);
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
