#include "../problems.hpp"
#include "../utils.hpp"

int solve_p027() {
	
	int longest = 0;
	int prod;

	for (int a = -999; a <= 999; ++a) {
		for (int b = -1000; b <= 1000; ++b) {
			int n = 0;
			long long x = (n * n) + (a * n) + b;

			while (is_prime(x)) {
				++n;
				x = (n * n) + (a * n) + b;
			}

			// The largest n == the largest sequence of primes
			if (n > longest) {
				longest = n;
				prod = a * b;
			}
		}
	}

	return prod;
}