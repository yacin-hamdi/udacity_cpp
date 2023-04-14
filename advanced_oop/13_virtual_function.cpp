#include<iostream>
#include<string>
#include<cassert>


class Shape{
    public:
        Shape(){};
        virtual double Area()const = 0;
        virtual double Perimeter()const = 0;
};

class Rectangle:public Shape{
    public:
        Rectangle(double width, double height):width_(width), height_(height){}
        double Area() const override{
            return width_ * height_;
        }

        double Perimeter() const override{
            return 2*(width_ + height_);
        }

    private:
        double width_;
        double height_;
};

int main(){
    Rectangle rectangle(2,2);
    assert(rectangle.Area() == 4);
    assert(rectangle.Perimeter() == 8);
}