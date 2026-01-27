#include "../problems.hpp"
#include "../utils.hpp"

#include <set>

int solve_p032() {

	int MAX = 987654321;
	std::set<int> found;

	for (int a = 2; a < MAX; ++a) {
		// Start just past a, we don't want to repeat products
		int b = a + 1;


		int prod = (a * b);
		// If we start too big, just leave
		if (prod > MAX) { break;  }


		// While our product is less than 987654321
		while (prod <= MAX) {
			prod = a * b;

			// Concat values
			std::string str = std::to_string(a) + std::to_string(b) + std::to_string(prod);
			
			// Easy length check for time save
			if (str.length() > 9) { break; }

			// Check pandigital property
			if (is_pandigital(str)) {
				found.insert(prod);
			}

			++b;
		}
	}


	// Sum our unique products
	int sum = 0;
	for (int n : found) {
		sum += n;
	}

	return sum;
}