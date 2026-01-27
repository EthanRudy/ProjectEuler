#include "../problems.hpp"
#include "../utils.hpp"

int solve_p028() {

	int diff = 2;

	int sum = 1;
	int n = 1;
	while (diff < 1002) {
		for (int i = 0; i < 4; ++i) {
			n += diff;
			sum += n;
		}

		diff += 2;
	}

	return sum;
}