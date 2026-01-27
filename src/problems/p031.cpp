#include "../problems.hpp"
#include "../utils.hpp"

int solve_p031() {
	int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200 };

	// Starting at 1p, we can only make one way
	std::vector<int> ways(200, 0);
	ways.insert(ways.begin(), 1);

	// Loop over all coins
	for (int c : coins) {

		// From coin value -> target
		for (int i = c; i <= 200; ++i) {
			// Add ways
			ways[i] += ways[i - c];
		}
	}

	return ways[200];
}