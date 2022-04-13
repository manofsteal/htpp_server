#include "Executor.h"

#include <thread>
#include <atomic>
#include <mutex>
#include <queue>
#include <condition_variable>

struct Executor::Data {
    std::unique_ptr<std::thread> MThread;
    std::atomic<bool>       MStopped;
    std::mutex              MMutex;
    std::queue<std::shared_ptr<Task>> MTasks;
    std::condition_variable MCV;
};

Executor::Executor() : mData(std::make_unique<Data>()) {

}

Executor::~Executor() {
    this->stop();
}

Status Executor::start() {
    mData->MThread = std::make_unique<std::thread>([&]() {
        while(mData->MStopped) {
            
            std::shared_ptr<Task> task;
            {
                auto lock = std::unique_lock(mData->MMutex);
                mData->MCV.wait(lock, [&]() {
                    return !mData->MTasks.empty();
                });

                task = mData->MTasks.front();
                mData->MTasks.pop();
            }

            if (task) (*task)();

        }
    });

    if (!mData->MThread)
        return Status::N_OK;
    return Status::OK;
}

Status Executor::exec(std::shared_ptr<Task> t) {
    auto lock = std::unique_lock(mData->MMutex);
    mData->MTasks.push(t);
    mData->MCV.notify_one();
}

Status Executor::stop() {
    mData->MStopped = true;
    mData->MThread->join();
}

// future support
std::shared_ptr<Task>Executor::steal() {
    //TODO
    return nullptr;
}


