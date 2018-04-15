#include <iostream>
#include <cstdlib>

#include "stack.h"

void init(stack *st) {
    st->size = 0;
    st->top = NULL;
}

bool is_empty(stack *st) {
    return (st->size == 0);
}

void push(stack *st, int val) {
    node *tmp = new node;
    tmp->key = val;
    tmp->next = st->top;
    st->top = tmp;
    st->size++;
}

int pop(stack *st) {
    if (is_empty(st)) {
        // A bad way of handling this situation
        std::cerr << "Error: Cannot pop value from empty stack\n";
        std::exit(1);
    }
    node *tmp = st->top;
    st->top = st->top->next;
    st->size--;

    int v = tmp->key;
    delete tmp;
    return v;
}
