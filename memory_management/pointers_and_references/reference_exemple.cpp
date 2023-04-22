#include<iostream>
#include<string>

void addspace(const char *&str){
    char *temp = new char(sizeof(str)*2);
    char *start = temp;

    while(*str!='\0'){
        *temp++ = *str++;
        *temp++ = ' ';
    }
    str = start;
}

int main(){
    std::string str = "hello world";
    const char* ptr = str.c_str();
    std::cout << "ptr=" << ptr << std::endl;
    std::cout << "str=" << str << std::endl;
    addspace(ptr);
    std::cout << "ptr=" << ptr << std::endl;
    std::cout << "str=" << str << std::endl;

    



}