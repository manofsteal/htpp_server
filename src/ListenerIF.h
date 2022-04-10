#ifndef IOSocketSrv_IF_H
#define IOSocketSrv_IF_H

#include <optional>

#include "Linux.h"
#include "Utils.h"

class ListenerIF {
public:
    virtual ~ListenerIF() = default;

    virtual Status setup() = 0;
    virtual std::optional<os::FileDesc> listen() = 0;
};

#endif 
