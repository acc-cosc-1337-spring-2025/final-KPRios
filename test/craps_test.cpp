#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

TEST_CASE("die rolls are within the range 1 to 6", "[die]") {
 die die;

    for (int i = 0; i < 10; ++i) {
        int roll_result = die.roll();
        REQUIRE(roll_result >= 1);
        REQUIRE(roll_result <= 6);
    }
}
