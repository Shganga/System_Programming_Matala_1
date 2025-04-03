//yanivg1000@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Edge.hpp"
#include <iostream>
#include <stdexcept>

namespace graph {

    class Graph {
    public:
        Graph(int vertices);
        ~Graph();

        void add_edge(int from, int to, int weight);
        void add_one_edge(int from,int to, int weight);
        void remove_edge(int from, int to);

        void print_graph() const;  
        bool has_edge(int from, int to) const; 
        int get_num_vertices() const;
        int* get_adjacent_vertices(int vertex) const;  
        int get_edge_weight(int from, int to) const;

    private:
        void remove_edge_helper(int from, int to);

        int num_vertices;
        Edge** adjacency_list;  
    };
}

#endif
