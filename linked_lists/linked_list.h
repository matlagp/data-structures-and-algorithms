#ifndef _LLIST_H
#define _LLIST_H 1

#include <iostream>
#include <stdexcept>

template<typename T>
struct Node {
    Node(T v, Node *n) {
        value = v;
        next = n;
    }
    Node(T v) : Node{v, nullptr} {}

    T value;
    Node *next;
};

template<typename T>
class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void print();
    Node<T>* find(T);
    void append(T);  // Place new element in the end of list
    void prepend(T);  // Place new element in the beggining of list
    void insert(T);  // Insert value into sorted list
    void remove(Node<T>*);
    Node<T>* pop_head();   // For stack
    Node<T>* get_tail();   // For queue

private:
    Node<T> *head;
    Node<T> *tail;
};

template<typename T>
void LinkedList<T>::print() {
    Node<T> *current = this->head;
    while (current != nullptr) {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "X\n";
}

template<typename T>
Node<T>* LinkedList<T>::find(T val) {
    Node<T> *current = this->head;
    while (current != nullptr && current->value != val) {
        current = current->next;
    }
    return current;
}

template<typename T>
void LinkedList<T>::prepend(T val) {
    Node<T> *tmp = new Node<T>{val, this->head};
    this->head = tmp;
    if (this->tail == nullptr) {
        this->tail = tmp;
    }
}

template<typename T>
void LinkedList<T>::append(T val) {
    Node<T> *tmp = new Node<T>{val};
    if (this->tail == nullptr) {    // Empty list
        this->head = tmp;
    } else {
        this->tail->next = tmp;
    }
    this->tail = tmp;
}

template<typename T>
void LinkedList<T>::insert(T val) {
    Node<T> *tmp = new Node<T>{val};

    Node<T> *curr = this->head, *prev = nullptr;
    while (curr != nullptr && curr->value < val) {
        prev = curr;
        curr = curr->next;
    }

    tmp->next = curr;
    if (curr == nullptr) {
        this->tail = tmp;
    }
    if (prev != nullptr) {
        prev->next = tmp;
    } else {
        this->head = tmp;
    }
}

template<typename T>
void LinkedList<T>::remove(Node<T> *el) {
    Node<T> *curr = this->head, *prev = nullptr;
    while (curr != nullptr && curr != el) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        return;     // Element to remove is not in the list
    }

    if (prev != nullptr) {
        prev->next = curr->next;
    } else {    // Element to remove is head
        this->head = this->head->next;
    }
    if (curr == this->tail) {
        this->tail = prev;
    }

    delete curr;
}

template<typename T>
Node<T>* LinkedList<T>::pop_head() {
    if (this->head == nullptr) {
        throw std::range_error("Tried to get an element from an empty list");
    }

    if (this->head == this->tail) { // After returning the list will be empty
        this->tail = nullptr;
    }

    Node<T> *tmp = this->head;
    this->head = this->head->next;
    return tmp;
}

template<typename T>
Node<T>* LinkedList<T>::get_tail() {
    if (this->tail == nullptr) {
        throw std::range_error("Tried to get an element from an empty list");
    }

    Node<T> *curr = this->head, *prev = nullptr, *result = this->tail;
    while (curr != this->tail) {
        prev = curr;
        curr = curr->next;
    }

    if (this->head == this->tail) { // After returning the list will be empty
        this->tail = nullptr;
        this->head = nullptr;
    }

    prev->next = nullptr;
    this->tail = prev;

    return result;
}

#endif
