#ifndef EDGE_HPP
#define EDGE_HPP

class Edge {
private:
    int destination;
    int weight;

public:
    // Constructor declaration
    Edge(int dest, int w);

    // Getter declarations
    int getDestination() const;
    int getWeight() const;
};

#endif // EDGE_HPP
