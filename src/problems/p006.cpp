#include "../problems.hpp"

int solve_p006() {
	int sum_square = 0;
	int square_sum = 0;

	for (int i = 1; i <= 100; ++i) {
		sum_square += (i * i);
		square_sum += i;
	}

	square_sum *= square_sum;

	return std::abs(sum_square - square_sum);
}