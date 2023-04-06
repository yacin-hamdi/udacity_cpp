#include<iostream>	
#include<cassert>

	struct Date {
		int day{31};
		int month{2};
		int year{2015};
	};

int main() {


	// Create an instance of the Date structure
	Date date;

	// Initialize the attributes of Date
	date.day = 31;
	date.month = 2;
	date.year = 2015;
	
	/*std::cout << "day of birth: ";
	std::cin >> date.day;
	std::cout << "month of birth: ";
	std::cin >> date.month;
	std::cout << "year of birth: ";
	std::cin >> date.year;
	
	assert(date.day == 19);
	assert(date.month == 4);
	assert(date.year == 2000);
	*/
	std::cout << "date: " << date.day << "/" << date.month << "/" << date.year << "\n";
}