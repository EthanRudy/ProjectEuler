#include "../problems.hpp"
#include "../utils.hpp"


unsigned long long solve_p008() {
	std::string str = "";
	load_input("./src/inputs/p008.txt", str);
	

	unsigned long long largest = 0;
	// Try adjacent 4 digits
	for (int i = 0; i < 1000 - 13; ++i) {
		unsigned long long prod = 1;
		for (int o = 0; o < 13; ++o) {
			prod *= (str[i + o] - '0');
		}

		if (prod > largest) {
			largest = prod;
		}
	}

	return largest;
}