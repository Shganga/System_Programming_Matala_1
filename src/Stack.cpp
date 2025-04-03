// yanivg1000@gmail.com
#include "Stack.hpp"
#include <iostream>

// Constructor to initialize the stack with a given size.
Stack::Stack(int size) {
    capacity = size;
    data = new int[capacity];
    top = -1;
}

// Destructor to free dynamically allocated memory for the stack.
Stack::~Stack() {
    delete[] data;
}

// Function to push a value onto the stack.
void Stack::push(int value) {
    if (top < capacity - 1) {
        data[++top] = value;
    } else {
        std::cout << "Stack overflow\n";
    }
}

// Function to pop (remove and return) the top value from the stack.
int Stack::pop() {
    if (top >= 0) {
        return data[top--];
    } else {
        std::cout << "Stack underflow\n";
        return -1;
    }
}

// Function to check if the stack is empty.
bool Stack::empty() const {
    return top == -1;
}

// Function to peek at the top value of the stack without removing it.
int Stack::peek() const {
    if (top >= 0) {
        return data[top];
    } else {
        std::cout << "Stack is empty\n";
        return -1;
    }
}
