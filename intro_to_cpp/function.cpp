#include<iostream>
#include<vector>
int add(int, int);
int sub(int, int);

int main() {
	std::cout << add(1, 1) << std::endl;
	std::cout << sub(1, 1) << std::endl;
}

int add(int a, int b) {
	std::cout << a << "+" << b << "=";
	return a + b;
}

int sub(int a, int b) {
	std::cout << a << "-" << b << "=";
	return a - b;
}