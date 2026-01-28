#include "../problems.hpp"
#include "../utils.hpp"

unsigned long long solve_p043() {

	std::vector<int> divisors;
	sieve_of_eratosthenes(18, divisors);

	unsigned long long sum = 0;

	// Create first string
	std::string str = "";
	for (int i = 0; i < 10; ++i) {
		str += (i + '0');
	}

	do {
		if (str[0] == '0') { continue; }

		bool valid = true;
		int s_i = 1;
		for (int d : divisors) {

			int num = (str[s_i] - '0') * 100
					+ (str[s_i + 1] - '0') * 10
					+ (str[s_i + 2] - '0');

			if (num % d != 0) {
				valid = false;
				break;
			}

			++s_i;
		}

		if (valid) {
			std::cout << str << "\n";
			sum += std::stoll(str);
		}

	} while (std::next_permutation(str.begin(), str.end()));

	return sum;
}