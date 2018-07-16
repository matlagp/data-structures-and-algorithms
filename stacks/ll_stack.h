#ifndef _LL_STACK_H
#define _LL_STACK_H 1

#include <iostream>
#include <stdexcept>

#include "stack.h"
#include "../linked_lists/linked_list.h"

template<typename T>
class ListStack : public Stack<T> {
public:
    virtual bool is_empty() {
            return (size == 0);
    }
    virtual void push(T);
    virtual T pop();
    virtual void print();

private:
    LinkedList<T> content;
    int size;
};

template<typename T>
void ListStack<T>::push(T val) {
    this->content.prepend(val);
    this->size++;
}

template<typename T>
T ListStack<T>::pop() {
    if (this->is_empty()) {
        throw std::range_error("Tried to pop value from an empty stack");
    }
    Node<T> *tmp = this->content.pop_head();
    this->size--;

    T v = tmp->value;
    delete tmp;
    return v;
}

template<typename T>
void ListStack<T>::print() {
    std::cout << "Stack: ";
    this->content.print();
}

#endif
