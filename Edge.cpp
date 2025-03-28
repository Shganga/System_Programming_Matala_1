#include "Edge.hpp"

// Constructor to initialize destination and weight
Edge::Edge(int dest, int w) : destination(dest), weight(w) {}

// Getter for destination
int Edge::getDestination() const {
    return destination;
}

// Getter for weight
int Edge::getWeight() const {
    return weight;
}
