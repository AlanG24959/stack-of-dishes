#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/Dish.h"
#include "../src/DishStack.hpp"

TEST_CASE("DishStack push, pop, peek, and size") {
    DishStack stack;

    Dish dish1("Glintstone Staff Plate");
    Dish dish2("Fire Giant Helmet Bowl");
    Dish dish3("Golden Seed Dish");

    SECTION("Initial stack is empty") {
        REQUIRE(stack.size() == 0);
    }

    SECTION("Push dishes increases size") {
        stack.push(dish1);
        REQUIRE(stack.size() == 1);

        stack.push(dish2);
        stack.push(dish3);
        REQUIRE(stack.size() == 3);
    }

    SECTION("Peek returns top without removing") {
        stack.push(dish1);
        stack.push(dish2);
        REQUIRE(stack.peek().get_description() == "Fire Giant Helmet Bowl");
        REQUIRE(stack.size() == 2);
    }

    SECTION("Pop returns top and decreases size") {
        stack.push(dish1);
        stack.push(dish2);
        stack.push(dish3);

        Dish popped = stack.pop();
        REQUIRE(popped.get_description() == "Golden Seed Dish");
        REQUIRE(stack.size() == 2);

        popped = stack.pop();
        REQUIRE(popped.get_description() == "Fire Giant Helmet Bowl");
        REQUIRE(stack.size() == 1);
    }

    SECTION("Pop or peek on empty stack returns 'No dish'") {
        Dish emptyPop = stack.pop();
        REQUIRE(emptyPop.get_description() == "No dish");

        Dish emptyPeek = stack.peek();
        REQUIRE(emptyPeek.get_description() == "No dish");
    }
}
