#ifndef _HEAP_H
#define _HEAP_H 1

#include <stdexcept>

enum HeapType { min_heap, max_heap };

template<typename T>
class Heap {
public:
    Heap(int n, HeapType t) {   // Create a new n-size heap
        size = 0;
        type = t;
        capacity = n;
        content = new T[capacity];
        if (t == max_heap) {
            heapify = &Heap::max_heapify;
        } else {
            heapify = &Heap::min_heapify;
        }
    }
    Heap() : Heap{64, max_heap} {}    // When no argument is given use default value - 64
    Heap(T *tab, int n, HeapType t) : Heap{n, t} { // Create heap with existing array
        size = n;
        for (int i = 0; i < n; i++) {
            content[i] = tab[i];
        }
        build_heap();
    }
    Heap(T *tab, int n) : Heap{tab, n, max_heap} {}
    ~Heap() {
        delete[] content;
    }

    bool is_full() {
        return (size == capacity);
    }
    bool is_empty() {
        return (size == 0);
    }
    void sort();
    void insert(T);
    T extract();
    T* extract_content();

private:
    int size;
    int capacity;
    T *content;
    HeapType type;

    int parent(int i) {
        return (i - 1)/2;
    }
    int left(int i) {
        return (i * 2) + 1;
    }
    int right(int i) {
        return (i * 2) + 2;
    }
    void grow();    // Enlarge the inner array if necessary
    void shrink();  // Shrink the inner array if too much space is unused
    void max_heapify(int);
    void min_heapify(int);
    void (Heap::*heapify)(int);
    void build_heap();
};

template<typename T>
void Heap<T>::max_heapify(int i) {
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

template<typename T>
void Heap<T>::min_heapify(int i) {
    int l = this->left(i), r = this->right(i);
    int smallest = i;
    if (l < this->size && this->content[l] < this->content[smallest])
        smallest = l;
    if (r < this->size && this->content[r] < this->content[smallest])
        smallest = r;

    if (smallest != i) {
        int tmp = this->content[i];
        this->content[i] = this->content[smallest];
        this->content[smallest] = tmp;
        this->min_heapify(smallest);
    }
}

template<typename T>
void Heap<T>::build_heap() {
    // Assume that content does not represent a valid heap, usually called after
    // initializing heap with existing array
    for (int i = parent(this->size - 1); i >= 0; i--) {
        (this->*(this->heapify))(i);
    }
}

template<typename T>
void Heap<T>::sort() {
    int saved_size = this->size;
    for (int i = this->size - 1; i >= 1; i--) {
        T tmp = this->content[0];
        this->content[0] = this->content[i];
        this->content[i] = tmp;
        this->size--;
        (this->*(this->heapify))(0);
    }
    this->size = saved_size;
}

template<typename T>
void Heap<T>::grow() {
    if (2 * this->size > this->capacity) {
        int n_cap = this->capacity * 2;
        T *n_tmp = new T[n_cap];
        for (int i = 0; i < this->size; i++) {
            n_tmp[i] = this->content[i];
        }
        T *old_content = this->content;
        this->content = n_tmp;
        this->capacity = n_cap;

        delete[] old_content;
    }
}

template<typename T>
void Heap<T>::shrink() {
    if (4 * this->size < this->capacity) {
        int n_cap = 2 * this->size;
        T *n_tmp = new T[n_cap];
        for (int i = 0; i < this->size; i++) {
            n_tmp[i] = this->content[i];
        }
        T *old_content = this->content;
        this->content = n_tmp;
        this->capacity = n_cap;

        delete[] old_content;
    }
}

template<typename T>
T Heap<T>::extract() {
    if (this->size == 0) {
        throw std::range_error("Tried to extract value from an empty heap");
    }
    T top = this->content[0];
    this->content[0] = this->content[this->size-1];
    this->size--;
    (this->*(this->heapify))(0);
    this->shrink();
    return top;
}

template<typename T>
void Heap<T>::insert(T x) {
    this->grow();
    int i = this->size;
    this->size++;
    this->content[i] = x;
    if (this->type == max_heap) {
        while (i != 0 && this->content[parent(i)] < this->content[i]) {
            T tmp = this->content[parent(i)];
            this->content[parent(i)] = this->content[i];
            this->content[i] = tmp;
            i = parent(i);
        }
    } else {
        while (i != 0 && this->content[parent(i)] > this->content[i]) {
            T tmp = this->content[parent(i)];
            this->content[parent(i)] = this->content[i];
            this->content[i] = tmp;
            i = parent(i);
        }
    }
}

template<typename T>
T* Heap<T>::extract_content() {
    T *tmp = new T[this->size];
    for (int i = 0; i < this->size; i++) {
        tmp[i] = this->content[i];
    }
    return tmp;
}

#endif
