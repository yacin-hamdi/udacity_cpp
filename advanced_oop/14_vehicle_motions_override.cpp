#include<iostream>
#include<cassert>
#include<cmath>


class VehicleModel{
    public:
        virtual void move(double v, double phi) = 0;
};

class ParticleModel:VehicleModel{
    public:
        void move(double v, double phi) override{
            this->theta +=phi;
            this->x += v * cos(theta);
            this->y += v * sin(theta);
        }
        double x;
        double y;
        double theta;
};

class BicycleModel:public VehicleModel{
    public:
        BicycleModel(double x, double y, double theta, double length);
        void setPosition(double x, double y, double theta);
        void Length(double length);
        double X();
        double Y();
        double Theta();
        double Length();
        void move(double v, double theta)override ;

    private:
        double L{0};
        double x{0};
        double y{0};
        double theta{0};
       
};

BicycleModel::BicycleModel(double x, double y, double theta, double length){
    this->setPosition(x, y, theta);
    this->Length(length);
}
void BicycleModel::setPosition(double x, double y, double theta){
    this->x = x;
    this->y = y;
    this->theta = theta;
}
void BicycleModel::Length(double length){
    this->L = length;
}
double BicycleModel::X(){return this->x;}
double BicycleModel::Y(){return this->y;}
double BicycleModel::Theta(){return this->theta;}
double BicycleModel::Length(){return this->L;}

void BicycleModel::move(double v, double phi){
    this->theta += (v/this->Length()) * tan(phi);
    this->x += v * cos(theta);
    this->y += v * sin(theta);
}

int main(){
    BicycleModel model(1,2,3, 15);
    assert(model.X() == 1);
    assert(model.Y() == 2);
    assert(model.Theta() == 3);
    assert(model.Length() == 15);
    
    std::cout << "x = " << model.X() << ", y = " << model.Y() << ", theta = " << model.Theta() << std::endl;
    model.move(2, M_PI/2);
    std::cout << "x = " << model.X() << ", y = " << model.Y() << ", theta = " << model.Theta() << std::endl;

}