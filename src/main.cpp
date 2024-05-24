#include <iostream>
#include <cassert>
#include "../include/cache/lru_cache.hpp"

int main() {
    LRUCache* cache = new LRUCache(5);

    cache->put(10, 100);
    cache->put(20, 400);
    cache->put(30, 900);
    cache->put(40, 1600);
    cache->put(50, 2500);

    assert(cache->get(30) == 900);
    assert(cache->get(50) == 2500);

    cache->put(60, 3600);

    assert(cache->get(10) == -1);

    cache->erase(50);
    assert(cache->get(50) == -1);

    return 0;
}