#include "Node.hpp"

// Constructor
Node::Node(int val) : value(val), next(nullptr) {}

// Destructor
Node::~Node() {}

// Getter for the value
int Node::get_value() const {
    return value;
}

// Getter for the next node
Node* Node::get_next() const {
    return next;
}

// Setter for the next node
void Node::set_next(Node* nextNode) {
    next = nextNode;
}
