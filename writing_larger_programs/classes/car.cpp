#include<iostream>
#include "car.h"
using std::cout;

void Car::printCarData() {
	cout << "the distance that " << color << " car " << number << " has traveled is " << distance << std::endl;

}

void Car::incrementDistance() {
	distance++;
}

