#include<iostream>
#include<cassert>
#include<cmath>
#include<stdexcept>
#include<string>

class Sphere {
public:
	Sphere(int radius):radius_(radius), volume_(M_PI * 4/3 * pow(radius, 3)) {}

	int Radius() { return radius_; }
	float Volume() { return volume_; }

	void Radius(int radius) {
		if (radius <= 0)
			throw std::invalid_argument("radius must be positive");
		radius_ = radius;
		volume_ = M_PI * 4 / 3 * pow(radius, 3);
	}

private:
	static float const pi_;
	int  radius_;
	float  volume_;
	
	
};

float const Sphere::pi_ = 3.14159;






int main() {
	Sphere sphere(5);
	assert(sphere.Radius() == 5);
	assert(abs(sphere.Volume() - 523.6) < 1);

	sphere.Radius(3);
	assert(sphere.Radius() == 3);
	assert(abs(sphere.Volume() - 113.1) < 1);

	bool myexception = false;
	try {
		sphere.Radius(-1);
	}
		
	catch (...) {
		myexception = true;
	}
		

	assert(!myexception);
	

}