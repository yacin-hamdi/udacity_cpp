#include "accountdbhelper.h"
#include "iostream"
bool AccountDBHelper::getAccountDB(MYSQL *CONN, std::string column, std::string value){
    _query = "select * from "+_ACCOUNT_TABLE+" where "+column+"='"+value+"'";    
   
    if(mysql_query(CONN, _query.c_str()) == 0){
        _res = mysql_store_result(CONN);
        _row = mysql_fetch_row(_res);
        if(mysql_affected_rows(CONN)){
            _account.setAccountDetails(_row);
            return true;
        }
        
    }
    

    return false;
}



bool AccountDBHelper::addAccountDB(MYSQL *CONN, Account &account){
    _query = "INSERT INTO " + _ACCOUNT_TABLE + "(number, username, balance, aod, type, status)";
    _query += "VALUES ('"+account.getNumber()+"', '"+account.getUsername()+"', '"+account.getBalance()+"', ";
    _query += "'"+account.getCreationDate()+"', '"+account.getType()+"', '"+account.getStatus()+"')";
    std::cout << _query << std::endl;
    _state = mysql_query(CONN, _query.c_str());
    return _state == 0;
}

bool AccountDBHelper::removeAccountDB(MYSQL *CONN, std::string account_number){
    _query = "delete from " + _ACCOUNT_TABLE + " where number='"+account_number+"'";
    std::cout << _query << std::endl;
    _state = mysql_query(CONN, _query.c_str());
    std::cout << _state << std::endl;
    return mysql_affected_rows(CONN);
}

bool AccountDBHelper::updateAccountDB(MYSQL *CONN, std::string account_number, std::string column, std::string value){
    _query = "UPDATE "+_ACCOUNT_TABLE+" SET "+column+"='"+value+"' WHERE number='"+account_number+"'";
    std::cout << _query << std::endl;
    _state = mysql_query(CONN, _query.c_str());
    if(_state == 0){
        if(mysql_affected_rows(CONN) != 0)
            return true;
    }
    
    return false;
}

bool AccountDBHelper::getAllAccountDB(MYSQL *CONN){
     _query = "select * from " + _ACCOUNT_TABLE;
    _all_account.clear();
    _state = mysql_query(CONN, _query.c_str());
    if (_state == 0){
        _res = mysql_store_result(CONN);
        int count = mysql_num_fields(_res);
        while(_row = mysql_fetch_row(_res)){
            _account.setAccountDetails(_row);
            _all_account.push_back(_account);
        }

        return true;
    }

    return false;
}


Account AccountDBHelper::getAccount(){return _account;}
std::vector<Account> AccountDBHelper::getAllAccount(){return _all_account;}