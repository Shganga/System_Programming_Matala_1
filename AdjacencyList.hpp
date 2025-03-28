#ifndef ADJACENCYLIST_HPP
#define ADJACENCYLIST_HPP

#include "Node.hpp"

class AdjacencyList
{
private:
    int numberOfVertices;   // Number of vertices in the graph
    Node** vertices;       // Array of pointers to nodes (adjacency list)

public:
    AdjacencyList(int numberOfVertices);
    ~AdjacencyList();

    // Add an edge from vertex 'from' to vertex 'to'
    void add_edge(int from, int to);

    // Print the adjacency list
    void printAdjacencyList() const;
};

#endif // ADJACENCYLIST_HPP
