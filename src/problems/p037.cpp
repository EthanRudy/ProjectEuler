#include "../problems.hpp"
#include "../utils.hpp"

int solve_p037() {

	// Generate a sizeable amount
	// I don't see the need to implement a "next_prime()" function just yet
	std::vector<int> primes;
	sieve_of_eratosthenes(1000000, primes);
	
	// Get rid of the trivials: 2 3 5 7

	int sum = 0;
	int count = 0;

	int i = 4;
	while (count < 11) {
		bool truncatable = true;

		// Truncate left <- right (easy)
		int lr = primes[i] / 10;
		while (lr > 0) {
			if (std::find(primes.begin(), primes.end(), lr) == primes.end()) {
				truncatable = false;
				break;
			}

			lr /= 10;
		}

		// Truncate right -> left (harder cuz strings)
		std::string rl = std::to_string(primes[i]).substr(1);
		while (rl != "" && truncatable) {
			if (std::find(primes.begin(), primes.end(), std::stoi(rl)) == primes.end()) {
				truncatable = false;
				break;
			}

			rl = rl.substr(1);

		}

		if (truncatable) {
			sum += primes[i];
			++count;
			std::cout << count << ": " << primes[i] << " -> " << sum << "\n";
		}

		++i;
	}

	return sum;
}