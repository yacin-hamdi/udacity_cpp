#ifndef TRANSACTIONDBHELPER_H
#define TRANSACTIONDBHELPER_H

#include "transaction.h"
#include<mysql/mysql.h>

class TransactionDBHelper{
    public:
        bool getTransactionDB(MYSQL *CONN, std::string account_id);
        bool addTransactionDB(MYSQL *CONN, Transaction &transaction);
        bool removeTransactionDB(MYSQL *CONN, std::string transaction_id);
        bool updateTransactionDB(MYSQL *CONN, std::string transaction_id, std::string column, std::string value);
        bool getAllTransactionDB(MYSQL *CONN);
        bool getTransactionDB(MYSQL *CONN,  std::string column, std::string number);

        std::vector<Transaction> getAllTransaction();
    
    private:
        Transaction _transaction;
        const std::string _TRANSACTION_TABLE = "transaction";
        std::string _query;
        int _state;
        MYSQL_RES *_res;
        MYSQL_ROW _row;
        std::vector<Transaction> _all_transaction;

};

#endif