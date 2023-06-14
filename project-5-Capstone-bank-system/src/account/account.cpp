#include "account.h"


std::string Account::getNumber(){return _number;}
std::string Account::getBalance(){return _balance;}
std::string Account::getType(){return _type;}
std::string Account::getStatus(){return _status;}
std::string Account::getCreationDate(){return _creation_date;}
std::string Account::getUsername(){return _username;}


void Account::setNumber(std::string number){_number = number;}
void Account::setBalance(std::string balance){_balance = balance;}
void Account::setType(std::string type){_type = type;}
void Account::setStatus(std::string status){_status = status;}
void Account::setCreationDate(std::string creation_date){_creation_date = creation_date;}
void Account::setUsername(std::string username){_username = username;}