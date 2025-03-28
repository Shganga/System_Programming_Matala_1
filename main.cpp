#include "Graph.hpp"
#include <iostream>

int main() {
    // Create a graph with 5 vertices
    graph::Graph g(5);

    // Add edges between some vertices
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 4);
    g.add_edge(3, 4);

    // Print the graph to show the adjacency list
    std::cout << "Graph adjacency list:" << std::endl;
    g.print_graph();

    // Remove an edge and print the graph again
    g.remove_edge(2, 4);
    std::cout << "\nAfter removing edge (2, 4):" << std::endl;
    g.print_graph();

    return 0;
}
