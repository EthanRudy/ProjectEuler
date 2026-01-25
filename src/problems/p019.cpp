#include "../problems.hpp"
#include "../utils.hpp"

// Zeller's Congruence :(
// I have deep rooted trauma from Honors Computer Programming II in highschool
int zellers(int year, int month, int day) {

	// Okay this is stupid, but january and february cound as the 13th and 14th month of the previous year
	// https://en.wikipedia.org/wiki/Zeller%27s_congruence, see the first note
	if (month < 3) {
		--year;
		month += 12;
	}

	return (day + ((13 * (month + 1)) / 5) + year + (year / 4) - (year / 100) + (year / 400)) % 7;
	// 1 == Sunday
}

int solve_p019() {

	int count = 0;
	for (int year = 1901; year <= 2000; ++year) {
		for (int month = 1; month <= 12; ++month) {
			// Don't need days because we're looking at only the first day!
			if (zellers(year, month, 1) == 1) {
				++count;
			}
		}
	}

	return count;
}