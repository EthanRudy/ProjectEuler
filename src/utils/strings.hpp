#pragma once
#include <string>



inline bool is_palindrome(std::string str) {
	std::string orig = str;
	std::reverse(str.begin(), str.end());

	if (orig == str) { return true; }
	return false;
}

inline std::string rotate(std::string str) {
	char c = str[0];
	return str.substr(1) + c;
}