#ifndef _SORTING_H
#define _SORTING_H 1

#include "heaps/heap.h"

template<typename T>
void heapsort(T A[], int n) {
    Heap<T> h(A, n);
    // h.sort();
    // A = h.extract_content();
    for (int i = n-1; i >= 0; i--) {
        A[i] = h.extract();
    }
}

template<typename T>
void insertion_sort(T A[], int n) {
    for (int i = 0; i < n; i++) {
        int j = i-1;
        T x = A[i];
        while (j >= 0 && A[j] > x) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

template<typename T>
void selection_sort(T A[], int n) {
    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i; j < n; j++) {
            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }
        T tmp = A[i];
        A[i] = A[min_index];
        A[min_index] = tmp;
    }
}

template<typename T>
void merge(T A[], int b, int m, int e) {
    T *aux = new T[e - b + 1];
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

template<typename T>
void _merge_sort(T A[], int b, int e) {
    if (b < e) {
        int m = (b + e)/2;
        _merge_sort(A, b, m);
        _merge_sort(A, m+1, e);
        merge(A, b, m, e);
    }
}

template<typename T>
void merge_sort(T A[], int n) {
    _merge_sort(A, 0, n-1);
}

template<typename T>
int partition(T A[], int p, int r) {
    T x = A[r];
    int i = p-1, j = p;
    while (j < r) {
        if (A[j] <= x) {
            i++;
            T tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
        j++;
    }
    i++;
    T tmp = A[i];
    A[i] = x;
    A[r] = tmp;
    return i;
}

template<typename T>
void _quicksort(T A[], int b, int e) {
    if (b < e) {
        int q = partition(A, b, e);
        _quicksort(A, b, q-1);
        _quicksort(A, q+1, e);
    }
}

template<typename T>
void quicksort(T A[], int n) {
    _quicksort(A, 0, n-1);
}

#endif
