#ifndef CAR_H
#define CAR_H
#include <string>
using std::string;
class Car {
public:
	Car(string c, int n) :color(c), number(n) {}
	void printCarData();
	void incrementDistance();

private:
	string color;
	int number;
	int distance = 0;
};

#endif
