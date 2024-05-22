#include "../include/node/node.hpp"

Node::Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}