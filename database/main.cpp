/*
CREATE TABLE `tblUsers` (
    `id` INT NOT NULL AUTO_INCREMENT,
    `name` varchar(30) NOT NULL,
    `surname` varchar(50) NOT NULL,
    `email` varchar(255) NOT NULL UNIQUE,
    `password` varchar(255) NOT NULL,
    PRIMARY KEY (`id`)
);

INSERT INTO tblUsers(name, surname, email, password) VALUES ("mike", "wowzowski", "mike@gmail.com", "password");
INSERT INTO tblUsers(name, surname, email, password) VALUES ("luke", "bordom", "luke@gmail.com", "password2");
INSERT INTO tblUsers(name, surname, email, password) VALUES ("sam", "dally", "sam@gmail.com", "password3");


 */

//ubuntu
//g++ main.cpp -o test `mysql_config --cflags --libs`

#include<iostream>
#include<mysql/mysql.h>
#include<mysql/mysqld_error.h>

struct SqlDetails{
    std::string host;
    std::string user;
    std::string password;
    std::string database;

    SqlDetails(std::string host, std::string user, std::string password, std::string database){
        this->host = host;
        this->user = user;
        this->password = password;
        this->database = database;
    }
};

/**
 * @brief
 * try to connect to mariadb database and return struct contain the connection and success
 * boolean which is true if the connection success
 * 
 * @param sql_details struct contain all the details needed to connect
 * @return  return struct contain connectin and success
*/
auto connectionSetup(SqlDetails sql_details){
    struct Result{
        bool success;
        MYSQL *connection;
    };

    Result result;
    result.success = true;
    result.connection = mysql_init(NULL);
    if(!mysql_real_connect(result.connection, sql_details.host.c_str(), sql_details.user.c_str(),
        sql_details.password.c_str(), sql_details.database.c_str(), 0, NULL, 0)){
            result.success = false;
            std::cout << "[error] " << mysql_error(result.connection) << std::endl;
        }

    return result;


}

/**
 * @brief
 * Execute a SQL query, will return a tuple, first value will be true if success
 *
 * @param connection SQL connection
 * @param query SQL query
 * @return result struct with success and res (result)
 */
auto sqlQuery(MYSQL *connection, std::string query){
    struct Result{
        bool success;
        MYSQL_RES *res;
    };

    Result result;
    result.success = true;

    if(mysql_query(connection, query.c_str())){
        result.success = false;
        std::cout << "[error] " << mysql_error(connection) << std::endl;
    }

    result.res = mysql_use_result(connection);
    return result;
}







int main(){
    SqlDetails sql_details("localhost", "yacin", "password", "test1");
    MYSQL_ROW row;
    auto connectionResult = connectionSetup(sql_details);

    if(!connectionResult.success){
        return 1;
    }
    std::cout << "connection success... \n";

    auto data = sqlQuery(connectionResult.connection, "select * from tblUsers");

    if(!data.success){
        return 1;
    }

    std::cout << "database output\n\n";

    while((row = mysql_fetch_row(data.res))!=NULL){
        std::cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << std::endl;
      }



    return 0;
}