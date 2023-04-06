#include<iostream>
#include<string>


class Person {
public:
	Person(std::string n):name(n){}

	std::string Name() { return name; }

private:
	std::string name;
};


int main() {
	Person moose("moose");
	std::cout << "my name is " << moose.Name() << std::endl;
}