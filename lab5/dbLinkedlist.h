#include<iostream>
#include <stdexcept>

template <typename T>
class dbNode {
public:
    T data;
    dbNode* next;
    dbNode* prev;
    
    dbNode(T value) : data(value), next(nullptr), prev(nullptr) {}
    dbNode(T value, dbNode* nextNode, dbNode* prevNode) 
        : data(value), next(nextNode), prev(prevNode) {}

};

template <typename T>
class dbLinkedList {
private:
    dbNode<T>* head;
    dbNode<T>* tail;
    int size;
public:
    dbLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~dbLinkedList(){
        while (head) {
            dbNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtHead(T value){
        dbNode<T>* newNode = new dbNode<T>(value);
        if (!head) {

            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    void insertAtTail(T value){
        dbNode<T>* newNode = new dbNode<T>(value);
        if (!tail) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void insertAfter(dbNode<T>* node, T value) {
        if (!node) throw std::invalid_argument("Node cannot be null");
        dbNode<T>* newNode = new dbNode<T>(value);
        newNode->next = node->next;
        newNode->prev = node;
        if (node->next) {
            node->next->prev = newNode;
        } else {
            tail = newNode;
        }
        node->next = newNode;
        size++;
    }

    void insertBefore(dbNode<T>* node, T value) {
        if (!node) throw std::invalid_argument("Node cannot be null");
        dbNode<T>* newNode = new dbNode<T>(value);
        newNode->prev = node->prev;
        newNode->next = node;
        if (node->prev) {
            node->prev->next = newNode;
        } else {
            head = newNode;
        }
        node->prev = newNode;
        size++;
    }

    T removeNode(dbNode<T>* node) {
        if (!node) throw std::invalid_argument("Node cannot be null");
        T removedData = node->data;
        if (node == head) {
            head = head->next;
            if (head) head->prev = nullptr;
        } else {
            node->prev->next = node->next;
        }
        if (node == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
        } else {
            node->next->prev = node->prev;
        }
        delete node;
        size--;
        return removedData;
    }

    T removeHead() {
        if (!head) throw std::out_of_range("List is empty");
        T return_value = head->data;
        dbNode<T>* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr; 
        delete temp;
        size--;
        return return_value;
    }

    T removeTail() {
        if (!tail) throw std::out_of_range("List is empty");
        T return_value = tail->data;
        dbNode<T>* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        size--;
        return return_value;
    }

    void display() const {
        dbNode<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }


    dbNode<T>* getHead() const { return head; }
    dbNode<T>* getTail() const { return tail; }
    int getSize() const { return size; }
};