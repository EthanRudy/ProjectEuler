#pragma once


#include <fstream>
#include <string>

inline void load_input(std::string filepath, std::string& target) {
	std::ifstream file(filepath);
	std::string line;
	while (std::getline(file, line)) {
		target += line;
	}
}