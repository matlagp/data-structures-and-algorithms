#ifndef _STACK_H
#define _STACK_H 1

#include "linked_list.h"

struct stack {
    node *top;
    int size;
};

void init(stack *st);
bool is_empty(stack *st);
void push(stack *st, int val);
int pop(stack *st);

#endif
