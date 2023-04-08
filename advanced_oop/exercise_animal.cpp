#include<iostream>
#include<cassert>
#include<string>


class Animal {
public:
	int age{ 0 };
	std::string name;
	std::string color;
};


class Snake :public Animal {
public:
	int length;
	void makeSound() {
		std::cout << "sessssesss\n";
	}
};

class Cat :public Animal {
public:
	int height;
	void makeSound() {
		std::cout << "mawwwww!!";
	}
};


int main() {
	Snake snake1;
	snake1.age = 25;
	snake1.name = "solid snake";
	snake1.color = "red";

	std::cout << "this " << snake1.color << " called " << snake1.name << " and he is " << snake1.age << " days old\n";
	std::cout << "he is speaking snake language ";
	snake1.makeSound();

	Cat cat1;
	cat1.age = 50;
	cat1.name = 'D';
	cat1.color = "black and white";
	std::cout << "this " << cat1.color << " called big " << cat1.name << " and he is " << cat1.age << " days old\n";
	std::cout << "he is ";
	cat1.makeSound();
	std::cout << " all the time\n";

	
}