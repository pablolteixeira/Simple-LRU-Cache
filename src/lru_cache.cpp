#include "../include/cache/lru_cache.hpp"
#include "../include/node/node.hpp"

// PRIVATE IMPLEMENTATION
void LRUCache::add(Node* node) {
    node->next = head->next;
    node->next->prev = node;
    head->next = node;
    node->prev = head;
}

void LRUCache::remove(Node* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
}

// PUBLIC IMPLEMENTATION
LRUCache::LRUCache(int capacity) {
    this->capacity = capacity;
    head = new Node(0, 0);
    tail = new Node(0, 0);

    head->next = tail;
    tail->prev = head;
}

LRUCache::~LRUCache() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current ->next;
        delete current;
        current = next;
    }
}   

int LRUCache::get(int key) {
    if (cache.find(key) != cache.end()) {
        Node* node = cache[key];

        remove(node);
        add(node);

        return node->value;
    }

    return -1;
}

void LRUCache::put(int key, int value) {
    if (cache.find(key) != cache.end()) {
        remove(cache[key]);
    }
    Node* node = new Node(key, value);
    add(node);

    cache[key] = node;

    if (cache.size() > capacity) {
        Node* lru = tail->prev;

        remove(lru);
        cache.erase(lru->value);
        delete lru;
    }
}

void LRUCache::erase(int key) {
    if (cache.find(key) != cache.end()) {
        Node* node = cache[key];

        remove(node);
        cache.erase(node->key);

        delete node;
    }
}
