#include<iostream>
#include "linkedlist.h"

int main() {
    LinkedList<int> list;

    list.appendEnd(1);
    list.appendEnd(2);
    list.appendEnd(3);
    list.display_list();
    list.appendFront(0);
    list.append_at(1, 3);
    list.display_list();

    list.remove_at(3);
    list.display_list();

    return 0;
}
