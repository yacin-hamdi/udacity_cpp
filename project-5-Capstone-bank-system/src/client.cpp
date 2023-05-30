#include "client.h"

Client::Client(std::string username, std::string name, std::string email,
                std::string password, std::string account_num){
        this->_username = username;
        this->_name = name;
        this->_email = email;
        this->_password = password;
        this->_account_num = account_num;
    }
void Client::setUsername(std::string username){Client::_username = username;}
void Client::setName(std::string name){Client::_name = name;}
void Client::setEmail(std::string email){ Client::_email = email;}
void Client::setPassword(std::string password){Client::_password = password;}
void Client::setAccountNum(std::string account_num){Client::_account_num = account_num;}

std::string Client::getUsername(){return _username;}
std::string Client::getName(){return _name;}
std::string Client::getEmail(){return _email;}
std::string Client::getPassword(){return _password;}
std::string Client::getAccountNum(){return _account_num;}