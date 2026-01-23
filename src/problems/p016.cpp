#include "../problems.hpp"
#include "../utils.hpp"


int solve_p016() {
	big::Integer num = big::pow(2, 1000);
	std::string str = big::to_string(num);

	int sum = 0;
	for (char c : str) {
		sum += (c - '0');
	}

	std::cout << num << "\n";
	
	return sum;
}