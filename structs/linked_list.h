#ifndef _LLIST_H
#define _LLIST_H 1

class Node {
public:
    Node(int v) {
        value = v;
        next = nullptr;
    }
    Node() : Node{0} {}

    int value;
    Node *next;
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    // Return list in reverse order for sorting
    LinkedList(int lrange, int hrange) : LinkedList{} {
        for (int i = lrange; i <= hrange; i++) {
            this->prepend(i);
        }
    }

    void print();
    Node* find(int);
    void append(int);  // Place new element in the end of list
    void prepend(int);  // Place new element in the beggining of list
    void insert(int);  // Insert value into sorted list
    void remove(Node*);
    Node* pop_head();   // For stack
    Node* get_tail();   // For queue

private:
    Node *head;
    Node *tail;
};

#endif
