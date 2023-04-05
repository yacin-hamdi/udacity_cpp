#include "car.h"
#include<vector>
using std::vector;

int main() {

	vector<Car*> cars;
	vector<string> color = { "red", "green", "yellow" };
	for (int i = 0; i < 100; i++) {
		cars.push_back(new Car(color[i % 3], i + 1));
	}

	for (Car* cp : cars) {
		cp->incrementDistance();
		cp->printCarData();
	}
}