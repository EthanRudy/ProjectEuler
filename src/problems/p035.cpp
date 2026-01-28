#include "../problems.hpp"
#include "../utils.hpp"

int solve_p035() {
	// I think I have everything I already need for this!

	std::vector<int> primes;
	sieve_of_eratosthenes(1000000, primes);

	// Could optimize by putting already found primes in but it feels
	// overkill for the moment

	int count = 0;

	for (int p : primes) {
		bool circular = true;

		std::string str = std::to_string(p);
		std::string next = rotate(str);

		while (next != str) {
			
			if (!is_prime(std::stoi(next))) {
				circular = false;
				break;
			}

			next = rotate(next);
		}

		if (circular) {
			++count;
		}
	}

	return count;
}