#include<iostream>

class Date {
public:
	Date(int d, int m, int y);
	
	int Day() { return day; }
	void Day(int d);

	int Month() { return month; }
	void Month(int m);

	int Year() { return year; }
	void Year(int y) {
		year = y;
	}
private:
	int day{ 1 };
	int month{ 1 };
	int year{ 0 };
};


Date::Date(int d, int m, int y): year(y) {
	Day(d);
	Month(m);
}

void Date::Month(int m) {
	if (m > 0 && m <= 12)
		month = m;
}

void Date::Day(int d) {
	if (d > 0 && d <= 30)
		day = d;
}

int main() {
	Date date(-1, 40, 2000);
	std::cout << "today is " << date.Day() << "/" << date.Month() << "/" << date.Year() << std::endl;
}