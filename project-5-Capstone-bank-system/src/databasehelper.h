#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H


#include<string>
#include<mysql/mysql.h>
#include<mysql/mysqld_error.h>
#include "customer/customer.h"
#include "customer/customerdbhelper.h"
#include "account/account.h"
#include "account/accountdbhelper.h"
#include "transaction/transaction.h"
#include "transaction/transactiondbhelper.h"
#include "utils/databasedetails.h"
#include "utils/constants.h"
#include <vector>


class DatabaseHelper{
    public:
        DatabaseHelper();

        bool dbConnect();
        bool addUser(Customer &customer, Account &Account);
        bool removeUser(std::string id);
        bool updateUser(std::string column, std::string value, std::string login);
        bool addTransaction(Transaction &transaction);
        
        bool getAllUser();
        bool checkLogin(std::string username, std::string password);
        void setAccountDetails(std::string number, std::string column, std::string value);

        //accessor
        bool isConnected();
        MYSQL* getMysqlConnection();
        std::vector<std::string> getUserDetails();
        std::vector<std::vector<std::string>> getAllUserDetails();

        Customer getCustomerDetails();
        std::vector<Customer> getAllCustomerDetails();
        
        Account getAccountDetails(std::string, std::string);
        std::vector<Account> getAllAccountDetails();
        std::vector<Transaction>getTransactionDetails();
        

    private:
        CustomerDBHelper _customer_db;
        AccountDBHelper _account_db;
        TransactionDBHelper _transaction_db;

        Customer _customer;
        Account _account;
        Transaction _transaction;
        



        Details _database_details;
        std::vector<std::string> _user_details;
        std::vector<std::vector<std::string>> _all_users_details;
        


        MYSQL* _connection;
        
        bool _success;
        bool _state;
        const unsigned int PORT = 0;
        std::string _query;
        MYSQL_RES *_res;
        MYSQL_ROW _row; 

    


};

#endif