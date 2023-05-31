#ifndef INTERFACE_H
#define INTERFACE_H

#include<iostream>

struct Auth{
        std::string username;
        std::string password;
    };

class Interface{
    public:
        Auth login();

    private:

};



#endif