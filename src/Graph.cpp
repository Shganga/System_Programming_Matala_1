// yanivg1000@gmail.com
#include "Graph.hpp"
#include "Edge.hpp"
#include <stdexcept>
#include <iostream>

namespace graph {

    // Constructor to initialize the graph with a given number of vertices
    Graph::Graph(int vertices) : num_vertices(vertices) {
        adjacency_list = new Edge*[num_vertices];
        for (int i = 0; i < num_vertices; ++i) {
            adjacency_list[i] = nullptr;  // Initialize all adjacency lists as null
        }
    }

    // Destructor to clean up dynamically allocated memory
    Graph::~Graph() {
        for (int i = 0; i < num_vertices; ++i) {
            Edge* current = adjacency_list[i];
            while (current != nullptr) {
                Edge* next_edge = current->get_next();
                delete current;  // Delete current edge
                current = next_edge;  // Move to next edge
            }
        }
        delete[] adjacency_list;  // Delete the adjacency list array
    }

    // Add an undirected edge to the graph with the given vertices and weight
    void Graph::add_edge(int from, int to, int weight) {
        if (from < 0 || to < 0 || from >= num_vertices || to >= num_vertices) {
            throw std::out_of_range("Invalid vertex index.");
        }

        // Add edge from 'from' to 'to'
        Edge* new_edge_from = new Edge(to, weight);
        new_edge_from->set_next(adjacency_list[from]);
        adjacency_list[from] = new_edge_from;  // Add the new edge to the adjacency list of 'from'

        // Add edge from 'to' to 'from' (reverse edge)
        Edge* new_edge_to = new Edge(from, weight);
        new_edge_to->set_next(adjacency_list[to]);
        adjacency_list[to] = new_edge_to;  // Add the new edge to the adjacency list of 'to'
    }

    // Add a one-way edge to the graph with the given vertices and weight
    void Graph::add_one_edge(int from, int to, int weight) {
        if (from < 0 || to < 0 || from >= num_vertices || to >= num_vertices) {
            throw std::out_of_range("Invalid vertex index.");
        }

        // Add one-way edge from 'to' to 'from'
        Edge* new_edge_to = new Edge(from, weight);
        new_edge_to->set_next(adjacency_list[to]);
        adjacency_list[to] = new_edge_to;
    }

    // Remove an undirected edge between the specified vertices
    void Graph::remove_edge(int from, int to) {
        if (from < 0 || to < 0 || from >= num_vertices || to >= num_vertices) {
            throw std::out_of_range("Invalid vertex index.");
        }

        remove_edge_helper(from, to);  // Remove the edge from 'from' to 'to'
        remove_edge_helper(to, from);  // Remove the reverse edge from 'to' to 'from'
    }

    // Helper function to remove a specific edge from the adjacency list
    void Graph::remove_edge_helper(int from, int to) {
        Edge* current = adjacency_list[from];
        Edge* prev = nullptr;

        while (current != nullptr) {
            if (current->getDestination() == to) {
                if (prev == nullptr) {
                    adjacency_list[from] = current->get_next();  // Update head of the list
                } else {
                    prev->set_next(current->get_next());  // Remove current edge from the list
                }
                delete current;  // Delete the edge
                return;
            }
            prev = current;
            current = current->get_next();
        }
    }

    // Print the graph (for debugging purposes)
    void Graph::print_graph() const {
        for (int i = 0; i < num_vertices; ++i) {
            std::cout << "Vertex " << i << ": ";
            Edge* current = adjacency_list[i];
            while (current != nullptr) {
                std::cout << "-> (" << i << ", " << current->getDestination() << ", " << current->getWeight() << ")";
                current = current->get_next();
            }
            std::cout << std::endl;
        }
    }

    // Check if an edge exists between two specified vertices
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

    // Get the number of vertices in the graph
    int Graph::get_num_vertices() const {
        return num_vertices;
    }

    // Get the list of adjacent vertices for a given vertex
    int* Graph::get_adjacent_vertices(int vertex) const {
        Edge* current = adjacency_list[vertex];
        int* adj_array = new int[num_vertices];  // Dynamically allocate an array
        int index = 0;
    
        // Traverse the adjacency list for the vertex
        while (current != nullptr) {
            adj_array[index++] = current->getDestination();
            current = current->get_next();
        }
    
        adj_array[index] = -1;  // Mark the end of the array
        return adj_array;  // Return the array of adjacent vertices
    }

    // Get the weight of the edge between two specified vertices
    int Graph::get_edge_weight(int from, int to) const {
        Edge* current = adjacency_list[from];
        while (current != nullptr) {
            if (current->getDestination() == to) {
                return current->getWeight();
            }
            current = current->get_next();
        }
        return -1;  // Return -1 if no edge exists between the vertices
    }

}
