#include <iostream>
#include <stdexcept>

class STACK {
private:
    int* arr;
    int top;
    int capacity;   
public: 
    STACK(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~STACK() {
        delete[] arr;
    }

    void push(int x) {
        if (top == capacity - 1) {
            throw std::overflow_error("Stack overflow");
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            throw std::underflow_error("Stack underflow");
        }
        return arr[top--];
    }

    int peek() const {
        if (top == -1) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[top];
    }

    bool isEmpty() const {
        return top == -1;
    }
};

int main() {
    STACK stack(5);

    try {
        stack.push(10);
        stack.push(20);
        stack.push(30);
        std::cout << "Top element is: " << stack.peek() << std::endl;

        std::cout << "Popped element is: " << stack.pop() << std::endl;
        std::cout << "Top element after pop is: " << stack.peek() << std::endl;

        while (!stack.isEmpty()) {
            std::cout << "Popping: " << stack.pop() << std::endl;
        }

        std::cout << "Popping from empty stack: " << stack.pop() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}