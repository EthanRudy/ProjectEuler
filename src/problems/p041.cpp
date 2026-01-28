#include "../problems.hpp"
#include "../utils.hpp"

int solve_p041() {

	int digits = 9;
	int largest = 0;

	while (digits > 1) {

		std::string str = "";
		for (int i = 0; i < digits; ++i) {
			str += (i + 1) + '0';
		}

		do {
			int n = std::stoi(str);

			if (is_prime(n)) {
				largest = std::max(largest, n);
			}
			
		} while (std::next_permutation(str.begin(), str.end()));

		--digits;
	}


	return largest;
}