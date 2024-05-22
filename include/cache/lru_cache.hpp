#ifndef LRU_CACHE_HPP
#define LRU_CACHE_HPP

#include "../node/node.hpp"
#include "unordered_map"

class LRUCache {
private:
    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void remove(Node* node);
    void add(Node* node);

public:
    LRUCache(int capacity);
    ~LRUCache();
    int get(int key);
    void put(int key, int value);
    void erase(int key);
};

#endif // LRU_CACHE_HPP