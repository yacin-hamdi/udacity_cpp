#include<iostream>
#include<cassert>
#include<cmath>

void trigono(double& sin, double& cos, double angle){
    sin = std::sin(angle);
    cos = std::cos(angle);
}


int main(){

    double angle;
    std::cout << "angle:";
    std::cin>>angle;
    std::cout << std::endl;

    double sin, cos;
    trigono(sin, cos, angle);
    std::cout << "sin:" << sin << std::endl;
    std::cout << "cos:" << cos << std::endl; 


    // int var = 4;
    // int& ref = var;
    // assert(ref == var);

    // std::cout << "var=" << var << std::endl;
    // std::cout << "ref=" << ref << std::endl;

    // int var2 = 5;
    // ref = var2;
    // assert(ref == var2);
    // std::cout << "var2=" << var2 << std::endl;
    // std::cout << "ref=" << ref << std::endl;


    // int var3;
    // ref = var3;
    // assert(ref == var3);

    // std::cout << "var3=" << var3 << std::endl;
    // std::cout << "ref=" << ref << std::endl;
}