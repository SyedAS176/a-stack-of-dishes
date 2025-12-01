#pragma once

#include "Dish.hpp"
#include <iostream>

class DishStack {
private:
    static const int MAX_SIZE = 100;
    Dish stack[MAX_SIZE];
    int top_index;

public:
    DishStack();
    void push(Dish dish);
    Dish pop();
    Dish peek();
    int size();
};