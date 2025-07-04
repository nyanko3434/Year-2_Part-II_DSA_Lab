#include <iostream>
using namespace std;

class Stack {
    struct Node {
        int data;
        Node* next;
    };

    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int val) {
        Node* newNode = new Node{val, top};
        top = newNode;
    }

    void pop() {
        if (!top) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        Node* temp = top;
        cout << "Stack: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    return 0;
}