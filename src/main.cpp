#include <iostream>
#include <cassert>
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

void test_come_out_phase() {
    ComeOutPhase come_out;

    int natural_vals[] = {7, 11};
    int craps_vals[] = {2, 3, 12};
    int point_vals[] = {4, 5, 6, 8, 9, 10};

    for (int val : natural_vals) {
        roll* r = new roll(val);  // test constructor: Roll(int value)
        assert(come_out.get_outcome(r) == RollOutcome::natural);
        delete r;
    }

    for (int val : craps_vals) {
        roll* r = new roll(val);
        assert(come_out.get_outcome(r) == RollOutcome::craps);
        delete r;
    }

    for (int val : point_vals) {
        roll* r = new roll(val);
        assert(come_out.get_outcome(r) == RollOutcome::point);
        delete r;
    }
}

void test_point_phase() {
    PointPhase phase(5);

    roll* r1 = new roll(5);  // should be point
    assert(phase.get_outcome(r1) == RollOutcome::point);
    delete r1;

    roll* r2 = new roll(7);  // should be seven_out
    assert(phase.get_outcome(r2) == RollOutcome::seven_out);
    delete r2;

    roll* r3 = new roll(9);  // should be nopoint
    assert(phase.get_outcome(r3) == RollOutcome::nopoint);
    delete r3;
}

int main() {
    test_come_out_phase();
    test_point_phase();
    std::cout << "All phase tests passed!" << std::endl;
    return 0;
}