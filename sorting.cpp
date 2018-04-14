#include "structs/heap.h"

void heapsort(int A[], int n) {
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

void insertion_sort(int A[], int n) {
    for (int i = 0; i < n; i++) {
        int j = i-1;
        int x = A[i];
        while (j >= 0 && A[j] > x) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void selection_sort(int A[], int n) {
    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i; j < n; j++) {
            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }
        int tmp = A[i];
        A[i] = A[min_index];
        A[min_index] = tmp;
    }
}

void merge(int A[], int b, int m, int e) {
    int *aux = new int[e - b + 1];
    int p = b, q = m+1, i = 0;
    while ( p <= m && q <= e) {
        if (A[p] <= A[q]) {
            aux[i++] = A[p++];
        } else {
            aux[i++] = A[q++];
        }
    }
    while (p <= m) {
        aux[i++] = A[p++];
    }
    while (q <= e) {
        aux[i++] = A[q++];
    }

    for (int j = 0; j < (e - b + 1); j++) {
        A[b + j] = aux[j];
    }

    delete[] aux;
}

void _merge_sort(int A[], int b, int e) {
    if (b < e) {
        int m = (b + e)/2;
        _merge_sort(A, b, m);
        _merge_sort(A, m+1, e);
        merge(A, b, m, e);
    }
}

void merge_sort(int A[], int n) {
    _merge_sort(A, 0, n-1);
}

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p-1, j = p;
    while (j < r) {
        if (A[j] <= x) {
            i++;
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
        j++;
    }
    i++;
    int tmp = A[i];
    A[i] = x;
    A[r] = tmp;
    return i;
}

void _quicksort(int A[], int b, int e) {
    if (b < e) {
        int q = partition(A, b, e);
        _quicksort(A, b, q-1);
        _quicksort(A, q+1, e);
    }
}

void quicksort(int A[], int n) {
    _quicksort(A, 0, n-1);
}
