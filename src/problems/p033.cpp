#include "../problems.hpp"
#include "../utils.hpp"

int solve_p033() {

	int p_num = 1;
	int p_den = 1;

	for (int den = 11; den < 100; ++den) {

		for (int num = 10; num < den; ++num) {

			// Check for cancelable
			if (num % 10 != den / 10) { continue;  }

			float reg = float(num) / den;
			float simple = float(num / 10) / (den % 10);


			if (reg == simple) {
				p_num *= num;
				p_den *= den;
			}
		}
	}

	// std::cout << p_num << " / " << p_den << "\n";

	std::vector<int> n_fac, d_fac;
	get_factors(p_num, n_fac);
	get_factors(p_den, d_fac);

	// Find the greatest common factor
	for (int i = n_fac.size() - 1; i >= 0; --i) {
		if (std::find(d_fac.begin(), d_fac.end(), n_fac[i]) != d_fac.end()) {
			// Return the simplified denominator
			return p_den / n_fac[i];
		}
	}
}