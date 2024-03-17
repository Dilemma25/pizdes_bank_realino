#pragma once
#include"Strategy.h"

class Menu {
	Strategy* strategy = nullptr;

	static Menu* menuConnect;

	const std::string adminPassword = "12345";

	Menu();

	enum ChoiceMenu {
		adminMenuApperCase = 'A',
		adminMenuLowerCase = 'a',

		userMenuApperCase = 'U',
		userMenuLowerCase = 'u'
	};

	enum ChoiseInAdminMenu {
		showAllAccounts = '1',
		createNewAccount = '2',
		showAllTransactions = '3',
		closeAdminMenu = '0'
	};

	enum ChoiseInUserMenu {
		insertBalanceToUserAccount = '1',
		transferMoney = '2',
		showAllTransactionsForUser = '3',
		showTransactionsInUserInterval = '4',
		closeUserMenu = '0'
	};

	void setStrategy(Strategy*);

	void executeStrategy();

	bool inputPassword();

	char inputValidation();

public:

	static Menu* getMenuConnect();

	void menu();


};