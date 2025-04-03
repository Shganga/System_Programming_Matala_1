//yanivg1000@gmail.com
#include "Edge.hpp"

// Constructor to initialize destination and weight
Edge::Edge(int dest, int w) : destination(dest), weight(w), next(nullptr) {}

Edge::Edge(int src, int dest, int w) : source(src), destination(dest), weight(w), next(nullptr) {}


int Edge::getSource() const {
    return source;
}

// Getter for destination
int Edge::getDestination() const {
    return destination;
}

// Getter for weight
int Edge::getWeight() const {
    return weight;
}

// Getter for next edge
Edge* Edge::get_next() const {
    return next;
}

// Setter for next edge
void Edge::set_next(Edge* next_edge) {
    next = next_edge;
}
