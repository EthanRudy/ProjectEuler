#ifndef PROBLEM_HPP
#define PROBLEM_HPP

#include <algorithm>
#include <iostream>

#include "timer.hpp"
#include "prime_helper.hpp"
#include "num_helper.hpp"

class Problem {
public:

	Problem() {
		ID = -1;
		_name = "BASE";
	}

	virtual void solve() { }

	virtual void print_solution() { }

protected:
	unsigned int ID;
	std::string _name;
	Timer _timer;
private:
};

#endif // !PROBLEM_002_HPP