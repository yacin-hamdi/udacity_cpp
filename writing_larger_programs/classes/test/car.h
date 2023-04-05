#ifndef CAR_H
#define CAR_H

#include<string>
using std::string;

class Car {
public:
	Car(string c, int n) :color(c), number(n) {};
	void incrementDistance();
	void printCarData();

private:
	string color;
	int number;
	int distance;
};

#endif
