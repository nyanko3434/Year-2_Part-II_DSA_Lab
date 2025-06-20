#pragma once
#include "../stack/stack.h"
#include <string>

class InfixToPostfixConverter {
private:
    STACK<char> stack;
    std::string output;
    int precedence(char op) const;-io 
    bool isOperator(char c) const;
    bool isLeftParenthesis(char c) const;
    bool isRightParenthesis(char c) const;
    void processOperator(char op);
public:
    InfixToPostfixConverter(int size) : stack(size), output("") {}
    std::string convert(const std::string& infix);
    std::string getOutput() const { return output; }
    void clearOutput() { output.clear(); }      
};