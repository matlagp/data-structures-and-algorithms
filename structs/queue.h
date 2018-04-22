#ifndef _QUEUE_H
#define _QUEUE_H 1

class Queue {
public:
    virtual bool is_empty() = 0;
    virtual void put(int) = 0;
    virtual int get() = 0;
    virtual void print() = 0;

    virtual ~Queue() {}
};

#endif
