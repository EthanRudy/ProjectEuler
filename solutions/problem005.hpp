#ifndef PROBLEM_005_HPP
#define PROBLEM_005_HPP

#include "../include/problem.hpp"

class Problem005 : public Problem {
public:

	Problem005() {
		ID = 005;
		_name = "";

		ans = 0;
	}

	void solve() override {
		_timer.start();

		// Refined list of numbers to check, Ex we remove 2 & 10, becuase anything divisible
		// by 20, is also divisible by 10 & 2
		int factors[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
		int num = 20;
		bool found = false;
		while (!found) {
			found = true;

			for (int n : factors) {
				if (num % n != 0) {
					found = false;
					break;
				}
			}

			if (!found) { num += 20; }
		}

		ans = num;

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

#endif // !PROBLEM_005_HPP