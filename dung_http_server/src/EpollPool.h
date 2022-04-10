#ifndef EPOLL_POOL_H_
#define EPOLL_POOL_H_

#include <Utils.h>
#include <vector>
#include <memory>
#include <Linux.h>


class EpollWorker;
class IOEpoll;
class EpollHandlerIF;

class EpollPool {
public:
    EpollPool(size_t workers, int timeout);

    Status setup();
    Status start();
    Status add(os::FileDesc fd, uint32_t events, std::shared_ptr<EpollHandlerIF> handler);

private:
    std::vector<std::shared_ptr< EpollWorker>> mWorkers;
    std::vector<std::shared_ptr< IOEpoll>> mEpolls;
    size_t mCurEpoolWorker{0};
};

#endif
