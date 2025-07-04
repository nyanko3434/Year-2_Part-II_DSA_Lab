#include<iostream>
#include "dbLinkedlist.h"

using namespace std;    

int main() {
    dbLinkedList<int> list;

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.display();

    cout << "Removed from head: " << list.removeHead() << endl;
    cout << "Removed from tail: " << list.removeTail() << endl;
    list.display();

    return 0;
}