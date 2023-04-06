#include<iostream>

	class Date {
	public:
		//constructors1
		Date(int d, int m, int y) {
			Day(d);
		}

		//constructors2
		Date(){}

		int Day() { return day; }
		void Day(int d) { day = d; };

		int Month() { return month; }
		void Month(int m) { month = m; }

		int Year() { return year; }
		void Year(int y) { year = y; }

	private:
		int day;
		int month;
		int year;
	};


int main() {
	Date date1 = Date(1,2,2000);
	Date date2 = Date();
	Date date3;
	date3.Day(3);
	std::cout << date3.Day() << std::endl;
	
}