#include "databasehelper.h"
#include <iostream>


DatabaseHelper::DatabaseHelper(std::string hostname, 
std::string user, std::string password, std::string database){
    DatabaseHelper::setDetails(hostname, user, password, database);
}

void DatabaseHelper::setDetails(std::string hostname, std::string user,
    std::string password, std::string database){
    this->_hostname = hostname;
    this->_user = user;
    this->_password = password;
    this->_database = database;
}

// ("mike", "wowzowski", "mike@gmail.com", "password")
int DatabaseHelper::insertData(Client user, std::string table_name){
    // INSERT INTO tblUsers(name, surname, email, password) VALUES ("mike", "wowzowski", "mike@gmail.com", "password");

    std::string query = "insert into "+table_name+""+
                        "(accountnum, username, name, email, password) values "+
                        "('"+user.getAccountNum()+"','"+user.getUsername()+"','"+user.getName()+"'"+
                        ",'"+user.getEmail()+"', '"+user.getPassword()+"')";
    std::cout << query << std::endl;
    int state = mysql_query(_connection, query.c_str());
    return state;
}

void DatabaseHelper::dbConnect(){
    _connection = mysql_init(0);
    _connection = mysql_real_connect(_connection, _hostname.c_str(),
     _user.c_str(), _password.c_str(), _database.c_str(), 0, NULL, 0);

     if(_connection)
        _success = true;
     else
        _success = false;
     
}

MYSQL* DatabaseHelper::getMysqlConnection(){return _connection;}
bool DatabaseHelper::isConnected(){return _success;}


