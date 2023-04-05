#include "car.h"

#include<iostream>
using std::cout;
void Car::incrementDistance() {
	distance++;
}

void Car::printCarData() {
	cout << "the distance that " << color << " car " << number << " has traveled is " << distance << std::endl;
}