#ifndef EXECUTOR_POOL_H_
#define EXECUTOR_POOL_H_

#include "ExecutorIF.h"
#include <memory>
#include <vector>
#include <atomic>

class ExecutorPool: public ExecutorIF {
public:
    ExecutorPool(size_t executors);
    virtual ~ExecutorPool();
    Status start() override;
    Status exec(std::shared_ptr<Task>) override;
    std::shared_ptr<Task> steal() override;
    Status stop() override;
private:
    std::vector<std::shared_ptr<ExecutorIF>> mExecutors;
    std::atomic<size_t> mCurExc = 0;

};
#endif 