#include "../problems.hpp"
#include "../utils.hpp"


int sequenceLength(int den) {
	int num = 1;

	std::vector<int> digits;
	int digitNum = 0;

	while (num != 0) {
		num *= 10;
		div_t d = div(num, den);
		num = d.rem;

		if (num == 0) { return 0; }

		std::vector<int>::iterator pos = std::find(digits.begin(), digits.end(), num);
		if (pos != digits.end()) {
			return digitNum - (pos - digits.begin());
		}

		++digitNum;
		digits.push_back(num);
	}
}

int solve_p026() {
	int longest = 0;
	int longestDen;

	for (int i = 2; i < 1000; ++i) {
		int seqLen = sequenceLength(i);
		if (seqLen > longest) {
			longest = seqLen;
			longestDen = i;
		}
	}

	return longestDen;
}
