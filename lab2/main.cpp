#include<iostream>
// #include<stack>

int non_tail_recursive_factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Negative input is not allowed.");
    }
    
    else if (n > 1){
        return n * non_tail_recursive_factorial(n - 1);
    }

    return 1;
}

int non_tail_recursive_fibonacci(int n) {
    if (n < 1) {
        throw std::invalid_argument("Non positive input is not allowed.");
    }
    
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    }else{
        return non_tail_recursive_fibonacci(n - 1) + non_tail_recursive_fibonacci(n - 2);
    }
}

int tail_recursive_factorial(int n, int accumulator = 1) {
    if (n < 0) {
        throw std::invalid_argument("Negative input is not allowed.");
    }
    
    if (n == 0 || n == 1) {
        return accumulator;
    }
    
    return tail_recursive_factorial(n - 1, n * accumulator);
}

int tail_recursive_fibonacci(int n, int a = 0, int b = 1) {
    if (n < 1) {
        throw std::invalid_argument("Non positive input is not allowed.");
    }
    
    if (n == 1) {
        return a;
    }
    
    return tail_recursive_fibonacci(n - 1, b, a + b);
}

// void tower_of_hanoi(int n, STACK<int>& source, STACK<int>& target, STACK<int>& auxiliary) {
//     if (n < 1) {
//         throw std::invalid_argument("Number of disks must be positive.");
//     }
    
//     std::cout << source.peek() << " -> " << target.peek() << std::endl;

//     if (n == 1) {
//         target.push(source.pop());
//         return;
//     }
    
//     tower_of_hanoi(n - 1, source, auxiliary, target);
//     target.push(source.pop());
//     tower_of_hanoi(n - 1, auxiliary, target, source);
// }

void tower_of_hanoi(int n, int source, int target, int auxiliary) {
    if (n < 1) {
        throw std::invalid_argument("Number of disks must be positive.");
    }
    
    if (n == 1) {
        std::cout << "Move disk 1 from rod " << source << " to rod " << target << std::endl;
        return;
    }
    
    tower_of_hanoi(n - 1, source, auxiliary, target);
    std::cout << "Move disk " << n << " from rod " << source << " to rod " << target << std::endl;
    tower_of_hanoi(n - 1, auxiliary, target, source);
}



int main() {
    try {
        int n = 5; 
        
        std::cout << "Non-tail recursive factorial of " << n << ": " << non_tail_recursive_factorial(n) << std::endl;
        std::cout << "Tail recursive factorial of " << n << ": " << tail_recursive_factorial(n) << std::endl;
        
        std::cout << "Non-tail recursive Fibonacci of " << n << ": " << non_tail_recursive_fibonacci(n) << std::endl;
        std::cout << "Tail recursive Fibonacci of " << n << ": " << tail_recursive_fibonacci(n) << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    int disks = 3; 
    std::cout << "Tower of Hanoi solution for " << disks << " disks:" << std::endl;
    tower_of_hanoi(disks, 1, 3, 2);


    
    return 0;
}