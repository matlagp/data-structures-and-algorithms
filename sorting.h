#ifndef _SORTING_H
#define _SORTING_H 1

void heapsort(int A[], int n);
void insertion_sort(int A[], int n);
void selection_sort(int A[], int n);
void merge(int A[], int b, int m, int e);
void _merge_sort(int A[], int b, int e);
void merge_sort(int A[], int n);
int partition(int A[], int p, int r);
void _quicksort(int A[], int b, int e);
void quicksort(int A[], int n);

#endif
