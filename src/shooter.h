//
#ifndef SHOOTER_H
#define SHOOTER_H

#include <vector>
#include "roll.h"  // Ensure this includes class Roll with roll_dice and result()

class shooter {
public:
    roll* throw_dice(die& die1, die& die2);
    void display_rolled_values();
    ~shooter();

private:
    std::vector<roll*> rolls;
};

#endif