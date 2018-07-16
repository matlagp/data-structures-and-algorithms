#ifndef _QUEUE_H
#define _QUEUE_H 1

template<typename T>
class Queue {
public:
    virtual bool is_empty() = 0;
    virtual void put(T) = 0;
    virtual T get() = 0;
    virtual void print() = 0;

    virtual ~Queue() {}
};

#endif
