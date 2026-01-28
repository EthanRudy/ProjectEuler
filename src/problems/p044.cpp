#include "../problems.hpp"
#include "../utils.hpp"

int solve_p044() {

	std::vector<int> pent_nums;
	int t_num = 1;
	pent_nums.push_back(nth_pent_number(t_num++));
	pent_nums.push_back(nth_pent_number(t_num++));

	int j = 0;
	int min = 999999999;
	while (j < 2500) {
		int p_j = pent_nums[j];

		// if (j % 100 == 0) { std::cout << j << "\n"; }

		int k = j + 1;
		while (k < 2500) {
			int p_k = pent_nums[k];

			// Find difference and sum
			int diff = std::abs(p_j - p_k);
			int sum = p_j + p_k;

			// Ensure that I have enough to check
			while (std::max(diff, sum) > pent_nums.back()) {
				pent_nums.push_back(nth_pent_number(t_num++));
			}

			if (std::find(pent_nums.begin(), pent_nums.end(), diff) != pent_nums.end()
				&&
				std::find(pent_nums.begin(), pent_nums.end(), sum) != pent_nums.end()) {

				min = std::min(min, diff);
			}

			++k;
		}



		++j;
	}

	return min;
}

// 22, 76