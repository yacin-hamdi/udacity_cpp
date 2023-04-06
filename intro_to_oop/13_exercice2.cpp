#include<iostream>
#include<cassert>
#include<string>

struct Person {
public:
	Person(std::string const &n):name(n) {};
	const std::string name;
};


int main() {
	Person moose("moose");
	Person dam("dam");
	int const i= 1;
	const int& j = i;
	std::cout << "person 1 name is " << moose.name << std::endl;
	std::cout << "person 2 name is " << dam.name << std::endl;
}