#pragma once

template <class T>
struct Node {

    Node(T _value, Node* _prev, Node* _next)
    {
        value = _value;
        previous = _prev;
        next = _next;
    };

    T value;
    Node* next;
    Node* previous;

    ~Node()
    {
        next = previous = nullptr;
    }

};

//Lista enlzada
template <class T>
class List {

public:

    Node<T>* first;
    Node<T>* last;
    size_t size;

public:

    List();
    ~List();

    Node<T>* get_first() { return first; }
    Node<T>* get_last() { return last; }

    const Node<T>* get_last() const { return last; }
    size_t get_size() const { return size; }

    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void pop_back();

    /**
     Inserta un nuevo nodo a continuacion de n.
    */
    void insert(Node<T>* n, int value);
    void erase(Node<T>* n);

    /**
    Borra todos los nodos
    */
    void clear();

    /**Pinta la lista por pantalla
    */
    void print();

};

template<class T>
inline List<T>::List()
{
    size = 0;
    first = new Node<T>(NULL, nullptr, last);
    last = new Node<T>(NULL, first, nullptr);

}

template<class T>
inline List<T>::~List()
{
    if (size > 0) {

        Node<T>* ptr;

        while (first) {

            ptr = first->next;
            delete first;
            first = ptr;

        }

        size = 0;
        last = nullptr;
    }
}

template<class T>
inline void List<T>::push_front(int value)
{
    Node<T>* new2 = first;
    first = new Node<T>(value, nullptr, new2);
    first->next->previous = first;

    size++;
}

template<class T>
inline void List<T>::push_back(int value)
{
    Node<T>* newPen = last;

    //Nuevo ultimo Nodo
    last = new Node<T>(value, newPen, nullptr);

    //Asignamos el valor de siguiente al antepenultimo
    last->previous->next = last;

    size++;
}

template<class T>
inline void List<T>::pop_front()
{

    Node<T>* toDelete = first;

    //Nuevo ultimo Nodo
    first = toDelete->next;
    first->previous = nullptr;

    delete toDelete;

    size--;

}

template<class T>
inline void List<T>::pop_back()
{

    Node<T>* toDelete = last;

    //Nuevo ultimo Nodo
    last = toDelete->previous;
    last->next = nullptr;

    delete toDelete;

    size--;
}

template<class T>
inline void List<T>::insert(Node<T>* n, int _value)
{
    Node<T>* ptr = first;

    while (ptr != nullptr) {

        if (
            n->value == ptr->value
            && n->next == ptr->next
            && n->previous == ptr->previous
            )
        { //Insertamos el nodo en next

            Node<T>* aux = ptr->next;
            ptr->next = new Node<T>(_value, ptr, aux);
            ptr = nullptr;

        }
        else {
            ptr = ptr->next;
        }

    }

}

template<class T>
inline void List<T>::erase(Node<T>* n)
{

    Node<T>* ptr = first;

    while (ptr != nullptr) {

        if (
            n->value == ptr->value
            && n->next == ptr->next
            && n->previous == ptr->previous
            )
        { //Borramos el nodo de la lista el nodo en next

            Node<T>* aux_prev = ptr->previous;
            Node<T>* aux_next = ptr->next;

            if (aux_prev != nullptr)
                aux_prev->next = aux_next;

            if (aux_next != nullptr)
                aux_next->previous = aux_prev;

            delete ptr;
            ptr = nullptr;
            size--;

        }
        else {
            ptr = ptr->next;
        }

    }


}

template<class T>
inline void List<T>::print()
{

    if (size > 0) {
        Node<T>* ptr = first;

        while (ptr != nullptr) {
            std::cout << ptr->value;
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "No hay ningun valor en el array" << std::endl;
    }
}
