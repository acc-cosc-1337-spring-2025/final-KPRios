//
#include "die.h"
#include <random>
#include <ctime>

int die::roll() {
    static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(1, sides);
    return dist(rng);
}