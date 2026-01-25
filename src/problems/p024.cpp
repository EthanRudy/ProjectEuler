#include "../problems.hpp"
#include "../utils.hpp"

std::string solve_p024() {
	std::string str = "0123456789";

	int target = 1000000;
	while (--target) {
		std::next_permutation(str.begin(), str.end());
	}

	return str;
}

// Wrong: 2783915604
// Wrong: 2783915640