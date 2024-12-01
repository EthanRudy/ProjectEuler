#ifndef PROBLEM_003_HPP
#define PROBLEM_003_HPP

#include "../include/problem.hpp"

class Problem003 : public Problem {
public:

	Problem003() {
		ID = 003;
		_name = "Largest Prime Factor";

		ans = 0;
	}

	void solve() override {
		_timer.start();

		std::vector<unsigned long long> factors;
		prime_factors(600851475143, factors);
		ans = factors[factors.size() - 1];

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

	long long ans;
};

#endif // !PROBLEM_003_HPP