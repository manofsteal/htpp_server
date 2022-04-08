#include "EpollWorker.h"


EpollWorker::EpollWorker(std::shared_ptr<IOEpoll> epoll) 
    :mEpoll(epoll), mStopped(false)
{

}

EpollWorker::~EpollWorker() {
    this->stop();
}


Status EpollWorker::start() {

    mThread = std::make_unique<std::thread>([&]() {
        LOG() << "EpollWorker: thread started" << std::endl;
        while(!mStopped) {
            mEpoll->poll();
        }
    });

    if (!mThread)
        return Status::N_OK;

    return Status::OK;
   
}

Status EpollWorker::stop() {
    mStopped = true;
    mThread->join();
    return Status::OK;
}