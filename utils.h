#ifndef _UTILS_H
#define _UTILS_H 1

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "linked_lists/linked_list.h"

// Helper structure mainly for sorting algorithms

int* generate_random_array(int size) {
    srand(time(NULL));
    int *rand_array = new int[size];
    for (int i = 0; i < size; i++) {
        rand_array[i] = (rand() % 1000) + 1;
    }
    return rand_array;
}

template<typename T>
void print_array(T *a, int size) {
    for (int i = 0; i < size; i++) {
        if (i % 5 == 0) {
            std::cout << std::endl;
        }
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

LinkedList<int>* generate_random_ll(int size) {
    srand(time(NULL));
    LinkedList<int> *ll = new LinkedList<int>;
    while (size > 0) {
        ll->append((rand() % 1000) + 1);
    }
    return ll;
}

#endif
