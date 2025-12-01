#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/dishstack.cpp"

TEST_CASE("Initial stack is empty") {
    DishStack stack;
    REQUIRE(stack.size() == 0);

    Dish peeked = stack.peek();
    REQUIRE(peeked.get_description() == "");
}

TEST_CASE("Push dishes onto the stack") {
    DishStack stack;
    Dish one("One fish");
    Dish two("Two fish");

    stack.push(one);
    stack.push(two);

    REQUIRE(stack.size() == 2);

    Dish top = stack.peek();
    REQUIRE(top.get_description() == "Two fish");
}

TEST_CASE("Pop dishes from the stack") {
    DishStack stack;
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
    DishStack stack;

    // Fill the stack to MAX_SIZE
    for (int i = 0; i < 100; i++) {
        stack.push(Dish("Dish " + std::to_string(i)));
    }

    REQUIRE(stack.size() == 100);

    // Attempt to push beyond MAX_SIZE
    stack.push(Dish("Overflow dish"));
    REQUIRE(stack.size() == 100);

    // Top dish should still be the last valid one
    REQUIRE(stack.peek().get_description() == "Dish 99");
}

TEST_CASE("Peek on empty stack") {
    DishStack stack;
    Dish peeked = stack.peek();
    REQUIRE(peeked.get_description() == "");
}