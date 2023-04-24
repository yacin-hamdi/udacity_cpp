#include<iostream>
#include<cstring>


int main(){
    char *ptr = new char('A');
    char str[4] = "AAA";

    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "str: " <<  str << std::endl;
    memset(ptr, 'C', 1);
    memset(str+1, 'D', 1);
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "str: " << str << std::endl;
}