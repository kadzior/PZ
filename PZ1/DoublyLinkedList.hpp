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
    /**
     * @brief Usu� element z pocz�tku listy.
     */
    void removeFromStart() {
        if (!head) return;

        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }
    /**
     * @brief Usu� element z ko�ca listy.
     */
    void removeFromEnd() {
        if (!tail) return;

        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete temp;
    }
    /**
     * @brief Usu� element pod wskazanym indeksem.
     *
     * @param index Indeks elementu do usuni�cia.
     */
    void deleteAtIndex(int index) {
        if (index < 0 || !head) return;

        if (index == 0) {
            removeFromStart();
            return;
        }

        Node* temp = head;
        int currentIndex = 0;

        while (temp && currentIndex < index) {
            temp = temp->next;
            currentIndex++;
        }

        if (!temp) return;

        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;

        if (temp == tail) tail = temp->prev;

        delete temp;
    }
    /**
     * @brief Wy�wietl ca�� list� od pocz�tku do ko�ca.
     */
    void read() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    /**
     * @brief Wy�wietl list� w odwrotnej kolejno�ci.
     */
    void readReverse() const {
        Node* temp = tail;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

};
