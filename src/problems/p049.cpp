#include "../problems.hpp"
#include "../utils.hpp"

std::string solve_p049() {
	std::vector<int> primes = { next_prime(1000) };
	while (primes.back() < 9999) {
		primes.push_back(next_prime(primes.back()));
	}


	int size = primes.size();

	// Starting position
	for (int start = 0; start < size; ++start) {

		// Offset
		for (int offset = start + 1; offset < size - 1; ++offset) {

			// Calculate difference
			int n1 = primes[start];
			int diff = primes[offset] - n1;

			int n2 = n1 + diff;
			int n3 = n2 + diff;


			if (n1 == 1487) { continue; }
			if (n2 > 9999 || n3 > 9999) { continue; }

			std::string s1 = std::to_string(n1), s2 = std::to_string(n2), s3 = std::to_string(n3);

			if (std::is_permutation(s1.begin(), s1.end(), s2.begin()) && std::is_permutation(s2.begin(), s2.end(), s3.begin())) {

				if (is_prime(n2) && is_prime(n3)) {
					return s1 + s2 + s3;
				}
			}
		}
	}

	return "-1";
}