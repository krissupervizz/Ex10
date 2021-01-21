// Copyright 2021 Krissupervizz
#include "postfix.h"
#include "MyStack.h"

int prioritet(char s) {
    if (((s >= '0') && (s <= '9')) || (s == '.')) return 5; //peremennaya
    else if ((s == '/') || (s == '*')) return 3; //if / or *
    else if ((s == '+') || (s == '-')) return 2; //if + or -
    else if (s == '(') return 0; //if (
    else if (s == ')') return 1; //if )
    else return 10;
}

std::string infix2prefix(std::string infix) {
    MyStack<char> operand(infix.size());
    std::string prefix = "";
    for (char i : infix) {
        if (prioritet(i) == 5) {
            prefix = prefix + i;
        } else if ((i == '(') || ((prioritet(i) != 10) && (operand.isEmpty()))) {
            operand.push(i);
        } else if (i == ')') {
            while ((operand.get() != '(') && (!operand.isEmpty())) {
                prefix = prefix + operand.pop();
            }
            operand.pop();
        } else if (prioritet(i) == 10) {
            i = i;
        } else {
            if (prioritet(operand.get()) < prioritet(i)) {
                operand.push(i);
            } else {
                while ((prioritet(operand.get()) >= prioritet(i)) && (!operand.isEmpty())) {
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