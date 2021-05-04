#include "consoleScreen.h"

namespace Screen {
    std::string operation[4] = {"2J", "5m", "0m", "2J"};

    std::ostream &operator<<(std::ostream &os, Type type) {
        if (type == Sleep5sec) {
#ifdef WINDOW
            Sleep(5000);
#endif
#ifndef WINDOW
            std::this_thread::sleep_for(std::chrono::seconds(5));
#endif
            return os;
        }
        if (type == Sleep1Sec) {
#ifdef WINDOW
            Sleep(1000);
#endif
#ifndef WINDOW
            std::this_thread::sleep_for(std::chrono::seconds(1));
#endif
            return os;
        }
        if (type == Clear){
#ifdef WINDOW
            Sleep(1000);
#endif
#ifndef WINDOW
            std::this_thread::sleep_for(std::chrono::seconds(1));
#endif
        }
        return os << "\033[" << operation[type];
    }
};
