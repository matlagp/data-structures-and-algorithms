#include <iostream>
#include <cstdlib>

#include "array.h"
#include "heap.h"

void heap_sort(int A[], int n) {
    heap *h = build_max_heap(A, n);
    for (int i = h->heap_size-1; i >= 1; i--) {
        int tmp = h->tab[0];
        h->tab[0] = h->tab[i];
        h->tab[i] = tmp;
        h->heap_size--;
        max_heapify(h, 0);
    }

    delete h;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;   // Didn't get the number of elements to sort
    }
    int size = std::atoi(argv[1]);
    int *A = generate_random_array(size);
    print_array(A, size);
    heap_sort(A, size);
    print_array(A, size);

    delete[] A;

    return 0;
}
