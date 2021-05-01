//
// Created by vincent97198 on 2021/4/30.
//

#ifndef NEW_CONSOLECOLOR_H
#define NEW_CONSOLECOLOR_H
#include <ostream>

namespace Color {
    enum frontColor {
        Default = 0,
        Black = 30,
        RED = 31,
        Green = 32,
        Yellow = 33,
        Blue = 34,
        Magenta = 35,
        Cyan = 36,
        White = 37
    };

    std::ostream &operator<<(std::ostream &os,frontColor color){
        return os << "\033[" << static_cast<int>(color) << "m";
    }
}
#endif //NEW_CONSOLECOLOR_H
