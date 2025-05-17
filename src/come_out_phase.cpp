//
#include "come_out_phase.h"

RollOutcome ComeOutPhase::get_outcome(roll* roll) {
    int value = roll->result();
    if (value == 7 || value == 11) {
        return RollOutcome::natural;
    } else if (value == 2 || value == 3 || value == 12) {
        return RollOutcome::craps;
    } else {
        return RollOutcome::point;
    }
}