//yanivg1000@gmail.com
#include "Stack.hpp"
#include <iostream>

Stack::Stack(int size) {
    capacity = size;
    data = new int[capacity];
    top = -1;
}

Stack::~Stack() {
    delete[] data;
}

void Stack::push(int value) {
    if (top < capacity - 1) {
        data[++top] = value;
    } else {
        std::cout << "Stack overflow\n";
    }
}

int Stack::pop() {
    if (top >= 0) {
        return data[top--];
    } else {
        std::cout << "Stack underflow\n";
        return -1;
    }
}

bool Stack::empty() const {
    return top == -1;
}

int Stack::peek() const {
    if (top >= 0) {
        return data[top];
    } else {
        std::cout << "Stack is empty\n";
        return -1;
    }
}
