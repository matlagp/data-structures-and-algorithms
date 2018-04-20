#include <iostream>
#include <cstdlib>

#include "utils.h"
#include "sorting.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;   // Didn't get the number of elements to sort
    }
    int size = std::atoi(argv[1]);
    int *A = generate_random_array(size);
    print_array(A, size);
    selection_sort(A, size);
    print_array(A, size);

    delete[] A;

    return 0;
}
