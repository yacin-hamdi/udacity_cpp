#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<string>


class Account{
    public:

        std::string getNumber();
        std::string getBalance();
        std::string getType();
        std::string getStatus();
        std::string getCreationDate();
        std::string getUsername();

        void setNumber(std::string number);
        void setBalance(std::string balance);
        void setType(std::string type);
        void setStatus(std::string type);
        void setCreationDate(std::string creation_date);
        void setUsername(std::string username);


    private:
        std::string _number;
        std::string _balance;
        std::string _type;
        std::string _status;
        std::string _creation_date;
        std::string _username;


};


#endif