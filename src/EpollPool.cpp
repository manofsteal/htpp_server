#include "EpollPool.h"
#include "EpollWorker.h"
#include "IOEpoll.h"


EpollPool::EpollPool(size_t workers, int timeout) {
    for(int i = 0; i < workers; ++i) {
        auto epoll  = std::make_shared<IOEpoll>(timeout);
        auto worker = std::make_shared<EpollWorker>(epoll);

        mEpolls.push_back(epoll);
        mWorkers.push_back(worker);
        
    }
}
Status EpollPool::setup() {
    Status status;
    for(auto& epoll: mEpolls) {
        status = epoll->setup();
        if (status != Status::OK)
            return status;
    }

    for(auto& worker: mWorkers) {
        status = worker->start();
        if (status != Status::OK)
            return status;
    }

    return Status::OK;
    
}


Status EpollPool::add(os::FileDesc fd, uint32_t events, std::shared_ptr<ReceiverIF> handler) {

    if (mWorkers.size() == 0) {
        LOG() << "There is no Epoll worker" << ENDL;
        return Status::N_OK;
    }

    auto nextEpollWorker = [&] () {
        // round-robin algorithm;
        auto next = (mCurEpoolWorker + 1) % mEpolls.size();

        return next;
    };

    auto status = mEpolls[mCurEpoolWorker]->add(fd, events, handler);

    mCurEpoolWorker = nextEpollWorker();

    return status;

}


Status EpollPool::write(os::FileDesc fd, const std::vector<uint8_t>& buffer) {
    for (auto& epoll: mEpolls) {
        auto status = epoll->write(fd, buffer);
        if (status == Status::OK) 
            return status;
    }

    return Status::N_OK;
}


EpollPool::~EpollPool() {

}