#include "../problems.hpp"
#include "../utils.hpp"

int solve_p014() {

	int largest_chain = 0;
	int num = 1;
	for (int i = 1; i < 1000000; ++i) {
		int chain_size = collatz_sequence_length(i);
		if (chain_size > largest_chain) {
			largest_chain = chain_size;
			num = i;
		}
	}

	return num;
}