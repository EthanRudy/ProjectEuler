#include "../problems.hpp"
#include "../utils.hpp"

int solve_p040() {
	

	// String thats 1 million long
	int n = 1;
	std::string frac = std::to_string(n);
	while (frac.length() < 1000000) {
		++n;
		frac += std::to_string(n);
	}

	int val = 1;
	for (int i = 0; i <= 6; ++i) {
		val *= (frac[std::pow(10, i) - 1] - '0');
	}

	return val;
}