#include <iostream>
#include <cstdlib>

#include "array_stack.h"

void ArrayStack::push(int v) {
    if (this->size == this->capacity) {
        int n_cap = this->capacity * 2;
        int *n_tmp = new int[n_cap];
        for (int i = 0; i < this->size; i++) {
            n_tmp[i] = this->content[i];
        }
        int *old_content = this->content;
        this->content = n_tmp;
        this->capacity = n_cap;

        delete[] old_content;
    }

    this->content[this->size] = v;
    this->size++;
}

int ArrayStack::pop() {
    if (this->is_empty()) {
        // A bad way of handling this situation
        std::cerr << "Error: Cannot pop value from empty stack\n";
        std::exit(1);
    }
    this->size--;
    if (this->capacity >= 4 * this->size) {
        int n_cap = 2 * this->size;
        int *n_tmp = new int[n_cap];
        for (int i = 0; i < this->size; i++) {
            n_tmp[i] = this->content[i];
        }
        int *old_content = this->content;
        this->content = n_tmp;
        this->capacity = n_cap;

        delete[] old_content;
    }
    return this->content[this->size];
}

void ArrayStack::print() {
    std::cout << "Stack: ";
    for (int i = 0; i < this->size; i++) {
        std::cout << this->content[i] << " / ";
    }
    std::cout << "X\n";
}
