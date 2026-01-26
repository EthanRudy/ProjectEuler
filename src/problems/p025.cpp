#include "../problems.hpp"
#include "../utils.hpp"

int solve_p025() {
	big::Integer a = 1;
	big::Integer b = 1;

	big::Integer c = 1;
	int index = 2;
	while (big::to_string(c).length() < 1000) {
		c = a + b;
		a = b;
		b = c;
		++index;
	}

	return index;
}

// Wrong: 4783