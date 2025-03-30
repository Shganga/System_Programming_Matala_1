#include "Queue.hpp"
#include <stdexcept>  // For overflow and underflow exceptions

Queue::Queue(int size) : arr(new Element[size]), front(-1), rear(-1), capacity(size) {}

Queue::~Queue() {
    delete[] arr;
}

// Helper function to maintain the heap property when adding an element
void Queue::heapify_up(int index) {
    while (index > 0 && arr[index].priority < arr[(index - 1) / 2].priority) {
        // Swap the elements
        Element temp = arr[index];
        arr[index] = arr[(index - 1) / 2];
        arr[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}

// Helper function to maintain the heap property when removing an element
void Queue::heapify_down(int index) {
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    int smallest = index;

    // Find the smallest among the current node, left child, and right child
    if (left_child <= rear && arr[left_child].priority < arr[smallest].priority) {
        smallest = left_child;
    }
    if (right_child <= rear && arr[right_child].priority < arr[smallest].priority) {
        smallest = right_child;
    }

    // If the smallest is not the current node, swap and continue heapifying down
    if (smallest != index) {
        Element temp = arr[index];
        arr[index] = arr[smallest];
        arr[smallest] = temp;
        heapify_down(smallest);
    }
}

void Queue::enqueue(int value, int priority) {
    if (rear == capacity - 1) {
        throw std::overflow_error("Queue is full");
    }

    // If it's the first element, set the front to 0
    if (front == -1) {
        front = 0;
    }

    // Increment rear and add the new element
    arr[++rear].value = value;
    arr[rear].priority = priority;

    // Maintain heap property by "heapifying up"
    heapify_up(rear);
}

int Queue::dequeue() {
    if (rear == -1) {  // The queue is empty
        throw std::underflow_error("Queue is empty");
    }

    // The element with the highest priority is at the front (index 0)
    int highest_priority_value = arr[0].value;

    // Move the last element to the front and decrease the rear
    arr[0] = arr[rear--];

    // Heapify the front element to restore heap property
    if (rear >= front) {
        heapify_down(0);
    }

    // If the queue is empty, reset the front and rear
    if (rear == -1) {
        front = -1;
    }

    return highest_priority_value;
}

bool Queue::is_empty() const {
    return rear == -1;  // The queue is empty if rear is -1
}
