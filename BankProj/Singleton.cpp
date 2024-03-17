#include "Singleton.h"
DataBase* DataBase::dataBaseConnection = nullptr;

DataBase* DataBase::getConnection() {
    if (!dataBaseConnection) {
        dataBaseConnection = new DataBase();
    }
    return dataBaseConnection;
}


DataBase::DataBase() {
    allAccounts = insertAccountsToDataBase();
    allTransactions = insertTransactionsToDataBase();
    return;
}


std::vector<Account*> DataBase::insertAccountsToDataBase() {
    std::vector<Account*> accounts;

    std::ifstream inFile("Accounts.jsonl");

    if (!inFile.is_open()) {
        std::cerr << "Unable to open the file.\n";
        return accounts;
    }

    inFile.seekg(0, std::ios::end);

    std::streampos fileSize = inFile.tellg();

    if (fileSize == 0) {
        std::cout << "File with Accounts is empty." << std::endl;
        return accounts;
    }
    else {
        std::cout << "File with Accounts is not empty." << std::endl;
    }

    inFile.seekg(0, std::ios::beg);

    std::string line;

    while (std::getline(inFile, line)) {
        try {

            nlohmann::ordered_json jsonAccount = nlohmann::ordered_json::parse(line);

            Account* parseJson = new Account(jsonAccount["id"].get<std::string>(), jsonAccount["name"].get<std::string>(), jsonAccount["balance"].get<double>());

            accounts.push_back(parseJson);

        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << '\n';
        }
    }

    inFile.close();

    return accounts;
}


std::vector<Transaction*> DataBase::insertTransactionsToDataBase()
{
    std::vector<Transaction*> transactions;

    std::ifstream inFile("Transactions.txt");

    if (!inFile.is_open()) {
        std::cerr << "Unable to open the file with Transactions.\n";
        return transactions;
    }

    inFile.seekg(0, std::ios::end);

    std::streampos fileSize = inFile.tellg();

    if (fileSize == 0) {
        std::cout << "File with Transactions is empty." << std::endl;
        return transactions;
    }
    else {
        std::cout << "File with Transactions is not empty." << std::endl;
    }

    inFile.seekg(0, std::ios::beg);

    std::string line;

    while (std::getline(inFile, line)) {
        try {

            std::vector<std::string> splitTransaction = splitStringTransaction(line);

            std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> date = getDateAtChrono(getDateAtString(splitTransaction));

            std::string transactionId = splitTransaction[0];
            std::string senderId = splitTransaction[1];
            std::string senderName = splitTransaction[2];
            std::string recipientId = splitTransaction[3];
            std::string recipientName = splitTransaction[4];
            std::string amoutntString = splitTransaction[5];
            double amount = std::stod(amoutntString);

            Transaction* transaction = new Transaction(transactionId, senderId, senderName,recipientId, recipientName,amount, Transaction::Date::Date(date));

            transactions.push_back(transaction);

        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << '\n';
        }
    }

    inFile.close();

    return transactions;
}

void DataBase::linkTransacionsWithUserAccount(Account* userAccount)
{
    if (!userAccount) {
        return;
    }

    for (Transaction* transaction : allTransactions) {
        if (transaction->getSenderId() == userAccount->getId() || transaction->getRecipientId() == userAccount->getId()) {
            userAccount->addTransaction(transaction);
        }
    }
}



void DataBase::insertNewAccount(Account* newAccount)
{
    allAccounts.push_back(newAccount);

}

void DataBase::insertAllAccountsInFileAndDeleteAccountsPtrs() {
    std::ofstream outFile("Accounts.jsonl");

    if (!outFile.is_open()) {
        std::cerr << "Unable to open the file with Accounts.\n";
        return;
    }

    for (Account* account : allAccounts) {
        nlohmann::ordered_json parseAccountToJson = account->toJson();
        outFile << parseAccountToJson << '\n';
        delete account;
        account = nullptr;
    }

    outFile.close();
    
}

void DataBase::deleteTransactionPtrs() {
    for (Transaction* transactionPtr : allTransactions) {
        delete transactionPtr;
    }
}


Account* DataBase::findAccount(std::string id)
{
    Account* foundAccount = nullptr;

    for (Account* account : allAccounts) {
        if (account->getId() == id) {
            foundAccount = account;
            return foundAccount;
        }
    }

    throw std::exception("Not found");

    return nullptr;
}


std::vector<Account*> DataBase::getAllAccounts()
{
    return allAccounts;
};

std::vector<Transaction> DataBase::getAllTransactions()
{
    std::vector<Transaction> transactionsCopies;

    for (Transaction* transaction : allTransactions) {
        transactionsCopies.push_back(*transaction);
    }

    return transactionsCopies;
};

void DataBase::insertNewTransaction(Transaction* newTransaction) {

    std::ofstream outFile("Transactions.txt", std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Unable to open the file with Transactions.\n";
        return;
    }

    outFile << *newTransaction;

    outFile.close();

    allTransactions.push_back(newTransaction);
}


std::vector<std::string> DataBase::splitStringTransaction(std::string stringTransaction)
{

    std::istringstream iss(stringTransaction);

    std::vector<std::string> splitTransaction;
    std::string field;

    int chekTransactionField = 1;

    while (iss >> field) {
        if ((chekTransactionField < 13 && chekTransactionField % 2 == 0) || chekTransactionField > 13) {
            splitTransaction.push_back(field);
        }
        chekTransactionField++;
    }

    return splitTransaction;
}


std::pair<std::string, std::string> DataBase::getDateAtString(std::vector<std::string> splitTransaction) {

    std::pair<std::string, std::string> stringDate(splitTransaction[splitTransaction.size() - 2], splitTransaction[splitTransaction.size() - 1]);

    return stringDate;

}


std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> DataBase::getDateAtChrono(std::pair<std::string, std::string> dateAtString) {

    std::string dateAtStringYMD = dateAtString.first;
    std::string dateAtStringHMS = dateAtString.second;

    std::istringstream issYMD(dateAtStringYMD);
    std::istringstream issHMS(dateAtStringHMS);

    std::tm tmYMD = {};
    std::tm tmHMS = {};

    issYMD >> std::get_time(&tmYMD, "%Y-%m-%d");
    issHMS >> std::get_time(&tmHMS, "%H:%M:%S");

    std::chrono::year_month_day yearMonthDay = std::chrono::year_month_day{
       std::chrono::year{tmYMD.tm_year + 1900},
       std::chrono::month{static_cast<unsigned int>(tmYMD.tm_mon) + 1},
       std::chrono::day{static_cast<unsigned int>(tmYMD.tm_mday)}
    };

    std::chrono::hh_mm_ss<std::chrono::seconds> hourMinuteSeconds = std::chrono::hh_mm_ss<std::chrono::seconds>{
        std::chrono::hours{tmHMS.tm_hour} +
        std::chrono::minutes{tmHMS.tm_min} +
        std::chrono::seconds{tmHMS.tm_sec}
    };

    std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> date(yearMonthDay, hourMinuteSeconds);
    return date;
}


std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> DataBase::getDateAtChronoForComparison(std::pair<std::string, std::string> userInputDate) {

    return getDateAtChrono(userInputDate);
}

