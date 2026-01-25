#include "../problems.hpp"
#include "../utils.hpp"

#include <set>

int solve_p021() {
	// We already have a factors func for this, only its not proper factors, so we skip the last one

	// Going to use a set to skip a couple numbers here and there
	std::set<int> found;
	int total = 0;

	for (int i = 1; i < 10000; ++i) {
		// If we already found it, skip it
		if (found.find(i) != found.end()) { 
			continue; 
		}

		int sum_facts = sum_p_factors(i);
		int o_sum_facts = sum_p_factors(sum_facts);

		// (pfact(b) == a) and (a != b)
		if (o_sum_facts == i && sum_facts != o_sum_facts) {

			found.insert(sum_facts);
			found.insert(i);
			total += i + sum_facts;
		}

		
	}

	return total;
}

// Correct: 31626