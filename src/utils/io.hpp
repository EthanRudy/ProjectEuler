#pragma once


#include <fstream>
#include <string>
#include <vector>
#include <sstream>

inline void load_input(std::string filepath, std::string& target) {
	std::ifstream file(filepath);
	std::string line;
	while (std::getline(file, line)) {
		target += line;
	}
}

inline void load_grid(std::string filepath, std::vector<std::vector<int>>& grid) {
	std::ifstream file(filepath);
	std::string line;
	while (std::getline(file, line)) {
		std::vector<int> row;
		std::stringstream ss(line);
		std::string num;
		while (ss >> num) {
			row.push_back(std::stoi(num));
		}
		grid.push_back(row);
	}
}

inline void load_string_array(std::string filepath, std::vector<std::string>& array) {
	std::ifstream file(filepath);
	std::string line;
	while (std::getline(file, line)) {
		array.push_back(line);
	}
}