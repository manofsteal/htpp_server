#include <Application.h>

int main(int argc, char** argv) {
    
    Application app;
    
    auto err = app.setup();
    if (err) {
        return *err;
    }

    err = app.exec();

    if (err) {
        return *err;
    }

    return 0;
}