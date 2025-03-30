#include "Graph.hpp"
#include <iostream>

int main() {
    // Create a graph with 5 vertices
    graph::Graph g(5);

    // Add edges between some vertices with weights
    g.add_edge(0, 1, 10);  // Add edge from vertex 0 to vertex 1 with weight 10
    g.add_edge(0, 2, 15);  // Add edge from vertex 0 to vertex 2 with weight 15
    g.add_edge(1, 3, 20);  // Add edge from vertex 1 to vertex 3 with weight 20
    g.add_edge(2, 4, 25);  // Add edge from vertex 2 to vertex 4 with weight 25
    g.add_edge(3, 4, 30);  // Add edge from vertex 3 to vertex 4 with weight 30

    // Print the graph to show the adjacency list
    std::cout << "Graph adjacency list:" << std::endl;
    g.print_graph();

    // Remove an edge and print the graph again
    g.remove_edge(2, 4);  // Remove edge between vertex 2 and vertex 4
    std::cout << "\nAfter removing edge (2, 4):" << std::endl;
    g.print_graph();

    return 0;
}
