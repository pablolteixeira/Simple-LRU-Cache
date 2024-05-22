#ifndef NODE_HPP
#define NODE_HPP

#include <string>

class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value);
};

#endif // NODE_HPP