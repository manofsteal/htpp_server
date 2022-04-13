#ifndef SENDER_IF_H
#define SENDER_IF_H

#include <vector>
#include "Utils.h"

class SenderIF {
public:
    virtual ~SenderIF() = default;
    virtual Status send(const std::vector<uint8_t>& buffer ) = 0;
};
#endif 