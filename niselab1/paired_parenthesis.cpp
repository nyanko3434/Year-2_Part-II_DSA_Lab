#include <iostream>
#include <stack>
using namespace std;

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}


bool areParenthesesBalanced(const string& expr) {
    stack<char> s;

    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty() || !isMatchingPair(s.top(), c)) {
                return false; 
            }
            s.pop();
        }
    }

    return s.empty(); 
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr); 

    if (areParenthesesBalanced(expr)) {
        cout << "Parentheses are balanced and properly paired.\n";
    } else {
        cout << "Parentheses are NOT balanced or properly paired.\n";
    }

    return 0;
}