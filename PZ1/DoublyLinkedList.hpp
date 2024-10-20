/**
 * @file doubly_linked_list.cpp
 * @brief Implementacja dwukierunkowej listy wi�zanej w C++.
 *
 * Ta klasa reprezentuje dwukierunkow� list� wi�zan� i implementuje podstawowe operacje
 * takie jak dodanie elementu na pocz�tek, koniec, do okre�lonego indeksu oraz inne.
 */
#include <iostream>
#include "Node.hpp"
using namespace std;

/**
 * @class DoublyLinkedList
 * @brief Klasa reprezentuj�ca dwukierunkow� list� wi�zan�.
 *
 * Ta klasa przechowuje w�z�y listy, umo�liwia dodawanie, usuwanie element�w,
 * oraz operacje takie jak wy�wietlanie listy.
 */
class DoublyLinkedList {
private:

    Node* head;
    Node* tail;
    Node* current; // wska�nik do poruszania si� po li�cie

public:
    /**
     * @brief Konstruktor domy�lny, inicjuje pust� list�.
     */
    DoublyLinkedList() : head(nullptr), tail(nullptr), current(nullptr) {}
    /**
     * @brief Destruktor, kt�ry zwalnia zasoby klasy z pami�ci
     */
    ~DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        current = nullptr; 
    }
};