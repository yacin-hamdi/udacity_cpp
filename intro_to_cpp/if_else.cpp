#include<iostream>
#include<vector>


int main() {
	int year_of_birth = 2001;
	int current_year = 2023;
	int age = current_year - year_of_birth;
	if (age < 23)
		std::cout << "your not old enough" << std::endl;
	else if (age == 23) {
		std::cout << "welcome" << std::endl;
	}
	else {
		std::cout << "your old";
	}
}