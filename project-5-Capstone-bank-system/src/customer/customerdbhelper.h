#ifndef CUSTOMERDBHELPER_H
#define CUSTOMERDBHELPER_H

#include<string> 
#include"customer.h"
#include <mysql/mysql.h>
#include <vector>

class CustomerDBHelper{
    public:
        bool addCustomerDB(MYSQL *CONN, Customer &customer);
        bool removeCustomerDB(MYSQL *CONN, std::string id);
        bool updateCustomerDB(MYSQL *CONN, std::string login, std::string column, std::string value);
        bool getCustomerDB(MYSQL *CONN, std::string login, std::string password);
        bool getAllCustomerDB(MYSQL *CONN);

        Customer getCustomer();
        std::vector<Customer> getAllCustomer();
    private:
        const std::string _CUSTOMER_TABLE = "customer";
        Customer _customer;
        Customer _temp;
        std::string _query;
        int _state;
        MYSQL_RES *_res;
        MYSQL_ROW _row;
        std::vector<Customer> _all_customer;



};


#endif