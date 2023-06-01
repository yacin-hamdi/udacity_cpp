#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H


#include<string>
#include<mysql/mysql.h>
#include<mysql/mysqld_error.h>
#include "customer.h"
#include "databasedetails.h"

class DatabaseHelper{
    public:
        DatabaseHelper(std::string filename);
        DatabaseHelper(){}

        void setDetailsFromFile(std::string filename);

        void dbConnect();
        int insertData(Customer customer, std::string table_name);
        void displayData(std::string table_name);
        bool checkLogin(std::string table_name, std::string username, std::string password);

        //accessor
        bool isConnected();
        MYSQL* getMysqlConnection();

    private:
        Details _details;

        MYSQL* _connection;
        MYSQL_RES *_res;
        MYSQL_ROW _row;
        std::string _query;
        bool _success;
        const unsigned int PORT = 0;


};

#endif