#ifndef _LL_QUEUE_H
#define _LL_QUEUE_H 1

#include <iostream>
#include <stdexcept>

#include "queue.h"
#include "../linked_lists/linked_list.h"

template<typename T>
class ListQueue : public Queue<T> {
public:
    virtual bool is_empty() {
        return (size == 0);
    }
    virtual void put(T);
    virtual T get();
    virtual void print();

private:
    LinkedList<T> content;
    int size;
};

template<typename T>
void ListQueue<T>::put(T v) {
    this->content.append(v);
    this->size++;
}

template<typename T>
T ListQueue<T>::get() {
    if (this->is_empty()) {
        throw std::range_error("Tried to get element from an empty queue");
    }
    Node<T> *tmp = this->content.pop_head();
    this->size--;

    T v = tmp->value;
    delete tmp;
    return v;
}

template<typename T>
void ListQueue<T>::print() {
    std::cout << "Queue: ";
    this->content.print();
}

#endif
