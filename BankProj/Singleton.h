#pragma once

#include"Account.h"

#include<fstream>
#include<string>

class DataBase {

	std::vector<Account*> allAccounts;
	std::vector<Transaction*> allTransactions;


	DataBase();
	//~DataBase();

	//void insertAllAccountsInFile();

	std::vector<Account*> insertAccountsToDataBase();
	std::vector<Transaction*> insertTransactionsToDataBase();
	

	static DataBase* dataBaseConnection;

	std::vector<std::string> splitStringTransaction(std::string stringTransaction);

	std::pair<std::string, std::string> getDateAtString(std::vector<std::string> splitTransaction);

	std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> getDateAtChrono(std::pair<std::string, std::string> dateAtString);

public:
	
	DataBase(const DataBase&) = delete;
	void operator = (const DataBase&) = delete;

	static DataBase* getConnection();

	Account* findAccount(std::string id);

	std::vector<Account*> getAllAccounts();
	std::vector<Transaction> getAllTransactions();

	void linkTransacionsWithUserAccount(Account* userAccount);

	void insertAllAccountsInFileAndDeleteAccountsPtrs();

	void deleteTransactionPtrs();

	void insertNewAccount(Account* newAccount);

	void insertNewTransaction(Transaction* newTransaction);

	std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> getDateAtChronoForComparison(std::pair<std::string, std::string> userInputDate);
};