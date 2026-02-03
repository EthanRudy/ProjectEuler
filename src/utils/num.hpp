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

inline int factorial(int n) {
	int prod = 1;

	while (n > 0) {
		prod *= n;
		--n;
	}

	return prod;
}

inline int f_digit_sum(int n) {
	int sum = 0;

	while (n > 0) {
		sum += factorial(n % 10);
		n /= 10;
	}

	return sum;
}

inline std::string bin_str(int n) {
	std::string bin = "";

	int place = 1;
	while (n > 0) {
		bin += (n % 2) + '0';
		n /= 2;
	}

	std::reverse(bin.begin(), bin.end());

	return bin;
}

inline unsigned long long nth_tri_number(int n) {
	return n * (n + 1) / 2;
}

inline bool is_tri_number(unsigned long long n) {
	unsigned long long x = sqrt(2 * n);
	unsigned long long check = x * (x + 1) / 2;
	return n == check;
}

inline unsigned long long nth_pent_number(int n) {
	return n * ((3 * n) - 1) / 2;
}

inline bool is_pent_number(unsigned long long n) {
	unsigned long long x = (1 + sqrt(24 * n + 1)) / 6;
	auto check = x * (3 * x - 1) / 2;
	return n == check;
}

inline unsigned long long nth_hex_number(int n) {
	return n * ((2 * n) - 1);
}

inline int next_odd_comp(int n) {
	if (n % 2 == 0) { n += 1; }
	else { n += 2; }
	while (is_prime(n)) {
		n += 2;
	}

	return n;
}

// Okay this is some wacky ass shit
// the first of the is the number, and the second is how many times it appears
// So for example:	644 is ((2, 2), (7, 1), (23, 1))
// Versus:			646 is ((2, 1), (17,1), (19, 1))
// Both of these share the factor: 2, but in different QUANTITIES
// That matters for problem #47
inline void naive_p_factorization(int n, std::vector<std::pair<int, int>>& factors) {
	std::vector<int> primes_sub_n;
	sieve_of_eratosthenes(n, primes_sub_n);

	while (n != 1) {
		for (int p : primes_sub_n) {
			if (n % p == 0) {
				// Divide n by p
				n /= p;

				// Handle p
				// Option 1, p is already in there, increment the occurences
				// Option 2, p is new!
				bool new_factor = true;
				for (int i = 0; i < factors.size(); ++i) {
					// Option 1
					if (factors[i].first == p) {
						factors[i].second++;
						new_factor = false;
					}
				}

				// Option 2
				if (new_factor) {
					factors.push_back(std::pair<int, int>(p, 1));
				}

				break;
			}
		}
	}
}


// Quicker version, sieve was taking too long
// Another option would be passing an arbitrarily large list of primes
inline void naive_p_factorization(int n, std::vector<std::pair<int, int>>& factors, std::vector<int>& primes_sub_n) {
	while (primes_sub_n.back() < n) {
		primes_sub_n.push_back(primes_sub_n.back() + 1);
	}
	//sieve_of_eratosthenes(n, primes_sub_n);

	while (n != 1) {
		for (int p : primes_sub_n) {
			if (n % p == 0) {
				// Divide n by p
				n /= p;

				// Handle p
				// Option 1, p is already in there, increment the occurences
				// Option 2, p is new!
				bool new_factor = true;
				for (int i = 0; i < factors.size(); ++i) {
					// Option 1
					if (factors[i].first == p) {
						factors[i].second++;
						new_factor = false;
					}
				}

				// Option 2
				if (new_factor) {
					factors.push_back(std::pair<int, int>(p, 1));
				}

				break;
			}
		}
	}
}