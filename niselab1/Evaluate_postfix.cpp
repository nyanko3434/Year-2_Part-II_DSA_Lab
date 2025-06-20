#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

int evaluatePostfix(const string& expr) {
    stack<int> s;

    for (char c : expr) {
        if (isspace(c)) continue;

        if (isdigit(c)) {
            s.push(c - '0'); 
        }
        else {
            int b = s.top();
            s.pop();
            int a = s.top(); 
            s.pop();

            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^': s.push(pow(a, b)); break;
                default:
                    cout << "Unsupported operator: " << c << endl;
                    return -1;
            }
        }
    }

    return s.top(); 
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}