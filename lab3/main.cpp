#include "Queue.h"
#include <iostream>

int main() {

    Linear_Queue<int> linearQueue(5);
    linearQueue.enqueue(1);
    linearQueue.enqueue(2);
    std::cout << "Liner_Queue Dequeue: " << linearQueue.dequeue() << std::endl;


    Circular_Queue<int> circularQueue(5);
    circularQueue.enqueue(1);
    circularQueue.enqueue(2);
    circularQueue.enqueue(3);
    circularQueue.enqueue(4);
    circularQueue.enqueue(5);
    std::cout << "Circular_Queue Dequeue: " << circularQueue.dequeue() << std::endl;
    circularQueue.enqueue(6); 
    while (circularQueue.getSize() > 0) 
    {
        std::cout << "Circular_Queue Dequeue: " << circularQueue.dequeue() << std::endl;
    }
    

    Double_Ended_Queue<int> deque(5);
    deque.enqueueRear(1);
    deque.enqueueRear(2);
    deque.enqueueFront(3);
    std::cout << "Double_Ended_Queue Dequeue Rear: " << deque.dequeueRear() << std::endl;
    std::cout << "Double_Ended_Queue Dequeue Front: " << deque.dequeueFront() << std::endl;

    return 0;
}