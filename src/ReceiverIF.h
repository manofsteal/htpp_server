#ifndef RECEIVER_IF_H
#define RECEIVER_IF_H

#include <vector>

class ReceiverIF {
public:
    virtual ~ReceiverIF() = default;
    virtual void recv(const std::vector<uint8_t>& buffer) = 0;
};
#endif 