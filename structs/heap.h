#ifndef _HEAP_H
#define _HEAP_H 1

class Heap {
public:
    Heap(int n) {   // Create a new n-size heap
        size = 0;
        capacity = n;
        content = new int[capacity];
    }
    Heap() : Heap{64} {}    // When no argument is given use default value - 64
    Heap(int *tab, int n) { // Create heap with existing array
        size = capacity = n;
        content = tab;
        build_max_heap();
    }
    ~Heap() {
        delete[] content;
    }

    bool is_full() {
        return (size == capacity);
    }
    int parent(int i) {
        return (i - 1)/2;
    }
    int left(int i) {
        return (i * 2) + 1;
    }
    int right(int i) {
        return (i * 2) + 2;
    }
    void max_heapify(int);
    void build_max_heap();
    int* sort();    // Will destroy the heap

private:
    int size;
    int capacity;
    int *content;
};

#endif
