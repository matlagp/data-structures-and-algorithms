#include <iostream>

#include "linked_list.h"

node* generate_list(int lrange, int hrange) {
    // Returns list in reversed order so it can be sorted right away
    node *head = NULL;
    for (int i = lrange; i <= hrange; i++) {
        head = append(head, i);
    }
    return head;
}

void print_list(node *head) {
    while (head != NULL) {
        std::cout << head->key << " -> ";
        head = head->next;
    }
    std::cout << "X\n";
}

node* append(node *head, int val) {
    node *tmp = new node;
    tmp->key = val;
    tmp->next = head;
    return tmp;
}

node* insert(node *head, int val) {
    node *tmp = new node;
    tmp->key = val;

    node *curr = head, *prev = NULL;
    while (curr != NULL && curr->key < val) {
        prev = curr;
        curr = curr->next;
    }

    tmp->next = curr;
    if (prev != NULL) {
        prev->next = tmp;
    } else {
        head = tmp;
    }

    return head;
}

node* find(node *head, int val) {
    while (head != NULL && head->key != val) {
        head = head->next;
    }
    return head;
}

void remove(node *head, node *el) {
    node *curr = head, *prev = NULL;
    while (curr != NULL && curr != el) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        return;     // Element to remove is not in the list
    }

    prev->next = curr->next;
    delete curr;
}
