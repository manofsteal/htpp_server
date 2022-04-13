#ifndef EPOLL_POOL_H_
#define EPOLL_POOL_H_

#include "Utils.h"
#include <vector>
#include <memory>
#include "Linux.h"
#include "ReceiverIF.h"
#include "IOWriterIF.h"


class EpollWorker;
class IOEpoll;


class EpollPool: public IOWriterIF {
public:
    EpollPool(size_t workers, int timeout);
    virtual ~EpollPool();

    Status write(os::FileDesc fd, const std::vector<uint8_t>& buffer) override;
    
    Status setup();
    Status start();
    Status add(os::FileDesc fd, uint32_t events, std::shared_ptr<ReceiverIF> handler);

private:
    std::vector<std::shared_ptr< EpollWorker>> mWorkers;
    std::vector<std::shared_ptr< IOEpoll>> mEpolls;
    size_t mCurEpoolWorker{0};

};

#endif
