#ifndef _ARRAY_STACK_H
#define _ARRAY_STACK_H 1

#include <iostream>
#include <stdexcept>

#include "stack.h"

template<typename T>
class ArrayStack : public Stack<T> {
public:
    ArrayStack(int n) {
        size = 0;
        capacity = n;
        content = new T[n];
    }
    ArrayStack() : ArrayStack{64} {}
    ~ArrayStack() {
        delete[] content;
    }

    virtual bool is_empty() {
        return (size == 0);
    }
    virtual void push(T);
    virtual T pop();
    virtual void print();

private:
    T *content;
    int size;
    int capacity;
};

template<typename T>
void ArrayStack<T>::push(T v) {
    if (this->size == this->capacity) {
        int n_cap = this->capacity * 2;
        T *n_tmp = new T[n_cap];
        for (int i = 0; i < this->size; i++) {
            n_tmp[i] = this->content[i];
        }
        T *old_content = this->content;
        this->content = n_tmp;
        this->capacity = n_cap;

        delete[] old_content;
    }

    this->content[this->size] = v;
    this->size++;
}

template<typename T>
T ArrayStack<T>::pop() {
    if (this->is_empty()) {
        throw std::range_error("Tried to pop value from an empty stack");
    }
    if (this->capacity >= 4 * this->size) {
        int n_cap = 2 * this->size;
        T *n_tmp = new T[n_cap];
        for (int i = 0; i < this->size; i++) {
            n_tmp[i] = this->content[i];
        }
        T *old_content = this->content;
        this->content = n_tmp;
        this->capacity = n_cap;

        delete[] old_content;
    }
    this->size--;
    return this->content[this->size];
}

template<typename T>
void ArrayStack<T>::print() {
    std::cout << "Stack: TOP / ";
    for (int i = this->size - 1; i >= 0; i--) {
        std::cout << this->content[i] << " / ";
    }
    std::cout << "BOTTOM\n";
}

#endif
