#ifndef NUM_HELPER_HPP
#define NUM_HELPER_HPP

#include <algorithm>
#include <string>

static bool palindrome(int num) {
	std::string rstr, str;
	str = rstr = std::to_string(num);
	std::reverse(rstr.begin(), rstr.end());
	return (str == rstr);
}

#endif // !NUM_HELPER_HPP