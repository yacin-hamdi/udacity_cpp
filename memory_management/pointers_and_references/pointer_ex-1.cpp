/* LAB 1
 * 
 * - Objectives
 * In this example we are going to make an implementation of memory allocation C++ via pointers. 
 * Using operators new and delete we are going to successfuly allocate and free memory (deallocation). 
 * Using pointers we are enabled to manipulate content of memory which has been allocated for usage.
 * 
 * - Steps
 * #1 Create new cpp file
 * #2 include standard iostream header
 * #3 Using pointer syntax declared integer type pointer
 * #4 Allocate memory of integer size via operator new
 * #5 Set this part of memory to specific integer
 * #6 Print memory address
 * #7 Print memory address value
 * #8 Free taken memory from the heap
 * #9 Exit script
 */

#include <iostream>

int main(){
    float *ptr_float;
    ptr_float = new float;
    *ptr_float = 21.2;
    std::cout << "address is " << ptr_float << std::endl;
    std::cout << "values is  " << *ptr_float<< std::endl;

    int *ptr_int = new int(5);
    std::cout << "address is " << ptr_int << std::endl;
    std::cout << "values is  " << *ptr_int << std::endl;


}
