// yanivg1000@gmail.com
#include "Edge.hpp"

// Constructor to initialize destination and weight
Edge::Edge(int dest, int w) : destination(dest), weight(w), next(nullptr) {}

// Constructor to initialize source, destination, weight, and next edge pointer
Edge::Edge(int src, int dest, int w) : source(src), destination(dest), weight(w), next(nullptr) {}

// Getter for the source vertex
int Edge::getSource() const {
    return source;
}

// Getter for the destination vertex
int Edge::getDestination() const {
    return destination;
}

// Getter for the weight of the edge
int Edge::getWeight() const {
    return weight;
}

// Getter for the next edge in the linked list
Edge* Edge::get_next() const {
    return next;
}

// Setter for the next edge in the linked list
void Edge::set_next(Edge* next_edge) {
    next = next_edge;
}
