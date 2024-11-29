#ifndef PROBLEM_001_HPP
#define PROBLEM_001_HPP

#include "../include/problem.hpp"

class Problem001 : public Problem {
public:

	Problem001() {
		ID = 001;
		_name = "Multiples of 3 or 5";

		ans = 0;
	}

	void solve() override {
		_timer.start();

		for (int i = 3; i < 1000; ++i) {
			if (i % 3 == 0 || i % 5 == 0) { ans += i; }
		}

		_timer.end();
	}

	void print_solution() override {
		std::pair<int, std::string> duration_pair = _timer.duration();
		std::cout << "Problem #" << ID << " - " << _name << "\n"
			<< "Solution: " << ans << "\n"
			<< "Found in " << duration_pair.first << " " << duration_pair.second << "(s)\n";
	}
protected:
private:

	int ans;
};

#endif // !PROBLEM_001_HPP