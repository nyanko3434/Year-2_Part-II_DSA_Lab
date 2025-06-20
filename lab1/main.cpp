#include "stack/stack.h"
#include<iostream>

int main() {
    // Example usage of the STACK class
    STACK<int> intStack(5);
    
    try {
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        
        while (!intStack.isEmpty()) {
            std::cout << "Popped: " << intStack.pop() << std::endl;
        }
        

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    

    return 0;
}