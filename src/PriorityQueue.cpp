//yanivg1000@gmail.com
#include "PriorityQueue.hpp"
#include <stdexcept>  // For overflow and underflow exceptions

PriorityQueue::PriorityQueue(int size) : arr(new Element[size]), front(-1), rear(-1), capacity(size) {}

PriorityQueue::~PriorityQueue() {
    delete[] arr;
}

// Helper function to maintain the heap property when adding an element
void PriorityQueue::heapify_up(int index) {
    while (index > 0 && arr[index].priority < arr[(index - 1) / 2].priority) {
        // Swap the elements
        Element temp = arr[index];
        arr[index] = arr[(index - 1) / 2];
        arr[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}

// Helper function to maintain the heap property when removing an element
void PriorityQueue::heapify_down(int index) {
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

void PriorityQueue::enqueue(int value, int priority) {
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

int PriorityQueue::dequeue() {
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

bool PriorityQueue::is_empty() const {
    return rear == -1;  // The queue is empty if rear is -1
}

void PriorityQueue::decrease_key(int value, int new_priority) {
    // Find the index of the element with the given value
    int index = -1;
    for (int i = 0; i <= rear; ++i) {
        if (arr[i].value == value) {
            index = i;
            break;
        }
    }

    // If the element is not found, return
    if (index == -1) {
        throw std::invalid_argument("Value not found in the priority queue");
    }

    // If the new priority is not smaller, ignore the request
    if (new_priority >= arr[index].priority) {
        throw std::invalid_argument("New priority must be lower than current priority");
    }

    // Update the priority and maintain heap property
    arr[index].priority = new_priority;
    heapify_up(index);
}

bool PriorityQueue::contains(int value) const {
    for (int i = 0; i <= rear; ++i) {
        if (arr[i].value == value) {
            return true;
        }
    }
    return false;
}


