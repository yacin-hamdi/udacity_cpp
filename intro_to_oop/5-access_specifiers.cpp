#include<cassert>
#include<iostream>

	struct Date {
	public:
		//Accessor => Getters
		int Day() { return day; }
		int Month() { return month; }
		int Year() { return year; }

		//Mutators => setters
		void Day(int d) {day = d;}
		void Month(int m) { month = m; }
		void Year(int y) { year = y; }

	private:
		int day{ 1 };
		int month{ 1 };
		int year{ 1992 };
	};

int main() {
	Date date;

	date.Day(1);
	date.Month(2);
	date.Year(1992);

	assert(date.Day() == 1);
	assert(date.Month() == 2);
	assert(date.Year() == 1992);

	std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
	date.Day(29);
	date.Month(2);
	date.Year(1993);

	std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";

}