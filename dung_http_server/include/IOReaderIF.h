#ifndef IOREADER_IF_H_
#define IOREADER_IF_H_

#include <Linux.h>
class IOReaderIF {
public:
    virtual ~IOReaderIF() = default;
    virtual std::optional<int> read(std::vector<uint8_t>& buffer) = 0;
};

#endif