#include<iostream>
#include<cassert>
#include<string>

struct Person {
public:
	Person(std::string n) :name(n) {};
	const std::string name;
};


int main() {
	Person moose("moose");
	Person dam("dam");
	std::cout << "person 1 name is " << moose.name << std::endl;
	std::cout << "person 2 name is " << dam.name << std::endl;
}