#pragma once
#include"Account.h"
#include"Singleton.h"
#include"Validator.h"


class Strategy {
public:
	virtual void execute() = 0;
	virtual ~Strategy() = default;
};

class ValidationHelper {
protected:
	Validator validator;
};

class AdminStrategy : public Strategy{};

class UserStrategy : public Strategy {
protected:
	static Account* userAccount;
};


class CloseProgrammAndInsertDataInDB : public Strategy {
	void execute() override;
};

class ShowTransactionForUserStrategy : public UserStrategy {
protected:
	void selectTransactionForUser(Transaction userTransaction);
};


class CreateNewAccountStrategy : public AdminStrategy, public ValidationHelper {
public:	
	void execute() override;
};

class ShowAllAccountsStrategy : public AdminStrategy {
	void execute() override;
};

class ShowAllTransactionsStrategy : public AdminStrategy {
	void execute() override;
};



class SetUserAccountStrategy : public UserStrategy {
public:
	void execute() override;
};

class ShowAllTransactionsForUserStrategy : public ShowTransactionForUserStrategy {
	void execute() override;
};

class ShowTransactionsInUserIntervalStrategy : public ShowTransactionForUserStrategy, public ValidationHelper {
	void execute() override;
};

class TransferMoneyStrategy : public UserStrategy, public ValidationHelper {
public:
	void execute() override;
};

class InsertBalanceToUserAccountStrategy : public UserStrategy, public ValidationHelper {
	void execute() override;
};



