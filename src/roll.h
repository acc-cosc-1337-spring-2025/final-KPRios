//
#ifndef ROLL_H
#define ROLL_H

#include "die.h"

class roll {
public:
    roll(die& d1, die& d2);   
    void roll_dice();         
    int roll_value() const;   

private:
    die& die1;
    die& die2;
    int rolled_value;
};

#endif  // ROLL_H