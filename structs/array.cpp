#include <iostream>
#include <cstdlib>
#include <ctime>

#include "array.h"

int* generate_random_array(int size) {
    srand(time(NULL));
    int *rand_array = new int[size];
    for (int i = 0; i < size; i++) {
        rand_array[i] = (rand() % 1000) + 1;
    }
    return rand_array;
}

void print_array(int *a, int size) {
    for (int i = 0; i < size; i++) {
        if (i % 5 == 0) {
            std::cout << std::endl;
        }
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
