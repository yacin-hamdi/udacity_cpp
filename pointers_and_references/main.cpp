#include<iostream>



int main(){
    // int i = 5;

    // std::cout << "i values is " << i << std::endl;
    // std::cout << "i address is " << &i << std::endl;

    // int i = 4;
    // int *ptr_int = &i;
    // std::cout << "i address is " << ptr_int << std::endl;
    // std::cout << "i values is " << *ptr_int << std::endl;

    // int*ptr = new int(4);


    // std::cout << "ptr address is" << ptr << std::endl;
    // std::cout << "ptr values is " << *ptr << std::endl;
    // delete ptr;

    int var = 5;
    int *ptr_int = nullptr;

    ptr_int = &var;

    std::cout << "var: " << var << std::endl;
    std::cout << "&var: " << &var << std::endl;
    std::cout << "ptr_int: " << ptr_int << std::endl;
    std::cout << "*ptr_int: " << *ptr_int << std::endl;

}