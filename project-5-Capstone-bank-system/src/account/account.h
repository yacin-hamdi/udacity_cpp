#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<string>
#include<mysql/mysql.h>
#include<vector>

class Account{
    public:
        Account(std::string number, std::string username, std::string balance,
                std::string creation_date, std::string type, std::string status);
        Account(){}

        std::string getNumber();
        std::string getBalance();
        std::string getType();
        std::string getStatus();
        std::string getCreationDate();
        std::string getUsername();
        std::vector<std::string> getAccountDetails();
        

        void setNumber(std::string number);
        void setBalance(std::string balance);
        void setType(std::string type);
        void setStatus(std::string type);
        void setCreationDate(std::string creation_date);
        void setUsername(std::string username);
        void setAccountDetails(MYSQL_ROW row);


    private:
        std::string _number;
        std::string _balance;
        std::string _type;
        std::string _status;
        std::string _creation_date;
        std::string _username;


};


#endif