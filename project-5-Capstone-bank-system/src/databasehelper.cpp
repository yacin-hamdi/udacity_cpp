#include "databasehelper.h"
#include <iostream>
#include <fstream>


DatabaseHelper::DatabaseHelper(std::string filename){
    _details.setDetailsFromFile(filename);
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
    _query = "select * from " + table_name;
    int state = mysql_query(_connection, _query.c_str());
    if (state == 0){
        _res = mysql_store_result(_connection);
        int count = mysql_num_fields(_res);
        while(_row = mysql_fetch_row(_res)){
            for(int i = 0;i<count;i++){
                std::cout  << _row[i] << "\t";
            }
            std::cout << std::endl;
        }

    }
   
}

bool DatabaseHelper::checkLogin(std::string table_name, std::string username, std::string password){
    _query = "select login, password from "+table_name+" where login='"+username+"' and password='"+password+"'";
    if(mysql_query(_connection, _query.c_str()) == 0){
        _res = mysql_store_result(_connection);
        int count = mysql_num_rows(_res);
        if(count){
            _row = mysql_fetch_row(_res);
            return _row[0] == username && _row[1] == password;
        }

        return false;
        
        
    }
    

    return false;
}



void DatabaseHelper::dbConnect(){
    _connection = mysql_init(0);
    _connection = mysql_real_connect(_connection, _details.getHostname().c_str(),
     _details.getUser().c_str(), _details.getPassword().c_str(), _details.getDatabase().c_str(), 0, NULL, 0);

     if(_connection)
        _success = true;
     else
        _success = false;
     
}




MYSQL* DatabaseHelper::getMysqlConnection(){return _connection;}
bool DatabaseHelper::isConnected(){return _success;}


