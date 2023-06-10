#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H


#include<string>
#include<mysql/mysql.h>
#include<mysql/mysqld_error.h>
#include "customer.h"
#include "databasedetails.h"
#include "constants.h"
#include <vector>


class DatabaseHelper{
    public:
        DatabaseHelper(std::string filename);
        DatabaseHelper(){}

        void setDetailsFromFile(std::string filename);

        void dbConnect();
        int addUser(Customer &customer);
        bool removeUser(std::string id);
        bool closeMyAccount(std::string username, std::string password);
        bool updateUser(std::string column, std::string value, std::string login);
        
        void getAllUser();
        bool checkLogin(std::string username, std::string password);

        //accessor
        bool isConnected();
        MYSQL* getMysqlConnection();
        std::vector<std::string> getUserDetails();
        std::vector<std::vector<std::string>> getAllUserDetails();

    private:



        Details _database_details;
        std::vector<std::string> _user_details;
        std::vector<std::vector<std::string>> _all_users_details;

        MYSQL* _connection;
        MYSQL_RES *_res;
        MYSQL_ROW _row;
        std::string _query;
        bool _success;
        const unsigned int PORT = 0;


};

#endif