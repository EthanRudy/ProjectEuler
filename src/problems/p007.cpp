#include "../problems.hpp"
#include "../utils.hpp"

int solve_p007() {
	int count = 1; // Starting at 2 :)

	int n = 3;
	while (true) {
		if (is_prime(n)) {
			++count;
		}
		if (count == 10001) {
			return n;
		}

		n += 2;
	}


	return -1;
}