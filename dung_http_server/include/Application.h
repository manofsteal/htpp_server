#ifndef EVENT_H
#define EVENT_H

#include <optional>

class Application final {
public:
    
    std::optional<int> setup();
    std::optional<int> exec();
    
};

#endif