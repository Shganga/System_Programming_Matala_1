//yanivg1000@gmail.com
#include "Graph.hpp"
#include "Algorithms.hpp"
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

    // Run BFS algorithm from vertex 0
    std::cout << "\nRunning BFS from vertex 0:" << std::endl;
    graph::Graph bfs_tree = graph::Algorithms::bfs(g, 0);
    bfs_tree.print_graph();  // Print BFS tree

    // Run DFS algorithm from vertex 0
    std::cout << "\nRunning DFS from vertex 0:" << std::endl;
    graph::Graph dfs_tree = graph::Algorithms::dfs(g, 0);
    dfs_tree.print_graph();  // Print DFS tree

    // Run Dijkstra's algorithm from vertex 0
    std::cout << "\nRunning Dijkstra's algorithm from vertex 0:" << std::endl;
    graph::Graph dijkstra_tree = graph::Algorithms::dijkstra(g,0);
    dijkstra_tree.print_graph();

    // Run Kruskal's algorithm to find the Minimum Spanning Tree (MST)
    std::cout << "\nRunning Kruskal's algorithm for MST:" << std::endl;
    graph::Graph mst_kruskal = graph::Algorithms::kruskal(g);
    mst_kruskal.print_graph();  // Print MST obtained from Kruskal's algorithm

    // Run Prim's algorithm to find the Minimum Spanning Tree (MST)
    std::cout << "\nRunning Prim's algorithm for MST:" << std::endl;
    graph::Graph mst_prim = graph::Algorithms::prim(g);
    mst_prim.print_graph();  // Print MST obtained from Prim's algorithm

    // Remove an edge and print the graph again
    g.remove_edge(2, 4);  // Remove edge between vertex 2 and vertex 4
    std::cout << "\nAfter removing edge (2, 4):" << std::endl;
    g.print_graph();

    return 0;
}
