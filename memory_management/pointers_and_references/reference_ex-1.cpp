/*
1. Create function swap.
2. Use template arguments, create generic type T which will be type of both input parameters
3. Declare input parameters by reference
4. Create function logic to swap two variable data
5. Logic is going to swap variables without usage of the helper (temp) variable
6. Return type of function is void ( doesn't return value)
7. Print out value of variables before and after function execution
8. Exit main function
*/

#include<iostream>

template<typename t> void swap(t &var1, t &var2){
    var1 += var2;
    var2 = var1 - var2;
    var1 -= var2;
}


int main(){
    int var1 =10;
    int var2 = 11;
    std::cout << "var1 = " << var1 << std::endl;
    std::cout << "var2 = " << var2 << std::endl;
    swap<int>(var1, var2);

    std::cout << "var1 = " << var1 << std::endl;
    std::cout << "var2 = " << var2 << std::endl;


    return 0;
}