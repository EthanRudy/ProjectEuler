#include "../problems.hpp"
#include "../utils.hpp"

int solve_p034() {
	int sum = 0;

	int MAX = 7 * factorial(9);

	for (int i = 3; i < MAX; ++i) {
		if (f_digit_sum(i) == i) {
			sum += i;
		}
	}

	return sum;
}