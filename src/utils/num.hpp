#pragma once


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