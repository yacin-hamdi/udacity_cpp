#include "account.h"

Account::Account(std::string number, std::string username, std::string balance, 
                std::string creation_date, std::string type, std::string status){
                setNumber(number);
                setUsername(username);
                setBalance(balance);
                setCreationDate(creation_date);
                setType(type);
                setStatus(status);
}
std::string Account::getNumber(){return _number;}
std::string Account::getBalance(){return _balance;}
std::string Account::getType(){return _type;}
std::string Account::getStatus(){return _status;}
std::string Account::getCreationDate(){return _creation_date;}
std::string Account::getUsername(){return _username;}

std::vector<std::string> Account::getAccountDetails(){
    return std::vector{
        getNumber(), getUsername(), getBalance(), 
        getCreationDate(), getType(), getStatus()
        };
}


void Account::setNumber(std::string number){_number = number;}
void Account::setBalance(std::string balance){_balance = balance;}
void Account::setType(std::string type){_type = type;}
void Account::setStatus(std::string status){_status = status;}
void Account::setCreationDate(std::string creation_date){_creation_date = creation_date;}
void Account::setUsername(std::string username){_username = username;}

void Account::setAccountDetails(MYSQL_ROW row){
    setNumber(row[0]);
    setUsername(row[1]);
    setBalance(row[2]);
    setCreationDate(row[3]);
    setType(row[4]);
    setStatus(row[5]);
    
}