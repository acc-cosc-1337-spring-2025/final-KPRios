#include <iostream>
#include <cassert>
#include "die.h"
#include "roll.h"
#include "shooter.h"

int main() {
    shooter shooter;
    die die1, die2;

    for (int i = 0; i < 10; ++i) {
        roll* roll = shooter.throw_dice(die1, die2);
        int result = roll->result();
        std::cout << "Test roll " << i + 1 << ": " << result << std::endl;
        assert(result >= 2 && result <= 12);
    }

    shooter.display_rolled_values();

    std::cout << "All rolls within valid range (2-12)." << std::endl;
    return 0;
}