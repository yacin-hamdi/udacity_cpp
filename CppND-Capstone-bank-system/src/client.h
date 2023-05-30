#ifndef USER_H
#define USER_H

#include <string>

class Client{
    public:
        Client(std::string username, std::string name, std::string email, std::string password, std::string account_num);
        void setUsername(std::string username);
        void setName(std::string name);
        void setEmail(std::string email);
        void setPassword(std::string password);
        void setAccountNum(std::string account_num);
        
        std::string getUsername();
        std::string getName();
        std::string getEmail();
        std::string getPassword();
        std::string getAccountNum();

    private:
        std::string _username;
        std::string _name;
        std::string _email;
        std::string _password;
        std::string _account_num;
        
};

#endif