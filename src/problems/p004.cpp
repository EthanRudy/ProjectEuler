#include "../problems.hpp"
#include "../utils.hpp"

int solve_p004() {
	int largest = -1;
	int prod = 1;

	for (int i = 999; i > 99; --i) {
		for (int j = 999; j > 99; --j) {
			prod = i * j;
			if (is_palindrome(std::to_string(prod))) {
				if (prod > largest) {
					largest = prod;
				}
			}
		}
	}

	return largest;
}