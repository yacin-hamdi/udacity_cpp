#include "databasehelper.h"
#include<iostream>


DatabaseHelper::DatabaseHelper(std::string filename){
    _database_details.setDetailsFromFile(filename);
}


int DatabaseHelper::addUser(Customer &customer){

    std::string query = "INSERT INTO " + CUSTOMER_TABLE + "(name, email, phone, dob, city, pincode, login, password, admin)";
                query += "VALUES ('"+customer.getName()+"', '"+customer.getEmail()+"', '"+customer.getPhone()+"', ";
                query += "'"+customer.getDob()+"', '"+customer.getCity()+"', '"+customer.getPinCode()+"',";
                query += "'"+customer.getLogin()+"', '"+customer.getPassword()+"', '"+customer.getAdmin()+"');";

    int state = mysql_query(_connection, query.c_str());
    return state;
}

bool DatabaseHelper::removeUser(std::string id){
    bool done = false;

    _query = "delete from " + CUSTOMER_TABLE + " where id='"+id+"'";
    int state = mysql_query(_connection, _query.c_str());
    done = mysql_affected_rows(_connection);
    return done;
}

bool DatabaseHelper::closeMyAccount(std::string username, std::string password){
    bool close = false;
    if(username == _user_details[7] && password == _user_details[8]){
        _query = "delete from " + CUSTOMER_TABLE + " where login='"+username+"' and password='"+password+"'";
        int state = mysql_query(_connection, _query.c_str());
        close = mysql_affected_rows(_connection);
    
    }
    return close;
}

    

    

void DatabaseHelper::getAllUser(){
    _query = "select * from " + CUSTOMER_TABLE;
    std::vector<std::string> temp;
    _all_users_details.clear();
    int state = mysql_query(_connection, _query.c_str());
    if (state == 0){
        _res = mysql_store_result(_connection);
        int count = mysql_num_fields(_res);
        while(_row = mysql_fetch_row(_res)){
            for(int i = 0;i<count;i++){
                temp.push_back(_row[i]);
            }
            
            _all_users_details.push_back(temp);
            temp.clear();
        }

    }


   
}



bool DatabaseHelper::checkLogin(std::string username, std::string password){
    _query = "select * from "+CUSTOMER_TABLE+" where login='"+username+"' and password='"+password+"'";
    bool success = false;
    if(mysql_query(_connection, _query.c_str()) == 0){
        _res = mysql_store_result(_connection);
        int count = mysql_num_rows(_res);
        if(count){
            _row = mysql_fetch_row(_res);
            int field_count = mysql_num_fields(_res);
            success = username == _row[7] && password == _row[8];
            if(success){
                for(int i = 0; i < field_count; i++){
                    _user_details.push_back(_row[i]);
                }

            }
            
        }
    }
    return success;
}




void DatabaseHelper::dbConnect(){
    _connection = mysql_init(0);
    _connection = mysql_real_connect(_connection, _database_details.getHostname().c_str(),
     _database_details.getUser().c_str(), _database_details.getPassword().c_str(), _database_details.getDatabase().c_str(), 0, NULL, 0);

     if(_connection)
        _success = true;
     else
        _success = false;
     
}

bool DatabaseHelper::updateUser(std::string column, std::string value, std::string login){
    _query = "UPDATE "+CUSTOMER_TABLE+" SET "+column+"='"+value+"' WHERE login='"+login+"'";
    int state = mysql_query(_connection, _query.c_str());
    if(state == 0){
        if(mysql_affected_rows(_connection) != 0)
            return true;
    }
    
    return false;
}




MYSQL* DatabaseHelper::getMysqlConnection(){return _connection;}
bool DatabaseHelper::isConnected(){return _success;}
std::vector<std::string> DatabaseHelper::getUserDetails(){return _user_details;}
std::vector<std::vector<std::string>> DatabaseHelper::getAllUserDetails(){return _all_users_details;}


