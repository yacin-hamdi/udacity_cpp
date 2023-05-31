#include "interface.h"

Auth Interface::login(){
    
    Auth auth;
    
    std::cout << "------welcome to my bank--------\n";
    std::cout << "enter your username: ";
    std::cin >> auth.username;
    std::cout << "enter your password: ";
    std::cin >> auth.password;
    return auth;
}