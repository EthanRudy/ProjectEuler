#include "../problems.hpp"
#include "../utils.hpp"

std::string solve_p048() {
	big::Integer sum = 0;

	// Cuz I can lol
	for (int n = 1; n <= 1000; ++n) {
		sum += big::pow(n, n);
	}

	std::string str = big::to_string(sum);

	return str.substr(str.length() - 10);
}