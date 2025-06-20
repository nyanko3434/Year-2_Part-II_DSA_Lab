#include "infix_to_postfix.h"
#include <cctype>

bool InfixToPostfixConverter::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' , c == '%';
}

bool InfixToPostfixConverter::isLeftParenthesis(char c) const {
    return c == '(';
}

bool InfixToPostfixConverter::isRightParenthesis(char c) const {
    return c == ')';
}


int InfixToPostfixConverter::precedence(char op) const {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

