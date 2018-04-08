#ifndef _HEAP_H
#define _HEAP_H 1

struct heap {
    int *tab;
    int heap_size;
    int capacity;
};

void heap_init(heap *h, int s);
int parent(int i);
int left(int i);
int right(int i);
void max_heapify(heap *h, int i);
heap* build_max_heap(int A[], int n);
void destroy_heap(heap *h);

#endif
