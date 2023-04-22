/*
1. Declare basic include->iostream 
2. Declare main function 
3. Use pointer syntax to declare integer pointer 
4. Use new operator to allocate memory space for one integer number via new syntax 
5. Assign that operation to declared pointer 
6. Print its address and value to make sure that we have right information 
7. Release occupied space before exiting
*/
#include<iostream>




int main(){
    int *ptr = nullptr;
    ptr = new(std::nothrow) int;
    *ptr = 10;
    std::cout << "address : " << ptr << ", value: " << *ptr << std::endl;

    delete ptr;
    return 0;

}