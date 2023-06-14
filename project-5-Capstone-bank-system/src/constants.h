#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>
#include<vector>

const std::string DATABASE_DETAILS = "database.dat";
const std::string CUSTOMER_TABLE = "customer";
const std::string ACCOUNT_TABLE = "account";



const std::vector<std::string> CUSTOMER_COLUMNS{
    "id",
    "name",
    "email",
    "phone",
    "date of birth",
    "city",
    "pin code",
    "login",
    "password",
    "admin"

};



#endif