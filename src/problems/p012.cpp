#include "../problems.hpp"
#include "../utils.hpp"

int solve_p012() {
	int num = 0;
	int to_add = 1;
	while (true) {
		std::vector<int> factors;
		get_factors(num, factors);

		if (factors.size() > 500) {
			return num;
		}

		num += to_add;
		to_add += 1;
	}
}