#include "../include/Timer.hpp"
#include "../include/BigInt.hpp"

#include <iostream>

void problem013() {
	precise_timer timer;

	BigInt sum = 0;

	std::ifstream file("./inputs/p013.txt");
	std::string line;
	while (std::getline(file, line)) {
		sum += line;
	}

	std::string res = sum.toString().substr(0, 10);


	int duration = timer.get_duration<int, std::chrono::milliseconds>();
	std::cout << "Solution: " << res << "\n";
	std::cout << "Solution found in " << duration << " milliseconds";
	// Avg runtime: 1 millisecond
}
