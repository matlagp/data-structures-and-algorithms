#include <iostream>

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

void LinkedList::append(int val) {
    Node *tmp = new Node;
    tmp->value = val;
    tmp->next = this->head;
    this->head = tmp;
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

    prev->next = curr->next;
    delete curr;
}

Node* LinkedList::pop_head() {
    // TODO: Rising exception in case of empty list
    Node *tmp = this->head;
    this->head = this->head->next;
    return tmp;
}
