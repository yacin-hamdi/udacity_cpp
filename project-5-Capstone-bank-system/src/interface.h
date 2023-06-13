#ifndef INTERFACE_H
#define INTERFACE_H

#include<iostream>
#include<vector>
#include "constants.h"
#include "customer.h"
#include "TextTable.h"


struct Auth{
        std::string username;
        std::string password;
    };

class Interface{
    public:
        Auth loginInterface();
        bool loginSuccess(bool &success);
        bool connectToDatabaseInterface(bool &connected);
        Interface();
        int adminInterface();
        int userAccountDetailsInterface(std::vector<std::string>&);
        int allUserAccountDetailsInterface(std::vector<std::vector<std::string>>&);
        int deleteUserInterface(std::vector<std::vector<std::string>>&);
        std::vector<std::string> updateAdminUserInterface();
        std::vector<std::string> updateUserInterface();
        std::string closeAccountInterface();
        void byeAccountInterface();
        Customer addUserInterface();
        int addUserSuccess(int &state);
        int updateUserSuccess(bool &state);
        int userInterface();

    private:
    Auth _auth;
    std::string _temp;
    Customer _customer;
    std::vector<std::string> _details_temp;
};



#endif