#include "src/dishstack.hpp"
#include <iostream>
using namespace std;

int main() {
  DishStack stack;

  Dish one_dish("A dish with one fish pattern on it");
  Dish two_dish("A dish with two fish patterns on it");
  Dish red_dish("A dish with a red fish pattern on it");
  Dish blue_dish("A dish with a blue fish pattern on it");

  // The output should equal zero.
  cout << "Initial stack size: " << stack.size() << endl;

  stack.push(one_dish);
  stack.push(two_dish);
  stack.push(red_dish);
  stack.push(blue_dish);

  // The output should equal four.
  cout << "Stack size after pushes: " << stack.size() << endl;

  // The output should have a description of "A dish with a blue fish pattern on it"
  Dish peeked_dish = stack.peek();
  cout << "Peeked dish: " << peeked_dish.get_description() << endl;

  // The output should have a description of "A dish with a blue fish pattern on it"
  Dish popped_dish = stack.pop();
  cout << "Popped dish: " << popped_dish.get_description() << endl;

  // The output should have a description of "A dish with a red fish pattern on it"
  Dish another_popped_dish = stack.pop();
  cout << "Another popped dish: " << another_popped_dish.get_description() << endl;

  // The output should equal two.
  cout << "Final stack size: " << stack.size() << endl;

  return 0;
}