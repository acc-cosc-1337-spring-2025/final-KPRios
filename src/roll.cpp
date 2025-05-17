//
#include "roll.h"

roll::roll(die& d1, die& d2)
    : die1(d1), die2(d2), rolled_value(0) {}

void roll::roll_dice() {
    int d1_value = die1.roll();
    int d2_value = die2.roll();
    rolled_value = d1_value + d2_value;
}

int roll::roll_value() const {
    return rolled_value;
}