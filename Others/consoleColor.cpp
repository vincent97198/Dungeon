#include "consoleColor.h"
#include <ostream>

namespace Color {
    std::ostream &operator<<(std::ostream &os,frontColor color){
#ifdef WINDOW
        return os;
#endif
#ifndef WINDOW
        return os << "\033[" << static_cast<int>(color) << "m";
#endif
    }
}

