/**
 * @file doubly_linked_list.cpp
 * @brief Implementacja dwukierunkowej listy wi¹zanej w C++.
 *
 * Ta klasa reprezentuje dwukierunkow¹ listê wi¹zan¹ i implementuje podstawowe operacje
 * takie jak dodanie elementu na pocz¹tek, koniec, do okreœlonego indeksu oraz inne.
 */
#include <iostream>
#include "Node.hpp"
using namespace std;

/**
 * @class DoublyLinkedList
 * @brief Klasa reprezentuj¹ca dwukierunkow¹ listê wi¹zan¹.
 *
 * Ta klasa przechowuje wêz³y listy, umo¿liwia dodawanie, usuwanie elementów,
 * oraz operacje takie jak wyœwietlanie listy.
 */
class DoublyLinkedList {
private:

    Node* head;
    Node* tail;
    Node* current; // wskaŸnik do poruszania siê po liœcie

public:
    /**
     * @brief Konstruktor domyœlny, inicjuje pust¹ listê.
     */
    DoublyLinkedList() : head(nullptr), tail(nullptr), current(nullptr) {}
    /**
     * @brief Destruktor, który zwalnia zasoby klasy z pamiêci
     */
    ~DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        current = nullptr; 
    }
};