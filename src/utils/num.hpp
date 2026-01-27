#pragma once

#include <algorithm>


inline void get_factors(int n, std::vector<int>& factors) {
	if (n < 1) { return; }
	
	for (int i = 1; i <= std::sqrt(n); ++i) {
		if (n % i == 0) {

			if (n / i == i) {
				factors.push_back(i);
			}
			else {
				factors.push_back(i);
				factors.push_back(n / i);
			}
		}
	}

	std::sort(factors.begin(), factors.end());
}

inline int sum_factors(int n) {
	if (n == 1) { return 1; }
	if (n == 0) { return 0; }

	std::vector<int> factors;
	get_factors(n, factors);

	int sum = 0;
	for (int n : factors) {
		sum += n;
	}
	return sum;
}

inline int sum_p_factors(int n) {
	if (n == 1 || n == 0) { return 0; }

	std::vector<int> factors;
	get_factors(n, factors);

	// I need them to be in order for this shortcut
	std::sort(factors.begin(), factors.end());

	int sum = 0;
	for (int i = 0; i < factors.size() - 1; ++i) {
		sum += factors[i];
	}

	return sum;
}

inline bool abundant(int n) {
	return sum_p_factors(n) > n;
}


inline int collatz_sequence_length(unsigned long long n) {
	if (n == 1) { return 1; }
	if (n % 2 == 0) {
		return 1 + collatz_sequence_length(n / 2);
	}
	else {
		return 1 + collatz_sequence_length(3 * n + 1);
	}
}

inline bool is_pandigital(std::string& str) {
	if (str.length() != 9) { return false; }
	for (int i = 1; i < 10; ++i) {
		if (std::count(str.begin(), str.end(), (i + '0')) != 1) {
			return false;
		}
	}

	return true;
}