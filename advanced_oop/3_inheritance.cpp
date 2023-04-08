#include<iostream>
#include<string>
#include<cassert>

class Vehicle {
public:

	int wheels = 0;
	std::string color = "blue";
	double steering_angle = 0;
	int speed = 0;

	void print() const {
		std::cout << "this " << color << " vehicle has " << wheels << " wheels\n";
	}

};


class Car :protected Vehicle {
public:
	Car(int wheels, std::string color, double steering_angle, int speed) {
		this->wheels = wheels;
		this->color = color;
		this->steering_angle = steering_angle;
		this->speed = speed;
	}

	void printcar() {
		print();
	}

};

class Bicycle :private Vehicle {
public:
	Bicycle(int wheels, std::string color, double steering_angle, int speed) {
		this->wheels = wheels;
		this->color = color;
		this->steering_angle = steering_angle;
		this->speed = speed;
	}

	void printbic() {
		print();
	}
	

};


int main() {
	Car car(4, "red", 30, 80);
	Bicycle bicycle(2, "black", 10, 5);
	car.printcar();
	bicycle.printbic();
	

	


}