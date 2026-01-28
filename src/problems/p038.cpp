#include "../problems.hpp"
#include "../utils.hpp"

int solve_p038() {

	// Start large
	for (int a = 9999; a > 0; --a) {
		std::string concat = "";

		int n = 1;
		while (concat.length() < 9) {
			concat += std::to_string(a * n);

			++n; 
		}

		if (concat.length() == 9) {
			if (is_pandigital(concat)) {
				return std::stoi(concat);
			}
		}
	}

	return -1;
}
