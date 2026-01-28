#include "../problems.hpp"
#include "../utils.hpp"

int solve_p039() {

	const int MAX = 1000;

	int count[MAX];
	std::memset(count, 0, sizeof(int) * MAX);


	for (int a = 1; a < MAX; ++a) {
		for (int b = a; b < MAX; ++b) {

			
			int c_max = (MAX - a - b);
			for (int c = b + 1; c < c_max; ++c) {

				if ((a * a) + (b * b) == (c * c) && a + b + c < MAX) {
					count[a + b + c]++;
				}
			}
		}
	}


	int largest = 0;
	int p = -1;
	for (int i = 0; i < MAX; ++i) {
		if (count[i] > largest) {
			largest = count[i];
			p = i;
		}
	}


	return p;

}


// 240, 864, 960