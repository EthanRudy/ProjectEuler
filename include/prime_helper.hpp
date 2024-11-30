#ifndef PRIME_HELPER
#define PRIME_HELPER

#include <cmath>
#include <vector>

static void prime_factors(unsigned long long limit, std::vector<unsigned long long>& factors) {
	while (limit % 2 == 0) {
		limit /= 2;
		if (factors.size() == 0) { factors.push_back(2); }
	}

	for (int i = 3; i * i <= limit; i += 2) {
		while (limit % i == 0) {
			factors.push_back(i);
			limit /= i;
		}
	}

	if (limit > 2) { factors.push_back(limit); }
}

#endif // !PRIME_HELPER
