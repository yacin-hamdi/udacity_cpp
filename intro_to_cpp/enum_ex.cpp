#include<iostream>
using std::cout;
enum class Color{red, black, green, yellow};	


int main() {
	Color red = Color::red;
	
	switch (red) {
	case Color::red: cout << "red";
		break;
	case Color::black: cout << "black";
		break;
	case Color::green: cout << "green";
		break;
	default: cout << "yellow";

	}

}