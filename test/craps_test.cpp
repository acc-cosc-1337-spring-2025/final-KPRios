#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

TEST_CASE("Roll rolls two dice and returns values from 2 to 12", "[Roll]") {
    die die1;
    die die2;
    roll roll(die1, die2);

    for (int i = 0; i < 10; ++i) {
        roll.roll_dice();
        int value = roll.roll_value();
        REQUIRE(value >= 2);
        REQUIRE(value <= 12);
    }
}