#include<iostream>



int main(){
    double* ptr_doub = new double(12.4);
    double* ptr_array = new double[4];
    for(int i=0;i<4;i++){
        ptr_array[i]=i;
    }
    for(int i=0;i<4;i++){
        *ptr_doub = ++*ptr_doub;
        ptr_array[i]  = i;
        
        std::cout << "address: " << ptr_doub << ", value: " << *ptr_doub << std::endl;
        std::cout << "address array: " << ptr_array << ", value array: " << ptr_array[i] << std::endl;
    }

    std::cout << "------------------------------------------------\n";
    for(int i=0;i<4;i++){
        
        std::cout << "address: " << ptr_doub << ", value: " << *ptr_doub << std::endl;
        std::cout << "address array: " << ptr_array << ", value array: " << *ptr_array << std::endl;
        ptr_array = ++ptr_array;
        ptr_doub = ++ptr_doub;
    }
}