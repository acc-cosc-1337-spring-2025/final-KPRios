//
#ifndef POINT_PHASE_H
#define POINT_PHASE_H

#include "phase.h"

class PointPhase : public Phase {
public:
    PointPhase(int p) : point(p) {}
    RollOutcome get_outcome(roll* roll) override;

private:
    int point;
};

#endif