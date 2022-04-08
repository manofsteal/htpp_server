#include "Application.h"
#include "Listener.h"
#include "Poller.h"
#include "Service.h"
#include <atomic>
#include <memory>
#include "IOEpoll.h"
#include "EpollWorker.h"

struct Application::Data {

    std::shared_ptr<Listener>    MListener;
    std::shared_ptr<Poller>      MPoller;
    std::shared_ptr<Service>     MService;

    std::shared_ptr<EpollWorker> MEpollWorker;
    std::shared_ptr<IOEpoll>     MIOEpoll;

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

    static constexpr int timeout = -1;
    static const std::string host = "0.0.0.0";
    static constexpr  std::uint16_t port = 8080;


    mData->MListener = std::make_shared<Listener>(host, port);
    mData->MIOEpoll   = std::make_shared<IOEpoll>(timeout);
    mData->MEpollWorker = std::make_shared<EpollWorker>(mData->MIOEpoll);


    auto status = mData->MListener->setup();
    if (status != Status::OK) {
        LOG() << "Listener setup failed";
        return status;
    }

    LOG() << "Server is listening at " << host << ":" << port << std::endl;

    //TODO: error handling
    status = mData->MIOEpoll->setup();
    if (status != Status::OK) {
        LOG() << "IOEpoll setup failed";
        return status;
    }

     //TODO: error handling

    return Status::OK;

}
Status Application::exec() {

    auto status = mData->MEpollWorker->start();

    if (status != Status::OK) {
        LOG() << "EpollWorker start failed" << std::endl;
        return status; 
    }

    //  LOG() << "EpollWorker start successfully" << std::endl;

    while(!mData->MExited) {
        
        auto clientFD = mData->MListener->listen();

        if (!clientFD)
            continue;

        //NOTE: ok
        // LOG() << "new client: " << *clientFD << ENDL;

        //NOTE: testing
        status = mData->MIOEpoll->add(*clientFD, EPOLLIN, [&](const epoll_event&, IOEpoll*) {
            LOG() << "new client" << std::endl;
        });
        // auto response = mData->mService.handle(event);

    }

    return Status::OK;
}
    
Status Application::clean() {
    //TODO: clean memory, other resource

    return Status::OK;
}
