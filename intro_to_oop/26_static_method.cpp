#include<iostream>
#include<cassert>
#include<cmath>

class Sphere {
public:
	static float Volume(int radius) {
		return M_PI * 4 / 3 * pow(radius, 3);
	}
private:


};

int main() {
	int radius = 5;
	assert(abs(Sphere::Volume(5) - 523.6) < 1);
	std::cout << "sphere volume = " << Sphere::Volume(radius) << std::endl;
}