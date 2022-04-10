
#ifndef HTPP_SERVER_LINUX_H_
#define HTPP_SERVER_LINUX_H_
#include <stdint.h>


#include <unistd.h>
#include <cerrno>

namespace os {
    using FileDesc = int;
    static inline int SystemError() {
        return errno;
    }
}

#endif