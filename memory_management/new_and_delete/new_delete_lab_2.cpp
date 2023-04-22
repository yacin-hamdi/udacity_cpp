/*
1. Declare basic include->iostream 
2. Declare main function 
3. Use pointer syntax to declare integer array pointer 
4. Use new operator to allocate memory block for integer array
5. Assign that operation to declared pointer 
6. Create for loop and use it to input new values from cin stream 
7. Print every memory address and value in array 
8. Release occupied space before exiting
*/

#include<iostream>



int main(){
    int *arr_ptr = nullptr;
    arr_ptr = new(std::nothrow) int[4];
    for (int i=0;i<4;i++){
        std::cout << "value " << i+1 <<":";
        std::cin >> arr_ptr[i]; 
    }

    for (int i=0;i<4;i++){
        std::cout << "address: " << &arr_ptr[i] << ", value: " << arr_ptr[i] << std::endl;
    }

    delete[] arr_ptr;

    return 0;
}