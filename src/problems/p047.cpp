#include "../problems.hpp"
#include "../utils.hpp"

int solve_p047() {

	// n consecutive numbers, each having n unique prime factors
	int n = 4;
	int count = 0;
	std::vector<std::pair<int, int>> factors;
	std::vector<int> primes_sub_n = { 2 };


	// this fuckass problem

	int i = 647;
	while (true) {
		// std::cout << i << "\n";
		std::vector<std::pair<int, int>> p_facts;
		naive_p_factorization(i, p_facts, primes_sub_n);

		/*
		std::cout << "\n" << i << ":\n";
		for (auto& pair : p_facts) {
			std::cout << "\t" << pair.first << " : " << pair.second << "\n";
		}
		std::cout << "\n";
		*/

		// Ensure we have n factors
		if (p_facts.size() == n) {


			// Ensure we're all unique!
			bool unique = true;
			for (auto& pair : p_facts) {
				if (std::find(factors.begin(), factors.end(), pair) != factors.end()) {
					unique = false;
					break;
				}
			}
			if (unique) {
				++count;
				factors.insert(factors.end(), p_facts.begin(), p_facts.end());
			}
			else {
				count = 0;
				factors.clear();
			}

		}
		else {
			count = 0;
			factors.clear();
		}



		++i;

		if (count == n) {
			return i - n;
		}
	}


	return -1;
}