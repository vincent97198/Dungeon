#include "Ask.h"

namespace Ask {
    char Ask_oneAlphabet(string output, map<char, string> &MAP) {
        cout << endl;
        cout << Color::Blue << output << Color::Default << '\n';
        for (auto &iter:MAP)
            cout << '(' << iter.first << ')' << '\t' << iter.second << '\n';
        string input;
        do {
            getline(cin, input);
            Tools::stringToUpper(input);
        } while (!Tools::check_input_logic_oneAlphabet(input, MAP));
        return input[0];
    }

    char Ask_oneAlphabet_Object(string output, map<char, Object *> &MAP) {
        cout << endl;
        cout << Color::Blue << output << Color::Default << '\n';
        for (auto &iter:MAP)
            cout << '(' << iter.first << ')' << '\t' << iter.second->getName() << '\n';

        string input;
        do {
            getline(cin, input);
            Tools::stringToUpper(input);
        } while (!Tools::check_input_logic_oneAlphabet_Object(input, MAP));
        return input[0];
    }

    void Ask_multi_int(string output, map<int, Object *> &MAP, vector<int> &outputType) {
        cout << endl;
        cout << Color::Blue << output << Color::Default << '\n';
        cout << Color::Purple << "輸入括號裡的編號，可以一次輸入多個整數，多個整數請以空格隔開\n" << Color::Default;

        for (auto &iter:MAP)
            cout << '(' << iter.first << ')' << '\t' << iter.second->getName() << '\n';

        cout << "(Q) Quit\n";

        string input;
        do {
            getline(cin, input);
            if(input=="Q" || input=="q")    return;
        } while (!Tools::check_input_logic_multi_int(input, MAP));

        stringstream ss;
        ss << input;
        int item_number;
        while (ss >> item_number) {
            outputType.emplace_back(item_number);
        }
        sort(outputType.begin(), outputType.end());
    }
}