#include "../problems.hpp"

int solve_p002() {
	int a = 1, b = 2, c = 0;
	int sum = 2; // Including b already

	while (c < 4000000) {
		c = a + b;

		if (c % 2 == 0) { sum += c; }

		a = b;
		b = c;
	}

	return sum;
}