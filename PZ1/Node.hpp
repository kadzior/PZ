/**
    * @struct Node
    * @brief Struktura reprezentuj¹ca wêze³ listy.
    *
    * Ka¿dy wêze³ przechowuje dane (data) oraz wskaŸniki na poprzedni (prev)
    * i nastêpny (next) element listy.
    */
struct Node {
    int data;
    Node* next;
    Node* prev;

    /**
     * @brief Konstruktor tworz¹cy nowy wêze³ z dan¹ wartoœci¹.
     * @param value Wartoœæ do przechowania w wêŸle.
     */
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};