/**
    * @struct Node
    * @brief Struktura reprezentuj�ca w�ze� listy.
    *
    * Ka�dy w�ze� przechowuje dane (data) oraz wska�niki na poprzedni (prev)
    * i nast�pny (next) element listy.
    */
struct Node {
    int data;
    Node* next;
    Node* prev;

    /**
     * @brief Konstruktor tworz�cy nowy w�ze� z dan� warto�ci�.
     * @param value Warto�� do przechowania w w�le.
     */
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};