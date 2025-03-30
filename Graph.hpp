#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Edge.hpp"

namespace graph {
    class Graph {
    private:
        int num_vertices;  // The number of vertices in the graph
        Edge** adjacency_list;  // Array of adjacency lists (array of Edge pointers)

    public:
        Graph(int vertices);  // Constructor
        ~Graph();  // Destructor

        void add_edge(int from, int to, int weight = 1);  // Add an edge between two vertices
        void remove_edge(int from, int to);  // Remove an edge between two vertices
        void print_graph() const;  // Print the graph's adjacency list

    private:
        void remove_edge_helper(int from, int to);  // Helper function to remove an edge from the adjacency list
    };
}

#endif // GRAPH_HPP
