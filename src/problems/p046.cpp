#include "../problems.hpp"
#include "../utils.hpp"

int solve_p046() {
	// next_prime() gets the next prime
	std::vector<int> primes = { next_prime(1) };

	int n = 7; // Starting just before a non-composite odd
	while (true) {

		// Find the next odd composite (!even && !prime)
		n = next_odd_comp(n);

		// Ensure we have enough primes
		while (primes.back() < n) {
			primes.push_back(next_prime(primes.back()));
		}

		// Looking for this: n = p_x + 2(a^2)

		// Loop over all relevant primes: (n > p_x && p_x in primes)
		bool found = false;
		int x = 0;
		while (primes[x] < n && x < primes.size()) {
			int p_x = primes[x];

			// Try and fit 2(a^2)
			int a = 0;
			int guess = p_x + 2 * (a * a);
			while (guess < n) {
				++a;
				guess = p_x + 2 * (a * a);
			}

			// If we can, make note of it
			if (guess == n) {
				found = true;
				break;
			}

			++x;
		}

		// A fit wasn't found, this is the answer
		if (!found) {
			return n;
		}
	}

	return -1;
}