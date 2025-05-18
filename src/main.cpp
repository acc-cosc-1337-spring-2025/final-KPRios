#include <iostream>
#include <cassert>
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include <cstdlib>     
#include <ctime> 

int main() {
    srand(time(0)); 

    die die1, die2;
    shooter shooter;
    roll* roll = shooter.throw_dice(die1, die2);

    int rolled_value = roll->result();
    ComeOutPhase come_out_phase;

    while (true) {
        RollOutcome outcome = come_out_phase.get_outcome(roll);

        if (outcome == RollOutcome::natural || outcome == RollOutcome::craps) {
            std::cout << "Rolled " << roll->result() << " roll again\n";
            roll = shooter.throw_dice(die1, die2);
        } else {
            break;
        }
    }

    rolled_value = roll->result();
    std::cout << "Rolled " << rolled_value << " start of point phase\n";
    std::cout << "Roll until " << rolled_value << " or a 7 is rolled\n";

    int point = rolled_value;
    roll = shooter.throw_dice(die1, die2);

    PointPhase point_phase(point);

    while (true) {
        RollOutcome outcome = point_phase.get_outcome(roll);
        rolled_value = roll->result();

        if (outcome == RollOutcome::point || outcome == RollOutcome::nopoint) {
            std::cout << "Rolled " << rolled_value << " roll again\n";
            roll = shooter.throw_dice(die1, die2);
        } else {
            break;
        }
    }

    std::cout << "Rolled " << roll->result() << " end of point phase\n\n";

    shooter.display_rolled_values();

    return 0;
}