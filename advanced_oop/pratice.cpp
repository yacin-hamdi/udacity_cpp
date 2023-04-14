#include<iostream>
#include<cassert>

class Shape{
    public:
        virtual double Area() const = 0;
        virtual double Perimeter() const = 0;
};


class Rectangle:public Shape{
    public:
        Rectangle(float width, float height):width_(width), height_(height){}

        void Width(float width);
        float Width() const;
        void Height(float height);
        float Height() const;

        double Area() const override;
        double Perimeter()const override;
    

    private:
        float width_ {0};
        float height_ {0};

};

void Rectangle::Width(float width){this->width_ = width;}
float Rectangle::Width() const{return this->width_;}

void Rectangle::Height(float height){this->height_ = height;}
float Rectangle::Height() const{return this->height_;}

double Rectangle::Area() const {
    return this->Height() * this->Width();
}

double Rectangle::Perimeter()const{
    return (this->Height() + this->Width()) * 2;
}

int main(){
    Rectangle rectangle(2,2);
    assert(rectangle.Width() == 2);
    assert(rectangle.Height() == 2);
    assert(rectangle.Area() == 4);
    assert(rectangle.Perimeter() == 8);
    
}