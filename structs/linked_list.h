#ifndef _LLIST_H
#define _LLIST_H 1

class Node {
public:
    Node() {
        value = 0;
        next = nullptr;
    }
    Node(int v) {
        value = v;
        next = nullptr;
    }

    int value;
    Node *next;
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
    }
    // Return list in reverse order for sorting
    LinkedList(int lrange, int hrange) : LinkedList{} {
        for (int i = lrange; i <= hrange; i++) {
            this->append(i);
        }
    }

    void print();
    Node* find(int val);
    void append(int val);  // Place new element in the beggining of list
    void insert(int val);  // Insert value into sorted list
    void remove(Node *el);
    Node* pop_head();

private:
    Node *head;
};

#endif
