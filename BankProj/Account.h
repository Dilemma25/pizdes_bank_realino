#pragma once

#include"Transaction.h"

#include<vector>
#include<utility>

#include<nlohmann/json.hpp>

class Account {
private:
    std::string accountId;
    std::string name;
    double balance;
    std::vector<Transaction*> userAccountTransactions;
    

    int decreaseBalance(double sum);
    std::string createAccountId();

public:
    Account(std::string fistName, double money);

    Account(std::string id, std::string firstName, double money);

    void insertBalance(double sum);

    void transferMoney(Account* recipientAccount, double sum);

    std::vector<Transaction> showTransactionInUserInterval(std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> start,
                                                            std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> end);
    

    double getBalance();
    std::string getName();
    std::string getId();
    std::vector<Transaction> getTransactions();

    nlohmann::ordered_json toJson();

    friend std::ostream& operator << (std::ostream& os, const Account& account);

    void addTransaction(Transaction*);
};