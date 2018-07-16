#ifndef _BUCKET_HASHTABLE_H
#define _BUCKET_HASHTABLE_H 1

#include <iostream>
#include <string>
#include <stdexcept>

#include "hashtable.h"

template<typename T, typename Key>
struct HTNode {
    HTNode(const Key, T, HTNode*);

    const Key id;
    T val;
    HTNode *next;
};

template<typename T, typename Key = std::string>
class BHashTable : public HashTable<T, Key> {
public:
    BHashTable(int n, unsigned int (*hash_func)(const Key));
    BHashTable(unsigned int (*hash_func)(const Key)) : BHashTable{64, hash_func} {}
    ~BHashTable() {
        delete[] content;
    }

    T get(const Key) const;
    void put(const Key, const T);
    bool contains(const Key) const;
    void print() const;

private:
    HTNode<T, Key> **content;
    int capacity;
    int size;
    unsigned int (*hash)(const Key);
};

template<typename T, typename Key>
HTNode<T, Key>::HTNode(const Key k, T v, HTNode *n) : id{k} {
    this->val = v;
    this->next = n;
}

template<typename T, typename Key>
BHashTable<T, Key>::BHashTable(int n, unsigned int (*hash_func)(const Key)) {
    this->capacity = n;
    this->size = 0;
    this->content = new HTNode<T, Key>*[n];
    for (int i = 0; i < n; i++) {
        content[i] = nullptr;
    }
    this->hash = hash_func;
}

template<typename T, typename Key>
T BHashTable<T, Key>::get(const Key key) const {
    unsigned int numeric_key = this->hash(key) % this->capacity;
    HTNode<T, Key> *current = this->content[numeric_key];

    while (current != nullptr && current->id != key) {
        current = current->next;
    }

    if (current == nullptr) {
        throw std::range_error("Wanted to get a value not present in the hashtable");
    }
    return current->val;
}

template<typename T, typename Key>
void BHashTable<T, Key>::put(const Key key, const T value) {
    unsigned int numeric_key = this->hash(key) % this->capacity;
    HTNode<T, Key> *current = this->content[numeric_key];

    while (current != nullptr && current->id != key) {
        current = current->next;
    }

    if (current == nullptr) {
        current = new HTNode<T, Key>(key, value, this->content[numeric_key]);
        this->content[numeric_key] = current;
    }
    current->val = value;
}

template<typename T, typename Key>
bool BHashTable<T, Key>::contains(const Key key) const {
    int numeric_key = this->hash(key) % this->capacity;
    HTNode<T, Key> *current = this->content[numeric_key];

    while (current != nullptr && current->id != key) {
        current = current->next;
    }

    if (current == nullptr) {
        return false;
    }
    return true;
}

template<typename T, typename Key>
void BHashTable<T, Key>::print() const {
    for (int i = 0; i < this->capacity; i++) {
        HTNode<T, Key> *current = this->content[i];
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

#endif
