
#ifndef EPOLL_WORKER_H_
#define EPOLL_WORKER_H_

#include <thread>
#include <optional>
#include <atomic>
#include <memory>
#include <Utils.h>
#include "IOEpoll.h"


class EpollWorker {
public:
    EpollWorker(std::shared_ptr<IOEpoll> epoll);
    ~EpollWorker();

    Status start();
    Status stop();
private:
    std::atomic<bool> mStopped;
    std::unique_ptr<std::thread> mThread;
    std::shared_ptr<IOEpoll> mEpoll;
};

#endif
