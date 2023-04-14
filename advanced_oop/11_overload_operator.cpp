#include<iostream>

class Point{
    public:
        Point(int x, int y):x_(x), y_(y){}
        Point(){}

        Point operator+(const Point &other){
            Point pt;
            pt.x_  = this->x_ + other.x_;
            pt.y_ = this->y_ + other.y_;
            return pt;
        }

        void print(){
            std::cout << "x = " << x_ << ", y = " << y_ << std::endl;
        }


    private:
        int x_ = 0;
        int y_ = 0;
};


int main(){
    Point pt1(1,2);
    Point pt2(3,4);
    Point pt3 = pt1 + pt2;
    pt3.print();
}