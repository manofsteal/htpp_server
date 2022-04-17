
#include "Signals.h"

Signals& Signals::singleton() {
    static Signals instance;
    return instance;
}

void Signals::install(int sig, Handler handler) {
    mHandlers[sig] = handler;
    std::signal(sig, &Signals::handle);
}

void Signals::uninstall(int sig) {
    auto it = mHandlers.find(sig);
    mHandlers.erase(it);
}

void Signals::handle(int sig) {

    // LOG() << "OS Signal: " <<  sig << ENDL;

    auto& handlers = Signals::singleton().mHandlers;

    auto it = handlers.find(sig);

    if (it == handlers.end()) {
        LOG() << "OS Signal: " <<  sig << ", not found handler" << ENDL;
    } else {
   
        Handler& handler = it->second;
        handler();
    }
   
}