#ifndef _HASHTABLE_H
#define _HASHTABLE_H 1

#include <string>

struct HTNode {
    HTNode(const std::string, int, HTNode*);

    const std::string id;
    int val;
    HTNode *next;
};

class HashTable {
public:
    HashTable(int n, unsigned int (*hash_func)(const std::string));
    HashTable(int n) : HashTable{n, default_hash} {}
    HashTable(unsigned int (*hash_func)(const std::string)) : HashTable{64, hash_func} {}
    HashTable() : HashTable{64, default_hash} {}
    ~HashTable() {
        delete[] content;
    }

    int& operator[](const std::string);
    bool contains(const std::string) const;
    void print() const;

private:
    HTNode **content;
    int capacity;
    int size;
    unsigned int (*hash)(const std::string);
    static unsigned int default_hash(const std::string);
};

#endif
