#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


string infixToPrefix(string infix) {

    reverse(infix.begin(), infix.end());


    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    stack<char> s;
    string prefix;

    for (char c : infix) {
        if (isspace(c)) continue;

        if (isalnum(c)) {
            prefix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                prefix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // pop '('
        }
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) > precedence(c)) {
                prefix += s.top();
                s.pop();
            }
            if (c != '^') {
                while (!s.empty() && precedence(s.top()) == precedence(c)) {
                    prefix += s.top();
                    s.pop();
                }
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}