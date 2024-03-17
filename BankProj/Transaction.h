#pragma once
#include<iostream>
#include<chrono>
#include<sstream>

class Transaction {
public:
    struct Date {
    private:
        std::chrono::year_month_day yearMonthDay;
        std::chrono::hh_mm_ss<std::chrono::seconds> hourMinuteSecond;

    public:
        Date();

        Date(std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>>);

        std::chrono::year_month_day getYearMonthDay();

        std::chrono::hh_mm_ss<std::chrono::seconds> getHourMinuteSecond();


    private:
        std::chrono::year_month_day countYearMonthDay();

        std::chrono::hh_mm_ss<std::chrono::seconds> countHourMinuteSeconds();
    };

private:
    std::string transactionId;
    std::string senderId;
    std::string senderName;
    std::string recipientId;
    std::string recipientName;
    double amount;
    Date date;

    std::string createTransctionId();
    
public:

    std::string getSenderId();
    std::string getSenderName();
    std::string getRecipientId();
    std::string getRecipientName();
    double getAmount();
    std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> getDate();

    Transaction();

    Transaction(std::string senderId, std::string senderName, std::string recipientId, std::string repicientName, double sum);

    Transaction(std::string transactionId, std::string senderId, std::string senderName, std::string recipientId, std::string repicientName, double sum, Date date);

    friend std::ostream& operator<<(std::ostream& os, Transaction& transaction);

};

