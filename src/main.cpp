// Copyright 2021 Krissupervizz
#include "postfix.h"
#include "MyStack.h"

int main() {
    std::string s1("2 + 6 * 3 / (4 - 2)");
    std::string s2 = infix2prefix(s1);
    std::cout << s2;  // 2 6 3 * 4 2 - / +

    std::string w1("(1 + 2) / (3 + 4 * 6.7) - 5.3 * 4.4");
    std::string w2 = infix2prefix(w1);
    std::cout << w2;  // 1 2 + 3 4 6.7 * + / 5.3 4.4 * -
    return 0;
}