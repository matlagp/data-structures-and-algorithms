#ifndef _ARRAY_STACK_H
#define _ARRAY_STACK_H 1

#include "stack.h"

class ArrayStack : public Stack {
public:
    ArrayStack(int n) {
        size = 0;
        capacity = n;
        content = new int[n];
    }
    ArrayStack() : ArrayStack{64} {}
    ~ArrayStack() {
        delete[] content;
    }

    virtual bool is_empty() {
        return (size == 0);
    }
    virtual void push(int);
    virtual int pop();
    virtual void print();

private:
    int *content;
    int size;
    int capacity;
};

#endif
