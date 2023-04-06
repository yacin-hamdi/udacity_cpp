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
		if (y > 0)
			Date::year = y;
	}


private:
	int day;
	int month;
	int year;
};



Date::Date(int d, int m, int y) {
	Day(d);
	Month(m);
	Year(y);
}

void Date::Day(int d) {
	if (d > 0 && d <= 30)
		day = d;
}



void Date::Month(int m) {
	if (m > 0 && m <= 12)
		month = m;
}




int main() {
	Date date(1, 1, 2000);
	std::cout << "today is " << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
	date.Day(3);
	date.Month(4);
	date.Year(1992);
	std::cout << "today is " << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";

}