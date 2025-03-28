#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Node.hpp"
#include "Edge.hpp"

namespace graph {
    class Graph {
    private:
        int num_vertices;  
        Node** adjacency_list;  

    public:
        Graph(int vertices);
        ~Graph();

        void add_edge(int from, int to, int weight = 1);
        void remove_edge(int from, int to);
        void print_graph() const;

    private:
        void remove_edge_helper(int from, int to);
    };
}

#endif // GRAPH_HPP
