#ifndef IO_WRITER_IF_H
#define IO_WRITER_IF_H

#include <vector>
#include "Utils.h"

class IOWriterIF {

public:
    virtual ~IOWriterIF() = default;
    virtual Status write(os::FileDesc fd, const std::vector<uint8_t>& buffer) = 0;
};
#endif 