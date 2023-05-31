#include "databasehelper.h"
#include <iostream>
#include <fstream>


DatabaseHelper::DatabaseHelper(std::string filename){
    DatabaseHelper::setDetailsFromFile(filename);
}

void DatabaseHelper::setDetailsFromFile(std::string filename){
    std::ifstream file(filename);
    std::string line;
    std::string name;

    if(file){
        while(getline(file, line)){
            name = line.substr(line.find("::")+2, line.size());
        if( line.substr(0, line.find("::")) == "hostname")
            this->_hostname = name;
        else if(line.substr(0, line.find("::")) == "user")
            this->_user = name;
        else if(line.substr(0, line.find("::")) == "password")
            this->_password = name;
        else if(line.substr(0, line.find("::")) == "database")
            this->_database = name;
    }
    }else{
        throw std::runtime_error("file not found");
    }
    
}

int DatabaseHelper::insertData(Customer customer, std::string table_name){

    std::string query = "INSERT INTO customer(name, email, phone, dob, city, pincode, login, password)";
                query += "VALUES ('"+customer.getName()+"', '"+customer.getEmail()+"', '"+customer.getPhone()+"', ";
                query += "'"+customer.getDob()+"', '"+customer.getCity()+"', '"+customer.getPinCode()+"',";
                query += "'"+customer.getLogin()+"', '"+customer.getPassword()+"');";

    std::cout << query << std::endl;
    int state = mysql_query(_connection, query.c_str());
    return state;
}

void DatabaseHelper::displayData(std::string table_name){
    MYSQL_ROW row;
    std::string query = "select * from " + table_name;
    int state = mysql_query(_connection, query.c_str());
    if (state == 0){
        MYSQL_RES * res = mysql_store_result(_connection);
        int count = mysql_num_fields(res);
        while(row = mysql_fetch_row(res)){
            for(int i = 0;i<count;i++){
                std::cout  << row[i] << "\t";
            }
            std::cout << std::endl;
        }

    }
   
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


