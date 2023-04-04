#include<iostream>
using std::cout

int multiply_by_two(int i) {
	i = i * 2;
	return i;
}

int main() {
	int a = 5;
	cout << "the int a=" << a << "\n";
	int b = multiply_by_two(a);
	cout << "the int b=" << b << "\n";
	cout << "and the a=" << a << "\n";
}