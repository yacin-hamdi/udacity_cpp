#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<string>
#include<mysql/mysql.h>
#include<vector>


class Transaction{
    public:
        Transaction(std::string transaction_id, std::string account_id, std::string from,
                std::string to, std::string date, std::string amount);
        Transaction(){}

        std::string getTransactionId();
        std::string getAccountId();
        std::string getFrom();
        std::string getTo();
        std::string getDate();
        std::string getAmount();
        std::vector<std::string> getTransactionDetails();

        void setTransactionId(std::string transaction_id);
        void setAccountId(std::string account_id);
        void setFrom(std::string from);
        void setTo(std::string to);
        void setDate(std::string date);
        void setAmount(std::string amount);
        void setTransactionsDetails(MYSQL_ROW row);

    private:
        std::string _transaction_id;
        std::string _account_id;
        std::string _from;
        std::string _to;
        std::string _date;
        std::string _amount;
};


#endif