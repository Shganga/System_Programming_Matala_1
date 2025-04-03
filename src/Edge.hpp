//yanivg1000@gmail.com
#ifndef EDGE_HPP
#define EDGE_HPP

class Edge {
private:
    int source; 
    int destination;  // The destination vertex of the edge
    int weight;       // The weight of the edge
    Edge* next;       // Pointer to the next edge (for linked list)

public:
    Edge(int dest, int w);  // Constructor to initialize destination and weight
    Edge(int src, int dest, int w); 


    int getSource() const; 
    int getDestination() const;  // Getter for destination
    int getWeight() const;       // Getter for weight
    Edge* get_next() const;      // Getter for the next edge
    void set_next(Edge* next_edge);  // Setter for next edge
};

#endif // EDGE_HPP
