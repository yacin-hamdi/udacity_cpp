#ifndef USER_H
#define USER_H

#include <string>
#include<vector>
#include<mysql/mysql.h>

class Customer{
    public:
        Customer(std::string id, std::string name, 
                std::string email, std::string phone,
                std::string dob, std::string city, 
                std::string pin_code,std::string login, 
                std::string password,std::string admin
        );

        Customer(){}
        
        void setId(std::string id);
        void setName(std::string name);
        void setEmail(std::string email);
        void setPhone(std::string phone);
        void setDob(std::string dob);
        void setCity(std::string city);
        void setPinCode(std::string pin_code);
        void setLogin(std::string login);
        void setPassword(std::string password);
        void setAdmin(std::string admin);
        void setAllDetails(MYSQL_ROW row);
        
        std::string getId();
        std::string getName();
        std::string getEmail();
        std::string getPhone();
        std::string getDob();
        std::string getCity();
        std::string getPinCode();
        std::string getLogin();
        std::string getPassword();
        std::string getAdmin();
        std::vector<std::string> getAllDetails();
        

    private:
        std::string _id;
        std::string _name;
        std::string _email;
        std::string _phone;
        std::string _dob;
        std::string _city;
        std::string _pin_code;
        std::string _login;
        std::string _password;
        std::string _admin;
        
        
        
};

#endif