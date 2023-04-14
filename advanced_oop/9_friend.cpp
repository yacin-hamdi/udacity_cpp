#include<iostream>
#include<cassert>

class Rectangle;

class Square{

    public:
        Square(int side):side_(side){};

    private:
        int side_;
        friend class Rectangle;
};

class Rectangle{
    public:
        Rectangle(Square square):width_(square.side_), height_(square.side_){};
        int Area();
    private:
        int width_ {0};
        int height_ {0};
};

int Rectangle::Area(){
    return this->width_ * height_;
}


int main(){
    Square square(2);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 4);
}
