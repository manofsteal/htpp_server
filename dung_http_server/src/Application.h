#ifndef EVENT_H
#define EVENT_H

#include <optional>
#include <memory>
#include <Utils.h>

class Application final {
public:
    ~Application();
    Application();

    Status setup();
    Status exec();
    Status clean();

private:

    struct Data;
    std::unique_ptr<Data> mData;
    
};

#endif