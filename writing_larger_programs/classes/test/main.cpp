#include "car.h"
#include <vector>
using std::vector;

int main() {
	vector<Car*> cars;
	Car* cp = nullptr;
	vector<string> colors = { "red", "green", "black" };
	for (int i = 0; i < 100; i++) {
		cp = new Car{ colors[i % 3], i - 1 };
		cars.push_back(cp);
	}

	for (auto car : cars) {
		car->incrementDistance();
		car->printCarData();
	}
}