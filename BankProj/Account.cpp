#include"Account.h"

std::string Account::createAccountId() {
    auto currentTime = std::chrono::system_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime.time_since_epoch()).count();

    std::string durationString = std::to_string(duration);

    std::string resultId = durationString.substr(3, 8);

    return resultId;
}

Account::Account(std::string fistName, double money) : accountId(createAccountId()), name(fistName), balance(money) {};// вот этот

Account::Account(std::string id, std::string firstName, double money) : accountId(id), name(firstName), balance(money) {};


double Account::getBalance() {
    return this->balance;
};


std::string Account::getId() {
    return this->accountId;
};


std::string Account::getName() {
    return this->name;
}


std::ostream& operator<<(std::ostream& os,const Account& account)
{
    return os << "id: " << account.accountId << " name: " << account.name << " balance: " << account.balance << '\n';
}


nlohmann::ordered_json Account::toJson() {
    nlohmann::ordered_json accountJson = {
        {"name", this->name},
        {"id", this->accountId},
        {"balance", this->balance}
    };

    return accountJson;
};


void Account::insertBalance(double sum) {
    this->balance += sum;
};


int Account::decreaseBalance(double sum) {
    if ((balance - sum) < 0) {
        return -1;
    }

    this->balance -= sum;
    return 0;
}


void Account::transferMoney(Account* recipientAccount ,double sum) {

    int errorCode = this->decreaseBalance(sum);

    if (errorCode == -1) {
        throw std::invalid_argument("not enough funds!");
    }


    recipientAccount->insertBalance(sum);
};

bool operator > (std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> transactionDate, std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> userInputDate)
{
    if (transactionDate.first.year() > userInputDate.first.year()) {
        return true;
    }
    else if (transactionDate.first.month() > userInputDate.first.month()) {
        return true;
    }
    else if (transactionDate.first.day() > userInputDate.first.day()) {
        return true;
    }
    else if (transactionDate.second.hours() > userInputDate.second.hours()) {
        return true;
    }
    else if (transactionDate.second.minutes() > userInputDate.second.minutes()) {
        return true;
    }
    else if (transactionDate.second.seconds() > userInputDate.second.seconds()) {
        return true;
    }
    else {
        return false;
    }
}

bool operator<(std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> transactionDate, std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> userInputDate)
{
    return (!(transactionDate > userInputDate));
}



std::vector<Transaction> Account::showTransactionInUserInterval(std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> start,
    std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> end) {

    std::vector<Transaction> transactionInUserInterval;

    for (Transaction* transaction : userAccountTransactions) {
        if (transaction->getDate() > start || transaction->getDate() < end) {
            transactionInUserInterval.push_back(*transaction);
        }
    }

    return transactionInUserInterval;
};

void Account::addTransaction(Transaction* transaction) {
    this->userAccountTransactions.push_back(transaction);
}

std::vector<Transaction> Account::getTransactions() {
    std::vector<Transaction> transactionsCopies;
    for (Transaction* transaction : userAccountTransactions) {
        transactionsCopies.push_back(*transaction);
    }
    
    return transactionsCopies;
}