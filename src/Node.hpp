#ifndef NODE_HPP
#define NODE_HPP

class Node
{
    private:
        int value;    // The value the node holds
        Node* next;   // Pointer to the next node in the list

    public:
        // Constructor
        Node(int val);

        // Destructor
        ~Node();

        // Getter for the value
        int get_value() const;

        // Getter for the next node
        Node* get_next() const;

        // Setter for the next node
        void set_next(Node* nextNode);
};

#endif // NODE_HPP
