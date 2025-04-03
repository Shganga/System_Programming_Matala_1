//yanivg1000@gmail.com
#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

class PriorityQueue {
public:
    PriorityQueue(int size);
    ~PriorityQueue();
    
    void enqueue(int value, int priority);  // Add value with priority to the queue
    int dequeue();  // Remove and return the element with the highest priority
    bool is_empty() const;  // Check if the queue is empty
    void decrease_key(int value, int new_priority);
    bool contains(int value) const;

private:
    struct Element {
        int value;
        int priority;
    };

    Element* arr;  // Array of elements in the queue
    int front;  // Index of the front element
    int rear;   // Index of the last element
    int capacity;  // Maximum size of the queue



    void heapify_up(int index);
    void heapify_down(int index);
};

const int INF = 1000000;  // Define a large value as "infinity" for Dijkstra

#endif
