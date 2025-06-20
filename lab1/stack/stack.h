#pragma once
#include <stdexcept>

template<typename T>
class STACK {
private:
    T* arr;
    int top;
    int capacity;

public:
    
    STACK(int size) : capacity(size), top(-1) {
        arr = new T[capacity];
    }

    ~STACK() {
        delete[] arr;
    }

    void push(T x){
        if (isFull()) {
        throw std::overflow_error("Stack overflow");
        }
        arr[++top] = x;
    }

    T pop(){
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        return arr[top--];        
    }

    T peek() const{
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[top];
    }

    bool isEmpty() const{
        return top == -1;
    }

    bool isFull() const{
        return top == capacity - 1;
    }

};