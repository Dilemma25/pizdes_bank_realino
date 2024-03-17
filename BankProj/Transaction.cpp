#include "Transaction.h"

Transaction::Date::Date() {
    this->yearMonthDay = countYearMonthDay();
    this->hourMinuteSecond = countHourMinuteSeconds();
};

Transaction::Date::Date(std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> date) {
    this->yearMonthDay = date.first;
    this->hourMinuteSecond = date.second;
};


std::chrono::year_month_day Transaction::Date::getYearMonthDay() {
    return this->yearMonthDay;
}


std::chrono::hh_mm_ss<std::chrono::seconds> Transaction::Date::getHourMinuteSecond() {
    return this->hourMinuteSecond;
}


std::chrono::year_month_day Transaction::Date::countYearMonthDay() {
    auto now = std::chrono::system_clock::now();
    std::time_t nowTimeT = std::chrono::system_clock::to_time_t(now);
    std::tm timeObject;

    localtime_s(&timeObject, &nowTimeT);

    std::chrono::year_month_day yearMonthDay = std::chrono::year_month_day{
        std::chrono::year{timeObject.tm_year + 1900},
        std::chrono::month{static_cast<unsigned int>(timeObject.tm_mon) + 1},
        std::chrono::day{static_cast<unsigned int>(timeObject.tm_mday)}
    };

    return yearMonthDay;
}


std::chrono::hh_mm_ss<std::chrono::seconds> Transaction::Date::countHourMinuteSeconds() {
    auto now = std::chrono::system_clock::now();
    std::time_t nowTimeT = std::chrono::system_clock::to_time_t(now);

    std::tm timeObject;
    localtime_s(&timeObject, &nowTimeT);

    std::chrono::hh_mm_ss<std::chrono::seconds> hourMinuteSeconds = std::chrono::hh_mm_ss<std::chrono::seconds>{
        std::chrono::hours{timeObject.tm_hour} +
        std::chrono::minutes{timeObject.tm_min} +
        std::chrono::seconds{timeObject.tm_sec}
    };

    return hourMinuteSeconds;
}


std::string Transaction::createTransctionId()
{
    auto currentTime = std::chrono::system_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime.time_since_epoch()).count();

    std::string durationString = std::to_string(duration);

    std::string resultId = durationString.substr(4, 14);

    return resultId;
}


std::string Transaction::getSenderId()
{
    return this->senderId;
}

std::string Transaction::getSenderName()
{
    return this->senderName;
}

std::string Transaction::getRecipientId()
{
    return this->recipientId;
}

std::string Transaction::getRecipientName()
{
    return this->recipientName;
}

double Transaction::getAmount()
{
    return this->amount;
}

std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> Transaction::getDate()
{
    std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> date(this->date.getYearMonthDay(), this->date.getHourMinuteSecond());
    return date;
}

Transaction::Transaction() : transactionId{}, senderId{}, senderName{}, recipientId{}, recipientName{}, amount{}, date{} {};


Transaction::Transaction(std::string senderId, std::string senderName, std::string recipientId, std::string recipientName, double sum) : transactionId(createTransctionId()), senderId(senderId),
                                                                                                            senderName(senderName), recipientId(recipientId),
                                                                                                            recipientName(recipientName),
                                                                                                            amount(sum),
                                                                                                            date(Date()) {}

Transaction::Transaction(std::string transactionId, std::string senderId, std::string senderName, std::string recipientId, std::string repicientName, double sum, Date date) : Transaction(senderId, senderName, recipientId, repicientName, sum)
{
    this->transactionId = transactionId;
    this->date = date;
}
                                                                                           


std::ostream& operator<<(std::ostream& os, Transaction& transaction) {
    return os << "Transaction_ID: " << transaction.transactionId
        << " Sender_ID: " << transaction.senderId
        << " Sender_Name: " << transaction.senderName 
        << " Recipient_ID: " << transaction.recipientId
        << " Recipient_Name: " << transaction.recipientName
        << " Amount: " << transaction.amount << " Date: " << transaction.date.getYearMonthDay()
        << " " << transaction.date.getHourMinuteSecond() << '\n';
}




