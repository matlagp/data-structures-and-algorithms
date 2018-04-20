#ifndef _LL_STACK_H
#define _LL_STACK_H 1

#include "stack.h"
#include "linked_list.h"

class ListStack : public Stack {
public:
    virtual bool is_empty() {
            return (size == 0);
    }
    virtual void push(int);
    virtual int pop();
    virtual void print();

private:
    LinkedList content;
    int size;
};

#endif
