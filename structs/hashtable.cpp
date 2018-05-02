#include <iostream>
#include <string>
#include <stdexcept>

#include "hashtable.h"

HTNode::HTNode(const std::string name, int v, HTNode *n) : id{name} {
    this->val = v;
    this->next = n;
}

HashTable::HashTable(int n, unsigned int (*hash_func)(const std::string)) {
    capacity = n;
    size = 0;
    content = new HTNode*[n];
    for (int i = 0; i < n; i++) {
        content[i] = nullptr;
    }
    hash = hash_func;
}

unsigned int HashTable::default_hash(const std::string string_key) {
    unsigned int result = 0;
    for (int i = 0; string_key[i] != '\0'; i++) {
        result ^= (unsigned int)string_key[i] << (8*(i % sizeof(unsigned int)));
    }

    return result;
}

int& HashTable::operator[](const std::string string_key) {
    int numeric_key = this->hash(string_key) % this->capacity;
    HTNode *current = this->content[numeric_key];

    while (current != nullptr && current->id != string_key) {
        current = current->next;
    }

    if (current == nullptr) {
        // Hash Table is virtually 0 initialized, so when a call is made for
        // a non-existent element, it is created in real time
        HTNode *tmp = new HTNode(string_key, 0, this->content[numeric_key]);
        this->content[numeric_key] = tmp;
        this->size++;
        current = tmp;
    }
    return current->val;
}

bool HashTable::contains(const std::string string_key) const {
    int numeric_key = this->hash(string_key) % this->capacity;
    HTNode *current = this->content[numeric_key];

    while (current != nullptr && current->id != string_key) {
        current = current->next;
    }

    if (current == nullptr) {
        return false;
    }
    return true;
}

void HashTable::print() const {
    for (int i = 0; i < this->capacity; i++) {
        HTNode *current = this->content[i];
        if (current != nullptr) {
            std::cout << "[" << i << "]: ";
            while (current != nullptr) {
                std::cout << current->id << ":" << current->val << " -> ";
                current = current->next;
            }
            std::cout << "X" << std::endl;
            if (i < this->capacity-1 && this->content[i+1] == nullptr) {
                std::cout << "..." << std::endl;
            }
        }
    }
}
