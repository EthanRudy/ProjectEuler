#ifndef PROBLEM_002_HPP
#define PROBLEM_002_HPP

#include "../include/problem.hpp"

class Problem002 : public Problem {
public:

	Problem002() {
		ID = 002;
		_name = "Even Fibonacci Numbers";

		ans = 0;
	}

	void solve() override {
		_timer.start();

		ans = 2; // Starting with 1 (not even) and 2
		int n1 = 1, n2 = 2, n3 = n1 + n2;

		while (n3 < 4000000) {
			n3 = n2 + n1;
			n1 = n2, n2 = n3;

			if (n3 % 2 == 0) { ans += n3; }
		}

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

#endif // !PROBLEM_002_HPP