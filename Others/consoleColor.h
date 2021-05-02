#ifndef NEW_CONSOLECOLOR_H
#define NEW_CONSOLECOLOR_H
#include <ostream>
#include <thread>
#include <chrono>

namespace Color {
    enum frontColor{
        Default = 0,
        Black = 30,
        RED = 31,
        Green = 32,
        Yellow = 33,
        Blue = 34,
        Purple = 35,
        Cyan = 36,
        White = 37
    };

    std::ostream &operator<<(std::ostream &os,frontColor color);
}
#endif //NEW_CONSOLECOLOR_H
