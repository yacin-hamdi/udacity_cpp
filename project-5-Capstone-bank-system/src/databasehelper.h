#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H


#include<string>
#include<mysql/mysql.h>
#include<mysql/mysqld_error.h>
#include "customer.h"

class DatabaseHelper{
    public:
        DatabaseHelper(std::string filename);
        DatabaseHelper(){}

        void setDetailsFromFile(std::string filename);

        void dbConnect();
        int insertData(Customer customer, std::string table_name);
        void displayData(std::string table_name);

        //accessor
        bool isConnected();
        MYSQL* getMysqlConnection();

    private:
        std::string _hostname;
        std::string _user;
        std::string _password;
        std::string _database;

        MYSQL* _connection;
        bool _success;
        const unsigned int PORT = 0;


};

#endif