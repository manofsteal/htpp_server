
#include "ExecutorPool.h"
#include "Executor.h"

ExecutorPool::ExecutorPool(size_t executors) {
    for (int i = 0; i < executors; ++i) {
        mExecutors.push_back(std::make_shared<Executor>());
    }
}
ExecutorPool::~ExecutorPool() {
    this->stop();
}

Status ExecutorPool::start() {

    Status status;
    for (auto& exc: mExecutors) {
        status = exc->start();
        if (status != Status::OK) {
            return status;
        }
    }

    return Status::OK;

}
Status ExecutorPool::exec(std::shared_ptr<Task> t) {
    auto status = mExecutors[mCurExc]->exec(t);
    mCurExc = (mCurExc + 1) % mExecutors.size();
    return status;
}

std::shared_ptr<Task> ExecutorPool::steal() {
    return nullptr;
}

Status ExecutorPool::stop() {

    Status status;
    for (auto& exc: mExecutors) {
        status = exc->stop();
        if (status != Status::OK) {
            return status;
        }
    }

    return Status::OK;
}