#include "../problems.hpp"
#include "../utils.hpp"


int solve_p011() {
	std::vector<std::vector<int>> grid;
	load_grid("./src/inputs/p011.txt", grid);

	int largest = 0;

	// Horizontal
	for (int row = 0; row < 20; ++row) {
		for (int col = 0; col < 16; ++col) {
			int prod = 1;
			for (int offset = 0; offset < 4; ++offset) {
				prod *= grid[row][col + offset];
			}
			largest = std::max(largest, prod);
		}
	}

	// Verical
	for (int row = 0; row < 16; ++row) {
		for (int col = 0; col < 20; ++col) {
			int prod = 1;
			for (int offset = 0; offset < 4; ++offset) {
				prod *= grid[row + offset][col];
			}
			largest = std::max(largest, prod);
		}
	}

	// Diagonal
	for (int row = 0; row < 16; ++row) {
		for (int col = 0; col < 16; ++col) {
			int prod = 1;
			for (int offset = 0; offset < 4; ++offset) {
				prod *= grid[row + offset][col + offset];
			}
			largest = std::max(largest, prod);
		}
	}

	// Inverse Diagonal
	for (int row = 4; row < 20; ++row) {
		for (int col = 0; col < 16; ++col) {
			int prod = 1;
			for (int offset = 0; offset < 4; ++offset) {
				prod *= grid[row - offset][col + offset];
			}
			largest = std::max(largest, prod);
		}
	}

	return largest;
}