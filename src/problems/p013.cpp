#include "../problems.hpp"
#include "../utils.hpp"

std::string solve_p013() {

	std::vector<std::string> strings;
	load_string_array("./src/inputs/p013.txt", strings);

	big::Integer sum = 0;
	for (std::string& s : strings) {
		sum += s;
	}

	std::string str = big::to_string(sum);

	return str.substr(0, 10);
}