#include "../problems.hpp"
#include "../utils.hpp"


long long solve_p015() {

	std::vector<std::vector<long long>> pascals = { { 1 } };

	// Pascals triangle! Don't ask how I know but I remember from the last time
	// We need 40 instead of 20 too
	for (int i = 0; i < 40; ++i) {
		std::vector<long long> row(2, 1);
		for (int prev_row = 0; prev_row < pascals[i].size() - 1; ++prev_row) {
			row.insert(row.end() - 1, pascals[i][prev_row] + pascals[i][prev_row + 1]);
		}
		pascals.push_back(row);
	}

	return pascals[40][20];
}