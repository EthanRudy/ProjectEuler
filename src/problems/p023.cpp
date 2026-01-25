#include "../problems.hpp"
#include "../utils.hpp"

#include <set>

int solve_p023() {

	// Generate abundant numbers
	std::vector<int> abundants;
	for (int i = 0; i <= 28123; ++i) {
		if (abundant(i)) {
			abundants.push_back(i);
		}
	}

	// trauma
	std::vector<bool> sums(28124, false);
	for (int a = 0; a < abundants.size(); ++a) {
		for (int b = a; b < abundants.size(); ++b) {
			int sum = abundants[a] + abundants[b];
			if (sum < 28123) {
				sums[sum] = true;
			}
		}
	}

	int total = 0;
	for (int i = 1; i < 28123; ++i) {
		if (sums[i] == false) {
			total += i;
		}
	}

	return total;
}