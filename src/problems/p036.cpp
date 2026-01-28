#include "../problems.hpp"
#include "../utils.hpp"

int solve_p036() {

	int sum = 0;

	for (int n = 0; n < 1000000; ++n) {

		// Ensure n is a palindrome
		if (is_palindrome(std::to_string(n))) {

			// Convert to binary string
			std::string bin = bin_str(n);

			if (is_palindrome(bin)) {
				sum += n;
			}
		}
	}

	return sum;
}