#include "../problems.hpp"
#include "../utils.hpp"

int solve_p018() {
	std::vector<std::vector<int>> pyramid;

	// Okay this wasn't on purpose but because we're using variable size data structures I can use the grid code lol
	load_grid("./src/inputs/p018.txt", pyramid);

	// Flip it upside down
	std::reverse(pyramid.begin(), pyramid.end());

	// Instead of the inefficient top down (as mentioned in problem 067) we go bottom up, hence the flip
	// Converging paths vs diverging paths
	// 15 rows btw

	for (int y = 1; y < 15; ++y) {
		for (int x = 0; x < pyramid[y].size(); ++x) {
			pyramid[y][x] += std::max(pyramid[y - 1][x], pyramid[y - 1][x + 1]);
		}
	}

	int ans = pyramid[14][0];

	return ans;

}