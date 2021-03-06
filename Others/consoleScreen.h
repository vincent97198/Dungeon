#ifndef NEW_CONSOLESCREEN_H
#define NEW_CONSOLESCREEN_H

#include <ostream>
#include <string>
#include <thread>
#include "console.h"

#ifdef WINDOW
#include <windows.h>
#endif

namespace Screen {
    enum Type {
        Clear = 0,
        Shining = 1,
        Closed = 2,
        Clear_soon = 3,
        Sleep5sec = 4,
        Sleep1Sec=5
    };

    std::ostream &operator<<(std::ostream &, Type);
};


#endif //NEW_CONSOLESCREEN_H
