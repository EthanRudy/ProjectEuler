#include "../problems.hpp"
#include "../utils.hpp"

int solve_p020() {
	big::Integer num = big::factorial(100);

	std::string str = big::to_string(num);

	int sum = 0;
	for (char c : str) {
		sum += (c - '0');
	}

	return sum;
}