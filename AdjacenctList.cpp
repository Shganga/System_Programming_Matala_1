#include "AdjacencyList.hpp"
#include <iostream>

// Constructor: Initialize the adjacency list with the specified number of vertices
AdjacencyList::AdjacencyList(int numberOfVertices)
{
    this->numberOfVertices = numberOfVertices;
    vertices = new Node*[numberOfVertices];  // Array of pointers to nodes

    // Initialize all adjacency lists to nullptr
    for (int i = 0; i < numberOfVertices; ++i)
    {
        vertices[i] = nullptr;
    }
}

// Destructor: Clean up memory by deleting the adjacency list nodes
AdjacencyList::~AdjacencyList()
{
    for (int i = 0; i < numberOfVertices; ++i)
    {
        Node* current = vertices[i];
        while (current != nullptr)
        {
            Node* temp = current;
            current = current->get_next();
            delete temp;  // Free memory
        }
    }

    delete[] vertices;  
}

// Add an edge from vertex 'from' to vertex 'to'
void AdjacencyList::add_edge(int from, int to)
{
    Node* newNode = new Node(to);  // Create a new node for the 'to' vertex

    // Insert it at the beginning of the adjacency list for 'from'
    newNode->set_next(vertices[from]);
    vertices[from] = newNode;
}

// Print the adjacency list
void AdjacencyList::printAdjacencyList() const
{
    for (int i = 0; i < numberOfVertices; ++i)
    {
        std::cout << "Vertex " << i << ": ";
        Node* current = vertices[i];
        while (current != nullptr)
        {
            std::cout << current->get_value() << " ";
            current = current->get_next();
        }
        std::cout << std::endl;
    }
}
