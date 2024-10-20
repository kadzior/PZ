#include <iostream>
#include "DoublyLinkedList.hpp"


int main() {
        DoublyLinkedList list;

        list.addToStart(10);
        list.addToEnd(20);
        list.addAtIndex(1, 15);
        list.read();

        list.removeFromStart();
        list.read();

        list.removeFromEnd();
        list.read();

        list.addToEnd(30);
        list.addToEnd(40);
        list.deleteAtIndex(1);
        list.read();

        list.readReverse();

        list.printNextElement();
        list.printNextElement();

        list.printPrevElement();
        list.printPrevElement();

        list.clearList();
        list.read();

        return 0;
}
