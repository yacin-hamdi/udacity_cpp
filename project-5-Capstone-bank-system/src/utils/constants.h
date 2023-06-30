#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>
#include<vector>


const std::string DATABASE_DETAILS = "database.dat";
const std::string CUSTOMER_TABLE = "customer";
const std::string ACCOUNT_TABLE = "account";
const std::string TRANSACTION_TABLE = "transaction";
const std::string ADMIN_PRIVILEGE = "1";
const std::string USER_PRIVILEGE = "0";



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

const std::vector<std::string> ACCOUNT_COLUMNS{
    "number", 
    "username",
    "balance", 
    "aod", 
    "type", 
    "status"
};

const std::vector<std::string> TRANSACTION_COLUMNS{
    "id", 
    "account_id",
    "from_account", 
    "to_account", 
    "transaction_date", 
    "transaction_amount", 

};



#endif