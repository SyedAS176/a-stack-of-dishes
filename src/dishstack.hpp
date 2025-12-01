#pragma once

#include <iostream>

template <typename T>
class Stack {
private:
    static const int MAX_SIZE = 100;
    T stack[MAX_SIZE];
    int top_index;

public:
    Stack() : top_index(-1) {}

    void push(T item) {
        if (top_index >= MAX_SIZE - 1) {
            std::cout << "Stack is full! Cannot push." << std::endl;
            return;
        }
        stack[++top_index] = item;
    }


    T pop() {
        if (top_index < 0) {
            std::cout << "Stack is empty! Cannot pop." << std::endl;
            return T(); // Default constructor
        }
        return stack[top_index--];
    }

    T peek() {
        if (top_index < 0) {
            std::cout << "Stack is empty! Nothing to peek." << std::endl;
            return T();
        }
        return stack[top_index];
    }

    int size() {
        return top_index + 1;
    }

    void clear() {
        top_index = -1;
    }
};