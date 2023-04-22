/*
1. Declare one integer and one double variable 
2. Declare two references of same type
3. Use initial variables and assign them upon 
   initialization to corresponding references 
4. Check references, write them out 
5. Change, modify variables 
6. Write references again
*/

#include<iostream>


int main(){
    int var1;
    double var2;

    int &ref1 = var1;
    double &ref2 = var2;

    std::cout << "ref1 = " << ref1 << std::endl;
    std::cout << "ref2 = " << ref2 << std::endl;

    var1 = 2;
    var2 = 23.22;

    std::cout << "ref1 = " << ref1 << std::endl;
    std::cout << "ref2 = " << ref2 << std::endl;

}