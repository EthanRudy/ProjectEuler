#include "../problems.hpp"
#include "../utils.hpp"

int solve_p022() {
	std::vector<std::string> names;
	load_names("./src/inputs/p022.txt", names);

	std::sort(names.begin(), names.end());

	int total = 0;
	for (int i = 0; i < names.size(); ++i) {
		int score = 0;

		for (char c : names[i]) {
			score += (c - 64); // A -> 1, B -> 2, etc.
		}
		score *= (i + 1);

		total += score;
	}

	return total;
}