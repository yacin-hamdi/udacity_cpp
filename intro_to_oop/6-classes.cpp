#include<iostream>	
#include<cassert>

class Date {
public:
	//accessors
	int Day() { return day; }
	int Month() { return month; }
	int Year() { return year; }

	//mutators
	void Day(int d) {
		if(d > 0 && d < 31) //invariant
			day = d;
	}
	void Month(int m) {
		if(m > 0 && m <=12) //invariant 
			month = m; 
	}
	void Year(int y) { year = y; }


private:
	int day{ 1 };
	int month{ 2 };
	int year{ 2000 };
};

int main() {
	Date today;
	today.Day(29);
	today.Month(13);
	today.Year(2000);

	std::cout << "today is " << today.Day() << "/" << today.Month() << "/" << today.Year() << "\n";
}