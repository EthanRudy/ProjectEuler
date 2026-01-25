#include "../problems.hpp"
#include "../utils.hpp"


int solve_p017() {
	std::string ones[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	std::string teens[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	std::string tens[] = { "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	
	int total = 0;
	for (int i = 1; i <= 1000; ++i) {
		int n = i;
		// One thousand
		if (n == 1000) {
			total += strlen("onethousand");
			n = 0;
		}
		// Hundreds place
		if (n > 99) {
			int digit = n / 100;
			total += ones[digit - 1].length() + strlen("hundred");
			n %= 100;

			// "and" is needed
			if (n > 0) {
				total += strlen("and");
			}
		}

		// Tens place (no teens)
		if (n > 19) {
			int digit = n / 10;
			total += tens[digit - 1].length();

			n %= 10;
		}

		// Teens (no tens)
		if (n > 9) {
			int digit = n % 10;
			total += teens[digit].length();
			n = 0;
		}

		// Ones place (no teens)
		if (n > 0) {
			total += ones[n - 1].length();
		}
	}

	return total;
}