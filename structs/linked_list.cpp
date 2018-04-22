#include <iostream>
#include <cstdlib>

#include "linked_list.h"

void LinkedList::print() {
    Node *current = this->head;
    while (current != nullptr) {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "X\n";
}

Node* LinkedList::find(int val) {
    Node *current = this->head;
    while (current != nullptr && current->value != val) {
        current = current->next;
    }
    return current;
}

void LinkedList::prepend(int val) {
    Node *tmp = new Node;
    tmp->value = val;
    tmp->next = this->head;
    this->head = tmp;
    if (this->tail == nullptr) {
        this->tail = tmp;
    }
}

void LinkedList::append(int val) {
    Node *tmp = new Node;
    tmp->value = val;
    tmp->next = nullptr;
    if (this->tail == nullptr) {    // Empty list
        this->head = tmp;
        this->tail = tmp;
    } else {
        this->tail->next = tmp;
        this->tail = tmp;
    }
}

void LinkedList::insert(int val) {
    Node *tmp = new Node;
    tmp->value = val;

    Node *curr = this->head, *prev = nullptr;
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

void LinkedList::remove(Node *el) {
    Node *curr = this->head, *prev = nullptr;
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

Node* LinkedList::pop_head() {
    // TODO: Rising exception in case of empty list
    if (this->head == nullptr) {
        std::cerr << "Error: Tried to get head of an empty list";
        std::exit(1);
    }

    if (this->head == this->tail) { // After returning the list will be empty
        this->tail = nullptr;
    }

    Node *tmp = this->head;
    this->head = this->head->next;
    return tmp;
}

Node* LinkedList::get_tail() {
    // TODO: Rising exception in case of empty list
    if (this->tail == nullptr) {
        std::cerr << "Error: Tried to get tail of an empty list";
        std::exit(1);
    }

    Node *curr = this->head, *prev = nullptr, *result = this->tail;
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
