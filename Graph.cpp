#include "Graph.hpp"
#include "Edge.hpp"
#include <iostream>
#include <stdexcept>

namespace graph {
    Graph::Graph(int vertices) : num_vertices(vertices) {
        adjacency_list = new Node*[num_vertices];
        for (int i = 0; i < num_vertices; ++i) {
            adjacency_list[i] = nullptr;
        }
    }

    Graph::~Graph() {
        for (int i = 0; i < num_vertices; ++i) {
            Node* current = adjacency_list[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->get_next();
                delete temp;
            }
        }
        delete[] adjacency_list;
    }

    void Graph::add_edge(int from, int to, int weight) {
        if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices) {
            throw std::invalid_argument("Invalid vertex index");
        }

        // Add the edge from 'from' to 'to'
        Node* new_node = new Node(to);  // Only storing destination
        new_node->set_next(adjacency_list[from]);
        adjacency_list[from] = new_node;

        // Add the edge from 'to' to 'from' (since the graph is undirected)
        new_node = new Node(from);  // Only storing destination
        new_node->set_next(adjacency_list[to]);
        adjacency_list[to] = new_node;
    }

    void Graph::remove_edge(int from, int to) {
        if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices) {
            throw std::invalid_argument("Invalid vertex index");
        }

        remove_edge_helper(from, to);
        remove_edge_helper(to, from);
    }

    // Helper function to remove an edge from the adjacency list
    void Graph::remove_edge_helper(int from, int to) {
        Node* current = adjacency_list[from];
        Node* prev = nullptr;

        while (current != nullptr && current->get_value() != to) {
            prev = current;
            current = current->get_next();
        }

        if (current == nullptr) {
            throw std::runtime_error("Edge not found");
        }

        if (prev == nullptr) {
            adjacency_list[from] = current->get_next();
        } else {
            prev->set_next(current->get_next());
        }

        delete current;
    }

    void Graph::print_graph() const {
        for (int i = 0; i < num_vertices; ++i) {
            std::cout << "Vertex " << i << ": ";
            Node* current = adjacency_list[i];
            while (current != nullptr) {
                std::cout << current->get_value() << " ";
                current = current->get_next();
            }
            std::cout << std::endl;
        }
    }
}
