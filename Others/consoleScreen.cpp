#include "consoleScreen.h"

namespace Screen {
    std::string operation[4] = {"2J", "5m", "0m", "2J"};

    std::ostream &operator<<(std::ostream &os, Type type) {
#ifdef WINDOW
        if (type == Sleep5sec) {
            Sleep(5000);
            return os;
        } else if (type == Sleep1Sec) {
            Sleep(1000);
            return os;
        }
#endif
#ifndef WINDOW
        if (type == Sleep5sec) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            return os;
        }
        if (type == Sleep1Sec) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return os;
        }
        if (type == Clear){
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        return os << "\033[" << operation[type];
#endif
    }
};
