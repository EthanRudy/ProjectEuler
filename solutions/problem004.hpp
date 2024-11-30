#ifndef PROBLEM_004_HPP
#define PROBLEM_004_HPP

#include "../include/problem.hpp"

class Problem004 : public Problem {
public:

	Problem004() {
		ID = 004;
		_name = "Largest Palindrome Product";

		ans = 0;
	}

	void solve() override {
		_timer.start();

		int largest = 0;
		for (int a = 999; a > 99; --a) {
			for (int b = a; b > 99; --b) {
				int prod = a * b;
				if (palindrome(prod) && prod > largest) {
					largest = prod;
				}
			}
		}
		ans = largest;

		_timer.end();
	}

	void print_solution() override {
		std::pair<int, std::string> duration_pair = _timer.duration();
		std::cout << "Problem #" << ID << " - " << _name << "\n"
			<< "Solution: " << ans << "\n"
			<< "Found in " << duration_pair.first << " " << duration_pair.second << "(s)\n\n";
	}
protected:
private:
	int ans;
};

#endif // !PROBLEM_004_HPP