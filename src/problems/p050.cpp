#include "../problems.hpp"
#include "../utils.hpp"

int solve_p050() {
	int n = 1000000;
	
	std::vector<int> primes;
	sieve_of_eratosthenes(n, primes);
	int size = primes.size();

	int longest = 0;
	int ans = 0;

	// Pick a starting point
	for (int start = 0; start < size; ++start) {

		int sum = primes[start];
	
		int offset = 1;
		while ((sum < n) && (start + offset < size)) {
			sum += primes[start + offset];

			if (sum > n) { break; }

			if (is_prime(sum)) {
				if (offset > longest) {
					longest = offset;
					ans = sum;
				}
			}

			++offset;
		}
	}

	return ans;
}