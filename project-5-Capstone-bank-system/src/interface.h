#ifndef INTERFACE_H
#define INTERFACE_H

#include<iostream>
#include<vector>
#include "constants.h"
#include "customer.h"

struct Auth{
        std::string username;
        std::string password;
    };

class Interface{
    public:
        Auth loginInterface();
        bool loginSuccess(bool &success);
        bool connectToDatabaseInterface(bool connected);

        int userInterface();
        int adminInterface();
        int userAccountDetailsInterface(std::vector<std::string>);
        int allUserAccountDetailsInterface(std::vector<std::vector<std::string>>);
        int deleteUserInterface(std::vector<std::vector<std::string>>&);
        std::string closeAccountInterface();
        void byeAccountInterface();
        Customer addUserInterface();
        int addUserSuccess(int &state);

    private:
    Auth _auth;
};



#endif