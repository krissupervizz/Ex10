// Copyright 2021 Krissupervizz
#include "postfix.h"
#include "MyStack.h"

int prior(char s) {
    if (((s >= '0') && (s <= '9')) || (s == '.')) return 5;
    else if ((s == '/') || (s == '*')) return 3;
    else if ((s == '+') || (s == '-')) return 2;
    else if (s == '(') return 0;
    else if (s == ')') return 1;
    else return 10;
}

std::string infix2prefix(std::string infix) {
    MyStack<char> operand(infix.size());
    std::string prefix = "";
    for (char i : infix) {
        if (prior(i) == 5) {
            prefix = prefix + i;
        } else if ((i == '(') || ((prior(i) != 10) && (operand.isEmpty()))) {
            operand.push(i);
        } else if (i == ')') {
            while ((operand.get() != '(') && (!operand.isEmpty())) {
                prefix = prefix + operand.pop();
            }
            operand.pop();
        } else if (prior(i) == 10) {
            i = i;
        } else {
            if (prior(operand.get()) < prior(i)) {
                operand.push(i);
            } else {
                while (prior(operand.get()) >= prior(i)) {
                    if (operand.isEmpty) break;
                    prefix = prefix + operand.pop();
                }
                operand.push(i);
            }
        }
    }
    while (!operand.isEmpty())
        prefix = prefix + operand.pop();
    return prefix;
}
