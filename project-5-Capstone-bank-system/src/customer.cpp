#include "customer.h"

Customer::Customer(std::string name, std::string email, 
    std::string phone, std::string dob, 
    std::string city, std::string pin_code,
    std::string login, std::string password){

        this->_name = name;
        this->_email = email;
        this->_phone = phone;
        this->_dob = dob;
        this->_city = city;
        this->_pin_code = pin_code;
        this->_login = login;
        this->_password = password;

}


void Customer::setName(std::string name){_name = name;}
void Customer::setEmail(std::string email){_email = email;}
void Customer::setPhone(std::string phone){_phone = phone;}
void Customer::setDob(std::string dob){_dob = dob;}
void Customer::setCity(std::string city){_city = city;}
void Customer::setPinCode(std::string pin_code){_pin_code = pin_code;}
void Customer::setLogin(std::string login){_login = login;}
void Customer::setPassword(std::string password){_password = password;}
void Customer::setAdmin(std::string admin){_admin = admin;}


std::string Customer::getName(){return _name;}
std::string Customer::getEmail(){return _email;}
std::string Customer::getPhone(){return _phone;}
std::string Customer::getDob(){return _dob;}
std::string Customer::getCity(){return _city;}
std::string Customer::getPinCode(){return _pin_code;}
std::string Customer::getLogin(){return _login;}
std::string Customer::getPassword(){return _password;}
std::string Customer::getAdmin(){return _admin;}
