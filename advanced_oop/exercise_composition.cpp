#include<iostream>
#include<cassert>
#include<cmath>

#define pi 3.14159;

class LineSegment {
public:
	double length;
};



class Circle {
public:
	Circle(LineSegment& radius);

	double Area();

private:
	LineSegment& radius_;
};

Circle::Circle(LineSegment& radius) :radius_(radius) {}

double Circle::Area() {
	double area =  pow(radius_.length,2)*pi;
	return area;
}

int main() {
	LineSegment radius{ 3.0};
	Circle circle(radius);
	std::cout << "area " << circle.Area() << std::endl;
}