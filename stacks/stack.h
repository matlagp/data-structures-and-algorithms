#ifndef _STACK_H
#define _STACK_H 1

template<typename T>
class Stack {
public:
    virtual bool is_empty() = 0;
    virtual void push(T) = 0;
    virtual T pop() = 0;
    virtual void print() = 0;

    virtual ~Stack() {}
};

#endif
