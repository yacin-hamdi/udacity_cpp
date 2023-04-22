#include<iostream>



int main(){
    int *ptr = nullptr;
    ptr = new(std::nothrow) int;
    if(!ptr){
        std::cout << "mem allocation failed!" << std::endl;
    }else{
        *ptr = 30;
        std::cout << "adress: " << ptr << std::endl;
        std::cout << "value: " << *ptr << std::endl;
    }

    std::cout << "-----------------------------\n";

    int *arr_ptr = new(std::nothrow) int[4];
    for (int i=0;i<4;i++){
        arr_ptr[i] = i*2;
    }

    for (int i=0;i<4;i++){
        
        std::cout << "address: " << &arr_ptr[i] << "value: " << arr_ptr[i] << std::endl;
        
    }

    delete ptr;
    delete[] arr_ptr;


    return 0;
}