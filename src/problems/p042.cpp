#include "../problems.hpp"
#include "../utils.hpp"

int solve_p042() {

	std::vector<std::string> names;
	load_names("./src/inputs/p042.txt", names);

	std::vector<int> tri_num;
	int term_number = 1;

	int count = 0;

	for (std::string& word : names) {
		// Get word value
		int word_value = 0;
		for (char c : word) {
			word_value += (c - 64);
		}

		// Generate enough triangle numbers such that tri_num.back() > word_value
		while (tri_num.size() == 0 || tri_num.back() < word_value) {
			tri_num.push_back(nth_tri_number(term_number));
			++term_number;
		}

		if (std::find(tri_num.begin(), tri_num.end(), word_value) != tri_num.end()) {
			++count;
		}
	}

	return count;
}