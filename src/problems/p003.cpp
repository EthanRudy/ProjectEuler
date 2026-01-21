#include "../problems.hpp"
#include "../utils.hpp"

int solve_p003() {
	long long n = 600851475143;
	int max = std::sqrt(n);

	// Ensure we're odd
	if (max % 2 == 0) { max += 1; }
	
	while (max > 0) {
		// If max is not a factor of n, continue
		if (n % max != 0) {
			max -= 2;
			continue;
		}

		// Answer found
		if (is_prime(max)) {
			return max;
		}
	
		max -= 2;
	}

	return -1;
}

