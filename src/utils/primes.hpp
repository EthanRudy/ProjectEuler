#pragma once
#include <vector>

inline bool is_prime(int n) {
	if (n == 2) { return true; }
	if (n % 2 == 0) { return false; }

	int max = std::sqrt(n) + 1;

	for (int i = 2; i < max; ++i) {
		if (n % i == 0) { return false; }
	}

	return true;

}

inline void sieve_of_eratosthenes(int max, std::vector<int>& primes) {
	// Init bool array
	bool* prime_arr = (bool*)malloc((max + 1) * sizeof(bool));
	prime_arr[0] = false;	// Set 0 to non-prime
	prime_arr[1] = false;	// Set 1 to non-prime

	for (int n = 2; n < max; ++n) {
		// n is prime, eliminate the factors
		if (prime_arr[n]) {
			for (int m = n + n; m <= max; m += n) {
				prime_arr[m] = false;
			}
		}
	}

	for (int i = 2; i <= max; ++i) {
		if (prime_arr[i] != 0) {
			primes.push_back(i);
		}
	}
}