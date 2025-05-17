#include <iostream>
#include <cassert>
#include "die.h"

int main() {
	die die;

    for (int i = 0; i < 10; ++i) {
        int result = die.roll();
        std::cout << "Roll " << i + 1 << ": " << result << std::endl;
        assert(result >= 1 && result <= 6);  // Test case: roll should always be between 1 and 6
    }

    std::cout << "All die rolls are within range 1-6." << std::endl;
	
	return 0;
}