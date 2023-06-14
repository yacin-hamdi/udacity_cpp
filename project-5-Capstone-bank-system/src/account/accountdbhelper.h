#ifndef ACCOUNTDBHELPER_H
#define ACCOUNTDBHELPER_H
#include "account.h"
#include "../databasehelper.h"

class AccountDBHelper:DatabaseHelper{

    public:
        Account getAccountDetails(std::string username);


    private:
        Account _account;


};

#endif