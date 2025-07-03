#include <iostream>
#include <stdexcept>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void appendEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void appendFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void append_at(T value, int index) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }

        Node<T>* newNode = new Node<T>(value);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
            if (size == 0) {
                tail = newNode;
            }
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            if (newNode->next == nullptr) {
                tail = newNode;
            }
        }
        size++;
    }

    void removeEnd(){
        Node<T>* temp = tail;
        if (!head) {
            std::cout << "List is empty\n";
            return;
        }
        if (head->next == nullptr) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node<T>* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            current->next = nullptr;
            tail = current;
        }
        delete temp;
        size--;
    }

    void removeFront(){
        if (!head) {
            std::cout << "List is empty\n";
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void remove_at(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* temp;
        if (index == 0) {
            temp = head;
            head = head->next;
            if (!head) {
                tail = nullptr;
            }
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            temp = current->next;
            current->next = temp->next;
            if (temp == tail) {
                tail = current;
            }
        }
        delete temp;
        size--;
    }

    void display_list(char sep = ' ') const {
        Node<T>* current = head;
        if (!current) {
            std::cout << "List is empty\n";
            return;
        }
        while (current) {
            std::cout << current->data;
            if (current->next) {
                std::cout << sep;
            }
            current = current->next;
        }
        std::cout << "\n";
    }

    int getSize() const {
        return size;
    }

};
