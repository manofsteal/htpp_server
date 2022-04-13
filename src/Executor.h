#ifndef EXECUTOR_H_
#define EXECUTOR_H_

#include "ExecutorIF.h"
#include <functional>
#include <memory>

class Executor: public ExecutorIF {
public:
    Executor();
    virtual ~Executor();

    Status start() override;
    Status exec(std::shared_ptr<Task>) override;
    std::shared_ptr<Task> steal() override;
    Status stop() override;

private:
    struct Data;
    std::unique_ptr<Data> mData;
    
};

#endif 