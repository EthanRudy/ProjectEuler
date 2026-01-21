#include "../problems.hpp"
#include "../utils.hpp"

unsigned long long solve_p010() {
	std::vector<int> primes;
	sieve_of_eratosthenes(2000000, primes);

	unsigned long long sum = 0;
	for (int n : primes) {
		sum += n;
	}

	return sum;
}

// 1179908154