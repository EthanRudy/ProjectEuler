#include "../problems.hpp"

int solve_p009() {

	for (int a = 1; a < 999; ++a) {
		for (int b = 1; b < (999 - a); ++b) {
			int c = 1000 - a - b;

			if (a * a + b * b == c * c) {
				return a * b * c;
			}
		}
	}

	return -1;
}