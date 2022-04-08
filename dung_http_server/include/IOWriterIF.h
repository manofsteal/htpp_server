#ifndef IOWRITER_IF_H_
#define IOWRITER_IF_H_

#include <Linux.h>

class IOWriterIF {
public:
    virtual ~IOWriterIF() = default;        
    virtual std::optional<int> write(const std::vector<uint8_t>& buffer) = 0;
};

#endif