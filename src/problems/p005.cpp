#include "../problems.hpp"

int solve_p005() {
	// I can skip some numbers like 2, 5, 5, etc because they're factors of 20
	int to_check[] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

	// Our number will also be a multiple of 20
	int ans = 20;
	while (true) {
		bool valid = true;

		for (int n : to_check) {
			if (ans % n != 0) {
				valid = false;
				break;
			}
		}

		if (valid) { return ans; }
		ans += 20;
	}

	return -1;
}