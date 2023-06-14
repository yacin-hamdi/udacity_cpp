#include "accountdbhelper.h"
#include "iostream"
Account AccountDBHelper::getAccountDetails(std::string username){
    _query = "select * from "+ACCOUNT_TABLE+" where username ='"+username+"'";
    _database_details.setDetailsFromFile(DATABASE_DETAILS);
    dbConnect();
    
    std::cout << "hello" << std::endl;
    std::cout << _success << std::endl;
    if(mysql_query(_connection, _query.c_str()) == 0){
        std::cout << "hello" << std::endl;
        _res = mysql_store_result(_connection);
        _row = mysql_fetch_row(_res);
        _account.setNumber(_row[0]);
        _account.setUsername(_row[1]);
        _account.setBalance(_row[2]);
        _account.setCreationDate(_row[3]);
        _account.setType(_row[4]);
        _account.setStatus(_row[5]);
    }
    

    return _account;
}