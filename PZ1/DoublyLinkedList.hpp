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
    /**
     * @brief Usuñ element z pocz¹tku listy.
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
     * @brief Usuñ element z koñca listy.
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
     * @brief Usuñ element pod wskazanym indeksem.
     *
     * @param index Indeks elementu do usuniêcia.
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
     * @brief Wyœwietl ca³¹ listê od pocz¹tku do koñca.
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
     * @brief Wyœwietl listê w odwrotnej kolejnoœci.
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
