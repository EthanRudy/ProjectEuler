#pragma once

inline bool is_prime(int n) {
	if (n == 2) { return true; }
	if (n % 2 == 0) { return false; }

	int max = std::sqrt(n) + 1;

	for (int i = 2; i < max; ++i) {
		if (n % i == 0) { return false; }
	}

	return true;

}