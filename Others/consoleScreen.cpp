#include <thread>
#include "consoleScreen.h"

namespace Screen {
    std::string operation[3]={"2J","5m","0m"};
    std::ostream &operator<<(std::ostream &os,Type type){
        if(type==Clear)
            std::this_thread::sleep_for(std::chrono::seconds(1));
        return os << "\033[" << operation[type];
    }
};
