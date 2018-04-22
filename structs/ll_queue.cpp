#include <iostream>
#include <cstdlib>

#include "ll_queue.h"

void ListQueue::put(int v) {
    this->content.append(v);
    this->size++;
}

int ListQueue::get() {
    if (this->is_empty()) {
        // A bad way of handling this situation
        std::cerr << "Error: Cannot get value from empty queue\n";
        std::exit(1);
    }
    Node *tmp = this->content.pop_head();
    this->size--;

    int v = tmp->value;
    delete tmp;
    return v;
}

void ListQueue::print() {
    std::cout << "Queue: ";
    this->content.print();
}
