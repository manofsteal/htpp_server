#ifndef SIGNALS_S_H_
#define SIGNALS_S_H_

#include <csignal>
#include <memory>
#include <map>
#include <functional>

#include "Utils.h"


class Signals {
public:
    using Handler = std::function<void()>;

    static Signals& singleton();

    void install(int sig, Handler handler);
    void uninstall(int sig);

private:
    Signals() = default;
    ~Signals() = default;

    static void handle(int sig);

    std::map<int, Handler> mHandlers;

};


#endif 