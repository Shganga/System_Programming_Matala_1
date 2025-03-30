#include "Graph.hpp"
#include "Edge.hpp"
#include <iostream>
#include <stdexcept>

namespace graph {

    // Constructor to initialize graph with a number of vertices
    Graph::Graph(int vertices) : num_vertices(vertices) {
        adjacency_list = new Edge*[num_vertices];
        for (int i = 0; i < num_vertices; ++i) {
            adjacency_list[i] = nullptr;  // Initialize each adjacency list as nullptr (empty)
        }
    }

    // Destructor to free memory for adjacency lists and edges
    Graph::~Graph() {
        for (int i = 0; i < num_vertices; ++i) {
            Edge* current = adjacency_list[i];
            while (current != nullptr) {
                Edge* temp = current;
                current = current->get_next();
                delete temp;
            }
        }
        delete[] adjacency_list;
    }

    // Add an edge between 'from' and 'to' with a given weight
    void Graph::add_edge(int from, int to, int weight) {
        if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices) {
            throw std::invalid_argument("Invalid vertex index");
        }

        // Add the edge from 'from' to 'to'
        Edge* new_edge = new Edge(to, weight);  // Create a new edge
        new_edge->set_next(adjacency_list[from]);
        adjacency_list[from] = new_edge;  // Add to the adjacency list of 'from'

        // Add the edge from 'to' to 'from' (since the graph is undirected)
        new_edge = new Edge(from, weight);  // Create a new edge
        new_edge->set_next(adjacency_list[to]);
        adjacency_list[to] = new_edge;  // Add to the adjacency list of 'to'
    }

    // Remove an edge between 'from' and 'to'
    void Graph::remove_edge(int from, int to) {
        if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices) {
            throw std::invalid_argument("Invalid vertex index");
        }

        remove_edge_helper(from, to);  // Remove edge from 'from' to 'to'
        remove_edge_helper(to, from);  // Remove edge from 'to' to 'from' (undirected graph)
    }

    // Helper function to remove an edge from the adjacency list
    void Graph::remove_edge_helper(int from, int to) {
        Edge* current = adjacency_list[from];
        Edge* prev = nullptr;

        // Traverse the adjacency list to find the edge to remove
        while (current != nullptr && current->getDestination() != to) {
            prev = current;
            current = current->get_next();
        }

        // If the edge is not found, throw an exception
        if (current == nullptr) {
            throw std::runtime_error("Edge not found");
        }

        // Remove the edge
        if (prev == nullptr) {
            adjacency_list[from] = current->get_next();  // Remove first edge
        } else {
            prev->set_next(current->get_next());  // Remove edge from the middle or end
        }

        delete current;  // Free memory for the removed edge
    }

    // Helper function to check if there is an edge between 'from' and 'to'
    bool Graph::has_edge(int from, int to) const {
        Edge* current = adjacency_list[from];
        while (current != nullptr) {
            if (current->getDestination() == to) {
                return true;
            }
            current = current->get_next();
        }
        return false;
    }

    // Print the adjacency list of the graph
    void Graph::print_graph() const {
        for (int i = 0; i < num_vertices; ++i) {
            std::cout << "Vertex " << i << ": ";
            Edge* current = adjacency_list[i];
            while (current != nullptr) {
                std::cout << "(" << current->getDestination() << ", " << current->getWeight() << ") ";
                current = current->get_next();
            }
            std::cout << std::endl;
        }
    }
}
