#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H


#include<string>
#include<mysql/mysql.h>
#include<mysql/mysqld_error.h>
#include "client.h"

class DatabaseHelper{
    public:
        DatabaseHelper(std::string hostname, std::string user, 
        std::string password, std::string database);

        void setDetails(std::string hostname, std::string user, 
        std::string password, std::string database);

        void dbConnect();
        int insertData(Client user, std::string table_name);
        

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