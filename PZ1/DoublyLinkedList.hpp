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
    /**
     * @brief Dodanie elementu na pocz¹tek listy.
     *
     * @param value Wartoœæ elementu do dodania na pocz¹tek listy.
     */
    void addToStart(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    /**
     * @brief Dodanie elementu na koniec listy.
     *
     * @param value Wartoœæ elementu do dodania na koniec listy.
     */
    void addToEnd(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    /**
     * @brief Dodanie elementu pod wskazany indeks.
     *
     * @param index Indeks, pod który ma zostaæ dodany element.
     * @param value Wartoœæ elementu do dodania.
     */
    void addAtIndex(int index, int value) {
        if (index <= 0) {
            addToStart(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        int currentIndex = 0;

        while (temp && currentIndex < index) {
            temp = temp->next;
            currentIndex++;
        }

        if (!temp) {
            addToEnd(value);
        }
        else {
            newNode->next = temp;
            newNode->prev = temp->prev;
            if (temp->prev) {
                temp->prev->next = newNode;
            }
            temp->prev = newNode;
        }
    }
};
