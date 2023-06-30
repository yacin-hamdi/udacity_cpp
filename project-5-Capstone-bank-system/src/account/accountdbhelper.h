#ifndef ACCOUNTDBHELPER_H
#define ACCOUNTDBHELPER_H
#include "account.h"
#include<mysql/mysql.h>

class AccountDBHelper{

    public:
        bool getAccountDB(MYSQL *CONN,std::string column,  std::string value);
        bool addAccountDB(MYSQL *CONN, Account &account);
        bool updateAccountDB(MYSQL *CONN, std::string account_number, std::string column, std::string value);
        bool getAllAccountDB(MYSQL *CONN);
        bool removeAccountDB(MYSQL *CONN, std::string account_number);
        


        //accessor
        Account getAccount();
        std::vector<Account> getAllAccount();


    private:
        Account _account;
        std::vector<Account> _all_account;
        const std::string _ACCOUNT_TABLE = "account";
        std::string _query;
        int _state;
        MYSQL_RES *_res;
        MYSQL_ROW _row;


};

#endif