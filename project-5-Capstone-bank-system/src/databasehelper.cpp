#include "databasehelper.h"
#include<iostream>


DatabaseHelper::DatabaseHelper(){
    _database_details.setDetailsFromFile();
}
//todo
//need two helper function
//first one to return today date
//second to check the account number increament it by one and return it
bool DatabaseHelper::addUser(Customer &customer, Account &account){
    _state = _customer_db.addCustomerDB(getMysqlConnection(), customer) &&
             _account_db.addAccountDB(getMysqlConnection(), account);
    std::cout << _state << std::endl;

    return _state;
}

//todo 
//need to check if the account have admin priviliges if not we delete it
bool DatabaseHelper::removeUser(std::string id){
    getAllUser();
    for(int i=0;i<getAllCustomerDetails().size();i++){
        if(getAllCustomerDetails()[i].getId() == id){
            if(getAllCustomerDetails()[i].getAdmin() == ADMIN_PRIVILEGE){
                return false;
            }
            _state = _customer_db.removeCustomerDB(getMysqlConnection(), id);   
            
            break;
        }
    }
    
    return _state;
}



    

    

bool DatabaseHelper::getAllUser(){
    _state = _customer_db.getAllCustomerDB(getMysqlConnection());

    return _state;
}


//done
bool DatabaseHelper::checkLogin(std::string login, std::string password){
    _state = _customer_db.getCustomerDB(getMysqlConnection(), login, password);
    
    return _state;
}




bool DatabaseHelper::dbConnect(){
    _connection = mysql_init(0);
    _connection = mysql_real_connect(_connection, _database_details.getHostname().c_str(),
     _database_details.getUser().c_str(), _database_details.getPassword().c_str(), _database_details.getDatabase().c_str(), 0, NULL, 0);

     if(_connection)
        _success = true;
     else
        _success = false;
     return _success;
}

//done

bool DatabaseHelper::updateUser(std::string column, std::string value, std::string login){
    _state = _customer_db.updateCustomerDB(getMysqlConnection(), login, column, value);
    
    return _state;
}

bool DatabaseHelper::addTransaction(Transaction &transaction){
    _state = _transaction_db.addTransactionDB(getMysqlConnection(), transaction);
    return _state;
}




MYSQL* DatabaseHelper::getMysqlConnection(){return _connection;}
bool DatabaseHelper::isConnected(){return _success;}
void DatabaseHelper::setAccountDetails(std::string number, std::string column, std::string value)
{
    _account_db.updateAccountDB(getMysqlConnection(), number, column, value);
}
Customer DatabaseHelper::getCustomerDetails(){
    _customer_db.getCustomerDB(getMysqlConnection(), _customer_db.getCustomer().getLogin(), 
                                _customer_db.getCustomer().getPassword());
    return _customer_db.getCustomer();

    }
Account DatabaseHelper::getAccountDetails(std::string column, std::string value){
    _account_db.getAccountDB(getMysqlConnection(), column, value);
    return _account_db.getAccount();}

std::vector<Customer> DatabaseHelper::getAllCustomerDetails(){
    _customer_db.getAllCustomerDB(getMysqlConnection());
    return _customer_db.getAllCustomer();
    }
std::vector<Account> DatabaseHelper::getAllAccountDetails(){
    _account_db.getAllAccountDB(getMysqlConnection());
    return _account_db.getAllAccount();
    }

std::vector<Transaction> DatabaseHelper::getTransactionDetails(){
    _state = _account_db.getAccountDB(getMysqlConnection(), "username", _customer_db.getCustomer().getLogin());
    _state  = _transaction_db.getTransactionDB(getMysqlConnection(),"from", _account_db.getAccount().getNumber());
    return _transaction_db.getAllTransaction();
    
}



