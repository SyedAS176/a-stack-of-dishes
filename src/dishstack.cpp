#include "dishstack.hpp"

DishStack::DishStack() {
    top_index = -1;
}

void DishStack::push(Dish dish) {
    if (top_index >= MAX_SIZE - 1) {
        std::cout << "Stack is full! Cannot push." << std::endl;
        return;
    }
    top_index++;
    stack[top_index] = dish;
}

Dish DishStack::pop() {
    if (top_index < 0) {
        std::cout << "Stack is empty! Cannot pop." << std::endl;
        return Dish("");
    }
    return stack[top_index--];
}

Dish DishStack::peek() {
    if (top_index < 0) {
        std::cout << "Stack is empty! Nothing to peek." << std::endl;
        return Dish("");
    }
    return stack[top_index];
}

int DishStack::size() {
    return top_index + 1;
}