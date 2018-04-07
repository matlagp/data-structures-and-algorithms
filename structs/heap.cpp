#include "heap.h"

void heap_init(heap *h, int s) {
    h->heap_size = 0;
    h->capacity = s;
    h->tab = new int[s];
}

int parent(int i) {
    return (i-1)/2;
}

int left(int i) {
    return i*2+1;
}

int right(int i) {
    return i*2+2;
}

void max_heapify(heap *h, int i) {
    int l = left(i), r = right(i);
    int largest = i;
    if (l < h->heap_size && h->tab[l] > h->tab[largest])
        largest = l;
    if (r < h->heap_size && h->tab[r] > h->tab[largest])
        largest = r;

    if (largest != i) {
        int tmp = h->tab[i];
        h->tab[i] = h->tab[largest];
        h->tab[largest] = tmp;
        max_heapify(h, largest);
    }
}

heap* build_max_heap(int A[], int n) {
    // Builds heap from existing array, so sorting doesn't require any additional space
    heap *h = new heap;
    h->tab = A;
    h->capacity = n;
    h->heap_size = n;

    for (int i = parent(h->heap_size-1); i >= 0; i--)
        max_heapify(h, i);

    return h;
}
