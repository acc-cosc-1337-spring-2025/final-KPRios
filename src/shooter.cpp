//
#include "shooter.h"
#include <iostream>

roll* shooter::throw_dice(die& die1, die& die2) {
    roll* roll = new roll(die1, die2);
    roll->roll_dice();  
    rolls.push_back(roll);
    return roll;
}

void shooter::display_rolled_values() {
    for (auto roll : rolls) {
        std::cout << "roll result: " << roll->result() << std::endl;
    }
}

shooter::~shooter() {
    for (auto roll : rolls) {
        delete roll;
    }
    rolls.clear();
}