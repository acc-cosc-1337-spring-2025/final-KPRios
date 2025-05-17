//
#include "point_phase.h"

RollOutcome PointPhase::get_outcome(roll* roll) {
    int value = roll -> result();
    if (value == point) {
        return RollOutcome::point;
    } else if (value == 7) {
        return RollOutcome::seven_out;
    } else {
        return RollOutcome::nopoint;
    }
}