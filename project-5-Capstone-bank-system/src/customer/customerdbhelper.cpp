#include"customerdbhelper.h"

#include<iostream>

bool CustomerDBHelper::addCustomerDB(MYSQL *CONN, Customer &customer){
    _query = "INSERT INTO " + _CUSTOMER_TABLE + "(name, email, phone, dob, city, pincode, login, password, admin)";
    _query += "VALUES ('"+customer.getName()+"', '"+customer.getEmail()+"', '"+customer.getPhone()+"', ";
    _query += "'"+customer.getDob()+"', '"+customer.getCity()+"', '"+customer.getPinCode()+"',";
    _query += "'"+customer.getLogin()+"', '"+customer.getPassword()+"', '"+customer.getAdmin()+"');";

    _state = mysql_query(CONN, _query.c_str());
    return _state == 0;
}

bool CustomerDBHelper::removeCustomerDB(MYSQL *CONN, std::string id){
    _query = "delete from " + _CUSTOMER_TABLE + " where id='"+id+"'";
    _state = mysql_query(CONN, _query.c_str());
    return mysql_affected_rows(CONN);
}

bool CustomerDBHelper::updateCustomerDB(MYSQL *CONN, std::string login, std::string column, std::string value){
    _query = "UPDATE "+_CUSTOMER_TABLE+" SET "+column+"='"+value+"' WHERE login='"+login+"'";
    _state = mysql_query(CONN, _query.c_str());
    if(_state == 0){
        if(mysql_affected_rows(CONN) != 0)
            return true;
    }
    
    return false;
}

bool CustomerDBHelper::getCustomerDB(MYSQL *CONN, std::string login, std::string password){
     _query = "select * from "+_CUSTOMER_TABLE+" where login='"+login+"' and password='"+password+"'";
     _state = mysql_query(CONN, _query.c_str());
    if(_state == 0){
        _res = mysql_store_result(CONN);
        _row = mysql_fetch_row(_res);
        if(mysql_affected_rows(CONN)){
            if(login == _row[7] && password == _row[8]){
                _customer.setAllDetails(_row);
                return true;
            }
                
        }
        
    }
    return false;
}

bool CustomerDBHelper::getAllCustomerDB(MYSQL *CONN){
    _query = "select * from " + _CUSTOMER_TABLE;
    _all_customer.clear();
    _state = mysql_query(CONN, _query.c_str());
    if (_state == 0){
        _res = mysql_store_result(CONN);
        int count = mysql_num_fields(_res);
        while(_row = mysql_fetch_row(_res)){
            _temp.setAllDetails(_row);
            _all_customer.push_back(_temp);
        }

        return true;
    }

    return false;

}

Customer CustomerDBHelper::getCustomer(){return _customer;}
std::vector<Customer> CustomerDBHelper::getAllCustomer(){return _all_customer;}
