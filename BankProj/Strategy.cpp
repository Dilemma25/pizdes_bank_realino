#include "Strategy.h"

Account* UserStrategy::userAccount = nullptr;


void CloseProgrammAndInsertDataInDB::execute() {
    DataBase::getConnection()->insertAllAccountsInFileAndDeleteAccountsPtrs();
    DataBase::getConnection()->deleteTransactionPtrs();
    std::cout << "Program has been complited\n";
}


void CreateNewAccountStrategy::execute() {
    
    std::string name;
    double balance;

    std::cout << "Enter name \n";
    
    validator.validationName(name);

    std::cout << "Enter balance \n";

    validator.validationBalance(balance);

    if (!validator.chekError()) {
        return;
    }

    Account* newAccount = new Account(name, balance);

    DataBase::getConnection()->insertNewAccount(newAccount);

    std::cout << "New account with id: " << newAccount->getId() << " created\n";
}


void TransferMoneyStrategy::execute() {//придется модифицировать
    std::cout << "Enter the person's id for transfer\n";

    std::string recipientId;

    std::cin >> recipientId;

    Account* recipientAccount;

    try {
        recipientAccount = DataBase::getConnection()->findAccount(recipientId);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        return;
    }

    std::cout << "Enter the transfer amount\n";

    double amount;

    validator.validationBalance(amount);

    if (!validator.chekError()) {
        return;
    }

    try {
        userAccount->transferMoney(recipientAccount, amount);
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << '\n';
        return;
    }


    Transaction* newTransaction = new Transaction(userAccount->getId(), userAccount->getName(), recipientAccount->getId(), recipientAccount->getName(), amount);

    userAccount->addTransaction(newTransaction);
    DataBase::getConnection()->insertNewTransaction(newTransaction);

    std::cout << "Your balance: " << userAccount->getBalance() << '\n';
}


void SetUserAccountStrategy::execute()//выбираем юзера для работы
{
    std::cout << "Enter your id\n";

    std::string userId;

    std::cin >> userId;

    userAccount = DataBase::getConnection()->findAccount(userId);
    
    if (!userAccount) {
        throw std::exception("Cant set user account");
    }

    DataBase::getConnection()->linkTransacionsWithUserAccount(userAccount);

    std::cout << "Your account: \n";
    std::cout << "\nName: " << userAccount->getName() << " Balance: " << userAccount->getBalance() << '\n' << '\n';
}


void ShowAllTransactionsForUserStrategy::execute() { //печать транзакций
    std::vector<Transaction> userAccountTransactions = userAccount->getTransactions();

    std::cout << "My transactions:\n";

    for (Transaction& transaction : userAccountTransactions) {
        selectTransactionForUser(transaction);
    }

    std::cout << '\n';
}


void ShowTransactionsInUserIntervalStrategy::execute() { //интервально показат

    std::cout << "Enter start time\n";

    std::pair<std::string, std::string> userInputDateStart;

    validator.validationTimeYearMonthDay(userInputDateStart);
    validator.validationTimeHourMinuteSecond(userInputDateStart);
  
    std::pair<std::string, std::string> userInputDateEnd;

    std::cout << "Enter end time\n";

    validator.validationTimeYearMonthDay(userInputDateEnd);
    validator.validationTimeHourMinuteSecond(userInputDateEnd);


    std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> userIntervalStart = DataBase::getConnection()->getDateAtChronoForComparison(userInputDateStart);
    std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> userIntervalEnd = DataBase::getConnection()->getDateAtChronoForComparison(userInputDateStart);
    
    for (Transaction& transaction : userAccount->showTransactionInUserInterval(userIntervalStart, userIntervalEnd)) {
        selectTransactionForUser(transaction);
    }
}

void ShowAllAccountsStrategy::execute()
{
    std::vector<Account*> allAccounts = DataBase::getConnection()->getAllAccounts();


    if (allAccounts.empty()) {
        std::cout << "No accounts in the database\n";
        return;
    }

    std::cout << "All accounts:\n";

    for (Account* account : allAccounts) {
        std::cout << *account;
    }
}

void InsertBalanceToUserAccountStrategy::execute()
{
    std::cout << "Enter how much you want to top up your balance\n";
    
    double insertBalance;
    
    validator.validationBalance(insertBalance);
    
    if (!validator.chekError()) {
        return;
    }

    userAccount->insertBalance(insertBalance);

    Transaction* newTransaction = new Transaction("-", "Bank", userAccount->getId(), userAccount->getName(), insertBalance);
    userAccount->addTransaction(newTransaction);

    DataBase::getConnection()->insertNewTransaction(newTransaction);

    std::cout << "Your balance: " << userAccount->getBalance() << '\n';
}


void ShowAllTransactionsStrategy::execute() {
    
    std::vector<Transaction> allTransactions = DataBase::getConnection()->getAllTransactions();
    
    for (Transaction& transaction : allTransactions) {
        std::cout << transaction;
    }

    std::cout << '\n';
}



void ShowTransactionForUserStrategy::selectTransactionForUser(Transaction userTransaction) {
    std::cout << "Sender_Name: " << userTransaction.getSenderName() << " Repicient_Name: " << userTransaction.getRecipientName()
        << " Amount: " << userTransaction.getAmount() << ' ' << userTransaction.getDate().first << ' ' << userTransaction.getDate().second << '\n';
}
