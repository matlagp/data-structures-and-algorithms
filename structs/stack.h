#ifndef _STACK_H
#define _STACK_H 1

class Stack {
public:
    virtual bool is_empty() = 0;
    virtual void push(int) = 0;
    virtual int pop() = 0;
    virtual void print() = 0;

    virtual ~Stack() {}
};

#endif
