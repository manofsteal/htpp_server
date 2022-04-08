#include "Application.h"

#include <thread>

int main(int argc, char** argv) {
    
    Application app;
    
    auto status = app.setup();

    if (status != Status::OK) {
        return (int)status;
    }

    status = app.exec();

    return (int)status;
}