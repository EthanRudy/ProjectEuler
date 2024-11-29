#include "../include/problem_list.hpp"
#include <iostream>
#include <thread>

std::vector<std::unique_ptr<Problem>> problem_list;

void populate_problems();

int main() {
	populate_problems();

	// Gauntlet
	for (auto& p : problem_list) {
		p->solve();
		p->print_solution();
	}
}

void populate_problems() {
	

	problem_list.push_back(std::make_unique<Problem001>());
}