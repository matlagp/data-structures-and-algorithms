#ifndef _LLIST_H
#define _LLIST_H 1

struct node {
    int key;
    node *next;
};

node* generate_list(int lrange, int hrange);    // Return list in reverse order for sorting
void print_list(node *head);
node* append(node *head, int val);  // Place new element in the beggining of list
node* insert(node *head, int val);  // Insert value into sorted list
node* find(node *head, int val);
void remove(node *head, node *el);

#endif
