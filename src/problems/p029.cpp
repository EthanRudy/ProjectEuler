#include "../problems.hpp"
#include "../utils.hpp"

#include <set>

int solve_p029() {

	std::set<big::Integer> unique;

	for (int a = 2; a <= 100; ++a) {
		big::Integer n = a;
		for (int b = 2; b <= 100; ++b) {
			n *= a;
			unique.insert(n);
		}
	}

	return unique.size();
}

// 92628