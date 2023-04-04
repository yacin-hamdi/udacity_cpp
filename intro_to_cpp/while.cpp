#include<iostream>
#include<string>

int main() {
	int i = 0;
	std::string str;
	str = "hello world!";
	while (i < 10) {
		std::cout << str << "\n";
		i++;
	}
}