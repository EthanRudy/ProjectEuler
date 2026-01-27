#include "../problems.hpp"
#include "../utils.hpp"

int solve_p030() {

	int total = 0;

	// Don't really know a max on this one
	for (int i = 2; i < 1000000; ++i) {
		int n = i;
		int sum = 0;
		while (n > 0) {
			div_t d = div(n, 10);
			sum += pow(d.rem, 5);
			n = d.quot;
		}

		if (sum == i) {
			std::cout << i << "\n";
			total += i;
		}
	}

	return total;
}