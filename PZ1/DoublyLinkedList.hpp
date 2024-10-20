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
    /**
     * @brief Dodanie elementu na pocz�tek listy.
     *
     * @param value Warto�� elementu do dodania na pocz�tek listy.
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
     * @param value Warto�� elementu do dodania na koniec listy.
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
     * @param index Indeks, pod kt�ry ma zosta� dodany element.
     * @param value Warto�� elementu do dodania.
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
