#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/dish.hpp"
#include "../src/dishstack.cpp"

TEST_CASE("Initial stack is empty") {
    Stack<Dish> stack;
    REQUIRE(stack.size() == 0);
    REQUIRE(stack.peek().get_description() == "");
}

TEST_CASE("Push dishes onto the stack") {
    Stack<Dish> stack;
    Dish one("One fish");
    Dish two("Two fish");

    stack.push(one);
    stack.push(two);

    REQUIRE(stack.size() == 2);
    REQUIRE(stack.peek().get_description() == "Two fish");
}

TEST_CASE("Pop dishes from the stack") {
    Stack<Dish> stack;
    Dish red("Red fish");
    Dish blue("Blue fish");

    stack.push(red);
    stack.push(blue);

    REQUIRE(stack.size() == 2);

    Dish popped = stack.pop();
    REQUIRE(popped.get_description() == "Blue fish");
    REQUIRE(stack.size() == 1);

    Dish another_popped = stack.pop();
    REQUIRE(another_popped.get_description() == "Red fish");
    REQUIRE(stack.size() == 0);

    // Popping empty stack
    Dish empty_pop = stack.pop();
    REQUIRE(empty_pop.get_description() == "");
}

TEST_CASE("Stack overflow") {
    Stack<Dish> stack;

    for (int i = 0; i < 100; i++) {
        stack.push(Dish("Dish " + std::to_string(i)));
    }

    REQUIRE(stack.size() == 100);

    stack.push(Dish("Overflow dish"));
    REQUIRE(stack.size() == 100);
    REQUIRE(stack.peek().get_description() == "Dish 99");
}

TEST_CASE("Clear stack") {
    Stack<Dish> stack;
    stack.push(Dish("One fish"));
    stack.push(Dish("Two fish"));
    REQUIRE(stack.size() == 2);

    stack.clear();
    REQUIRE(stack.size() == 0);
    REQUIRE(stack.peek().get_description() == "");
}