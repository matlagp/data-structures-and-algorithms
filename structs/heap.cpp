#include "heap.h"

void Heap::max_heapify(int i) {
    int l = this->left(i), r = this->right(i);
    int largest = i;
    if (l < this->size && this->content[l] > this->content[largest])
        largest = l;
    if (r < this->size && this->content[r] > this->content[largest])
        largest = r;

    if (largest != i) {
        int tmp = this->content[i];
        this->content[i] = this->content[largest];
        this->content[largest] = tmp;
        this->max_heapify(largest);
    }
}

void Heap::build_max_heap() {
    // Assume that content does not represent a valid heap, usually called after
    // initiating heap with existing array
    for (int i = parent(this->size - 1); i >= 0; i--) {
        this->max_heapify(i);
    }
}

int* Heap::sort() {
    // Calling this will destroy heap; we sort content and return pointer to it,
    // we also change inner array to size 1 tab, as it presumably will be
    // deleted shortly after calling this function
    for (int i = this->size - 1; i >= 1; i--) {
        int tmp = this->content[0];
        this->content[0] = this->content[i];
        this->content[i] = tmp;
        this->size--;
        max_heapify(0);
    }
    int *tmp = this->content;
    this->capacity = 1;
    this->size = 1;
    this->content = new int[1];
    return tmp;
}
