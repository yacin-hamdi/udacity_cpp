#include<iostream>
#include<cassert>


class Birthday {
public:
	Birthday(int d, int m, int y):day(d), month(m), year(y) {};
	int Day() { return day; }
	int Month() { return month; }
	int Year() { return year; }

public:
	int const day;
	int const month;
	int const year;
};




int main() {
	Birthday date(1, 1, 2000);
	assert(date.Day() == 1);
	assert(date.Month() == 1);
	assert(date.Year() == 2000);
	std::cout << "my birthday is " << date.Day() << "/" << date.Month() << "/" << date.Year() << std::endl;	
}