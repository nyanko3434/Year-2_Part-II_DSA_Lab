#include <iostream>
#include <stdexcept>

template <typename T>
class Linear_Queue {
private:
    T* data;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Linear_Queue(int cap) : capacity(cap), front(0), rear(-1), size(0) {
        if (cap <= 0) {
            throw std::invalid_argument("Capacity must be positive.");
        }
        data = new T[capacity];
    }

    ~Linear_Queue() {
        delete[] data;
    }

    void enqueue(const T& value) {
        if (size == capacity) {
            throw std::overflow_error("Queue is full.");
        }
        rear = (rear + 1);
        data[rear] = value;
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty.");
        }
        T value = data[front];
        front = (front + 1);
        size--;
        return value;
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }
};

template <typename T>
class Circular_Queue {
private:
    T* data;
    int front;
    int rear;
    int capacity;


public:
    Circular_Queue(int cap) : capacity(cap), front(-1), rear(-1) {
        if (cap <= 0) {
            throw std::invalid_argument("Capacity must be positive.");
        }
        data = new T[capacity];
    }

    ~Circular_Queue() {
        delete[] data;
    }

    void enqueue(const T& value) {
        if ((rear + 1) % capacity == front) {
            throw std::overflow_error("Queue is full.");
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        data[rear] = value;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty.");
        }
        T value = data[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return value;
    }

    bool isEmpty() const {
        return front == -1;
    }

    int getSize() const {
        if (isEmpty()) return 0;
        return (rear - front + capacity) % capacity + 1;
    }
};

template <typename T>
class Double_Ended_Queue{
private:
    T* data;
    int front;
    int rear;
    int capacity;

public:
    Double_Ended_Queue(int cap) : capacity(cap), front(-1), rear(-1) {
        if (cap <= 0) {
            throw std::invalid_argument("Capacity must be positive.");
        }
        data = new T[capacity];
    }

    ~Double_Ended_Queue() {
        delete[] data;
    }

    void enqueueFront(const T& value) {
        if ((front == 0 && rear == capacity - 1) || (rear + 1 == front)) {
            throw std::overflow_error("Queue is full.");
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }
        data[front] = value;
    }

    T dequeueRear() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty.");
        }
        T value = data[rear];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear--;
        }
        return value;
    }
    void enqueueRear(const T& value) {
        if ((rear + 1) % capacity == front) {
            throw std::overflow_error("Queue is full.");
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        data[rear] = value;
    }

    T dequeueFront() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty.");
        }
        T value = data[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return value;
    }

    bool isEmpty() const {
        return front == -1;
    }

    int getSize() const {
        if (isEmpty()) return 0;
        return (rear - front + capacity) % capacity + 1;
    }

};