#ifndef BASE_H
#define BASE_H
#include "databasehelper.h"
#include "interface.h"


class Base{
    public:
        Base(){}
        void start();

    private:
        void closeAccount();
        void deleteUser();
        void addAccount();
        void userAccount();
        void adminAccount();
        void login();
        void sendMoney();

        Interface _interface;
        DatabaseHelper _dbHelper;
        bool _login_success = false;
        bool _is_connected = false;
        int _num = 0;
        bool _exit = false;
        Auth _auth;
        std::vector<Customer> _all_customer_details;
        std::vector<Account> _all_account_details;
        std::vector<Transaction> _all_transaction_details;
        Customer _customer_details;
        Account _account_details;
        Transaction _transaction_details;
        
    
        std::vector<std::string> _temp;
        int _temp_int;
        bool _state;
        
};

#endif