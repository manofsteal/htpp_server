#ifndef EXECUTOR_IF_H_
#define EXECUTOR_IF_H_

#include "Task.h"
#include <memory>


class ExecutorIF {
public:
    virtual ~ExecutorIF() = default;
    virtual Status start() = 0;
    virtual Status exec(std::shared_ptr<Task>) = 0;
    virtual std::shared_ptr<Task> steal() = 0; // job stealing
    virtual Status stop() = 0;
};

#endif 