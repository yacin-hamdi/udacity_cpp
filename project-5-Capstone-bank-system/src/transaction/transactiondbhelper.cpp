#include "transactiondbhelper.h"
#include "../utils/constants.h"
#include <iostream>

bool TransactionDBHelper::addTransactionDB(MYSQL *CONN, Transaction &transaction){
    _query = "INSERT INTO " + _TRANSACTION_TABLE + "(account_id, from_account, to_account,";
    _query += "transaction_date, transaction_amount)";
    _query += "VALUES ('"+transaction.getAccountId()+"', '"+transaction.getFrom()+"', ";
    _query += "'"+transaction.getTo()+"', '"+transaction.getDate()+"', '"+transaction.getAmount()+"')";
    _state = mysql_query(CONN, _query.c_str());
    return _state == 0;
}

bool TransactionDBHelper::getTransactionDB(MYSQL *CONN, std::string column, std::string number){
    _query = "select * from " + TRANSACTION_TABLE+" where from_account='"+number+"'or to_account='"+number+"'";
    std::cout << _query << std::endl;
    _all_transaction.clear();
    if(mysql_query(CONN, _query.c_str()) == 0){
        _res = mysql_store_result(CONN);
        int count = mysql_num_fields(_res);
        while(_row = mysql_fetch_row(_res)){
            _transaction.setTransactionsDetails(_row);
            _all_transaction.push_back(_transaction);
        }
        std::cout << "hello" << std::endl;

        return true;
    }
    return false;
}

bool TransactionDBHelper::removeTransactionDB(MYSQL *CONN, std::string transaction_id){
    _query = "delete from " + _TRANSACTION_TABLE + " where transaction_id='"+transaction_id+"'";
    _state = mysql_query(CONN, _query.c_str());
    return mysql_affected_rows(CONN);
}

bool TransactionDBHelper::updateTransactionDB(MYSQL *CONN, std::string transaction_id, std::string column, std::string value){
    _query = "UPDATE "+_TRANSACTION_TABLE+" SET "+column+"='"+value+"' WHERE transaction_id='"+transaction_id+"'";
    _state = mysql_query(CONN, _query.c_str());
    if(_state == 0){
        if(mysql_affected_rows(CONN) != 0)
            return true;
    }
    
    return false;
}



bool TransactionDBHelper::getAllTransactionDB(MYSQL *CONN){
    _query = "select * from " + _TRANSACTION_TABLE;
    _all_transaction.clear();
    _state = mysql_query(CONN, _query.c_str());
    if (_state == 0){
        _res = mysql_store_result(CONN);
        int count = mysql_num_fields(_res);
        while(_row = mysql_fetch_row(_res)){
            for(int i=0;i<count;i++)
                std::cout << _row << " ";
            std::cout << std::endl;
            _transaction.setTransactionsDetails(_row);
            _all_transaction.push_back(_transaction);
        }

        return true;
    }

    return false;
}

bool TransactionDBHelper::getTransactionDB(MYSQL *CONN, std::string account_id){
    _query = "select * from " + _TRANSACTION_TABLE + " where account_id='" + account_id + "'";
    _all_transaction.clear();
    _state = mysql_query(CONN, _query.c_str());
    if (_state == 0){
        _res = mysql_store_result(CONN);
        int count = mysql_num_fields(_res);
        while(_row = mysql_fetch_row(_res)){
            _transaction.setTransactionsDetails(_row);
            _all_transaction.push_back(_transaction);
        }

        return true;
    }

    return false;
}


std::vector<Transaction> TransactionDBHelper::getAllTransaction(){return _all_transaction;}