//yanivg1000@gmail.com
#ifndef EDGE_HPP
#define EDGE_HPP

class Edge {
private:
    int source; 
    int destination;  
    int weight;       
    Edge* next;       

public:
    Edge(int dest, int w);  
    Edge(int src, int dest, int w); 


    int getSource() const; 
    int getDestination() const;  
    int getWeight() const;       
    Edge* get_next() const;      
    void set_next(Edge* next_edge);  
};

#endif // EDGE_HPP
