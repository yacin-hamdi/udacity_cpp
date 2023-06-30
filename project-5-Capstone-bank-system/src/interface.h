#ifndef INTERFACE_H
#define INTERFACE_H

#include<iostream>
#include<vector>
#include "utils/constants.h"
#include "customer/customer.h"
#include "account/account.h"
#include "transaction/transaction.h"
#include "utils/TextTable.h"
#include "transaction/transaction.h"


struct Auth{
        std::string username;
        std::string password;
    };

class Interface{
    public:
        Auth loginInterface();
        bool loginSuccess(bool &success);
        bool connectToDatabaseInterface(bool &connected);
        Interface();
        int adminInterface();
        int userAccountDetailsInterface(Customer&, Account&);
        int allUserAccountDetailsInterface(std::vector<Customer>&, std::vector<Account>&);

        int deleteUserInterface(std::vector<Customer> &);
        int deleteUserSuccessInterface(bool &success);
        
        std::vector<std::string> updateAdminUserInterface();
        std::vector<std::string> updateUserInterface();
        std::string closeAccountInterface();
        void byeAccountInterface();
        Customer addUserInterface();
        Account addAccountInterface();
        Transaction sendMoneyInterface();

        int addUserSuccess(bool &state);
        int updateUserSuccess(bool &state);
        int sendMoneySuccess(bool &state);
        int userInterface();
        int TransactionHistoInterface(std::vector<Transaction>);
        template<typename t> int showTable(std::vector<t> vec);

    private:
    Auth _auth;
    std::string _temp;
    Customer _customer;
    Account _account;
    Transaction _transaction;
    std::vector<std::string> _details_temp;
};



#endif