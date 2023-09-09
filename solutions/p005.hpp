#include "../include/Timer.hpp"

#include <iostream>

void problem005() {
	precise_timer timer;

	int num = 20;
	for (;; num += 20) {
		bool found = true;
		
		int factors = 20;
		while (factors > 0) {
			if (num % factors != 0) {
				found = false;
				break;
			}
			--factors;
		}

		if (found) { break; }
	}

	int duration = timer.get_duration<int, std::chrono::milliseconds>();
	std::cout << "Solution: " << num << "\n";
	std::cout << "Solution found in " << duration << " milliseconds";
	// Avg runtime: 34 milliseconds
}