#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <string>
#include <type_traits>

class Timer {
public:

	Timer() = default;

	void start() {
		_start = std::chrono::high_resolution_clock::now();
	}

	void end() {
		_end = std::chrono::high_resolution_clock::now();
	}

	const std::pair<int, std::string> duration() {
		unsigned long long time = std::chrono::duration_cast<std::chrono::nanoseconds>(_end - _start).count();
		int interval = 0;
		/*
		0 -> Nanoseconds
		1 -> Microseconds
		2 -> Milliseconds
		3 -> Seconds
		*/

		while (time > 1000 && interval < 3) {
			switch (interval) {
			case 0:
				++interval;
				break;
			case 1:
				++interval;
				break;
			case 2:
				++interval;
			default: break;
				
			};

			time /= 1000;
		}

		return std::pair<int, std::string>{ time, _interval_strings[interval] };
	}

	template <typename AllowedInterval, typename = std::enable_if_t<
		std::is_same_v<AllowedInterval, std::chrono::seconds> ||
		std::is_same_v<AllowedInterval, std::chrono::milliseconds> ||
		std::is_same_v<AllowedInterval, std::chrono::microseconds> ||
		std::is_same_v<AllowedInterval, std::chrono::nanoseconds>>>
	const int duration() {
		return std::chrono::duration_cast<AllowedInterval>(_end - _start).count();
	}

protected:
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> _start, _end;
	std::string _interval_strings[4] = { "nanosecond", "microsecond", "millisecond", "second"};
};

#endif // !TIMER_HPP