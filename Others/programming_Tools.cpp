#include "programming_Tools.h"

namespace Tools {
    mt19937_64 RANDOM(time(NULL));

    void stringToUpper(string &str) {
        transform(str.begin(), str.end(), str.begin(),
                  [](unsigned char c) { return toupper(c); });
    }

    bool check_input_logic_oneAlphabet(string &input, map<char, string> &Map) {
        try {
            string Warning;
            if (input.empty())
                throw (Warning = "You didn't enter anything!");
            else if (input.size() > 1)
                throw (Warning = "Please input exactly \"one\" alphabet");
            else if (Map.find(input[0]) == Map.end())
                throw (Warning = "You CANNOT do this action");
            else
                return true;
        }
        catch (string Warning) {
            cout << Color::RED << Warning << '\n' << Color::Default;
            return false;
        }
    }

    bool check_input_logic_multi_int(string &input, map<int, string> &Map) {
        try {
            string Warning;
            if (input.empty()) throw (Warning = "You didn't enter anything!");
            else {
                for (char ch:input)
                    if (!(ch <= '9' && ch >= '0') && ch!=' ') throw (Warning = "Wrong input");

                stringstream ss;
                ss << input;
                int integer;
                set<int> haveChosen;
                while (ss >> integer) {
                    if (haveChosen.find(integer) != haveChosen.end())
                        throw (Warning = "You type the same item more than one time");
                    haveChosen.insert(integer);
                }
                if (*haveChosen.begin() < 0 || *prev(haveChosen.end()) >= Map.size())
                    throw (Warning = "Invalid number of Item");
            }
            return true;
        }
        catch (string Warning) {
            cout << Color::RED << Warning << Color::Default << '\n';
            return false;
        }
    }

    int gainRandomNumber(const int RangeL, const int RangeR) {   // left closed, right open
        return ((int) Tools::RANDOM() % (RangeR - RangeL)) + RangeL;
    }

    int CeilDiv(int A, int B) {
        return (A / B) + 1 - (A % B);
    }
}