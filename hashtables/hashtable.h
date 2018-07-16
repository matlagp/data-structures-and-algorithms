#ifndef _HASHTABLE_H
#define _HASHTABLE_H 1

#include <string>

template<typename T, typename Key = std::string>
class HashTable {
public:
    virtual ~HashTable() {}

    virtual bool contains(const Key) const = 0;
    virtual T get(const Key) const = 0;
    virtual void put(const Key, const T) = 0;
    virtual void print() const = 0;

    static unsigned int default_hash(const std::string string_key) {
        unsigned int result = 0;
        for (int i = 0; i < string_key.length(); i++) {
            result ^= (unsigned int)string_key[i] << (8*(i % sizeof(unsigned int)));
        }

        return result;
    }

private:
    int capacity;
    int size;
    unsigned int (*hash)(const Key);
};

#endif
