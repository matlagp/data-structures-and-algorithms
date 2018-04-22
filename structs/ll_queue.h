#ifndef _LL_QUEUE_H
#define _LL_QUEUE_H 1

#include "queue.h"
#include "linked_list.h"

class ListQueue : public Queue {
public:
    virtual bool is_empty() {
        return (size == 0);
    }
    virtual void put(int);
    virtual int get();
    virtual void print();

private:
    LinkedList content;
    int size;
};

#endif
