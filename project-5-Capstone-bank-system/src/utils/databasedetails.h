#ifndef DATABASEDETAILS_H
#define DATABASEDETAILS_H

#include<string>

class Details{
    public:
        Details(){}
        void setDetailsFromFile();

        std::string getHostname();
        std::string getUser();
        std::string getPassword();
        std::string getDatabase();


    private:
        std::string _hostname;
        std::string _user;
        std::string _password;
        std::string _database;
};

#endif