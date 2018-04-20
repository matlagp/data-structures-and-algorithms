#include <iostream>
#include <cstdlib>

#include "ll_stack.h"

void ListStack::push(int val) {
    this->content.append(val);
    this->size++;
}

int ListStack::pop() {
    if (this->is_empty()) {
        // A bad way of handling this situation
        std::cerr << "Error: Cannot pop value from empty stack\n";
        std::exit(1);
    }
    Node *tmp = this->content.pop_head();
    this->size--;

    int v = tmp->value;
    delete tmp;
    return v;
}

void ListStack::print() {
    std::cout << "Stack: ";
    this->content.print();
}
