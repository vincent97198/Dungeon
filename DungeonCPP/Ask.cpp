#include "Dungeon.h"

char Dungeon::Ask_oneAlphabet(string output, map<char, string> &MAP) {
    cout << output << '\n';
    for (auto &iter:MAP)
        cout << '(' << iter.first << ')' << '\t' << iter.second << '\n';
    string input;
    do {
        getline(cin, input);
        Tools::stringToUpper(input);
    } while (!Tools::check_input_logic_oneAlphabet(input, MAP));
    return input[0];
}

void Dungeon::Ask_multi_int(string output, map<int, string> &MAP, vector<int> &outputType) {
    cout << output << '\n';
    cout << Color::Magenta << "輸入括號裡的武器編號，可以一次輸入多個整數，多個整數請以空格隔開\n" << Color::Default;

    for (auto &iter:MAP)
        cout << '(' << iter.first << ')' << '\t' << iter.second << '\n';

    string input;
    do {
        getline(cin, input);
    } while (!Tools::check_input_logic_multi_int(input, MAP));

    stringstream ss;
    ss << input;
    int item_number;
    while (ss >> item_number) {
        outputType.emplace_back(item_number);
    }
}