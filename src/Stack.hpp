#ifndef STACK_HPP
#define STACK_HPP

class Stack {
private:
    int* data;
    int capacity;
    int top;

public:
    Stack(int size);
    ~Stack();

    void push(int value);
    int pop();
    bool empty() const;
    int peek() const;
};

#endif // STACK_HPP
