#include "customer.h"

Customer::Customer(std::string id, std::string name, std::string email, 
    std::string phone, std::string dob, 
    std::string city, std::string pin_code,
    std::string login, std::string password,
    std::string admin){
        setId(id);
        setName(name);
        setEmail(email);
        setPhone(phone);
        setDob(dob);
        setCity(city);
        setPinCode(pin_code);
        setLogin(login);
        setPassword(password);
        setAdmin(admin);

}

void Customer::setAllDetails(MYSQL_ROW row){

    setId(row[0]);
    setName(row[1]);
    setEmail(row[2]);
    setPhone(row[3]);
    setDob(row[4]);
    setCity(row[5]);
    setPinCode(row[6]);
    setLogin(row[7]);
    setPassword(row[8]);
    setAdmin(row[9]);
}

std::vector<std::string> Customer::getAllDetails(){
    return std::vector<std::string>{getId(),getName(), getEmail(), getPhone(),
                                    getDob(), getCity(), getPinCode(),
                                    getLogin(), getPassword(), getAdmin()};
}


void Customer::setId(std::string id){_id = id;}
void Customer::setName(std::string name){_name = name;}
void Customer::setEmail(std::string email){_email = email;}
void Customer::setPhone(std::string phone){_phone = phone;}
void Customer::setDob(std::string dob){_dob = dob;}
void Customer::setCity(std::string city){_city = city;}
void Customer::setPinCode(std::string pin_code){_pin_code = pin_code;}
void Customer::setLogin(std::string login){_login = login;}
void Customer::setPassword(std::string password){_password = password;}
void Customer::setAdmin(std::string admin){_admin = admin;}



std::string Customer::getId(){return _id;}
std::string Customer::getName(){return _name;}
std::string Customer::getEmail(){return _email;}
std::string Customer::getPhone(){return _phone;}
std::string Customer::getDob(){return _dob;}
std::string Customer::getCity(){return _city;}
std::string Customer::getPinCode(){return _pin_code;}
std::string Customer::getLogin(){return _login;}
std::string Customer::getPassword(){return _password;}
std::string Customer::getAdmin(){return _admin;}
