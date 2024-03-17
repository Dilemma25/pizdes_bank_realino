#include"Menu.h"


Menu* Menu::menuConnect = nullptr;

Menu::Menu() {
    std::cout << "Menu get ready\n";
}

Menu* Menu::getMenuConnect()
{
    if (!menuConnect) {
        menuConnect = new Menu();
    }

    return menuConnect;
}

void Menu::setStrategy(Strategy* newStrategy)
{
    strategy = newStrategy;
}

void Menu::executeStrategy() {
    if (strategy) {
        strategy->execute();
    }
    else {
        std::cout << "Strategy not set\n";
    }
}

bool Menu::inputPassword()
{
    std::string tryPassword = "";

    std::cin >> tryPassword;

    if (tryPassword != adminPassword) {
        return false;
    }

    return true;
}

char Menu::inputValidation()
{
    std::string tryInput = "";

    try {
        std::cin >> tryInput;

        if (tryInput.length() > 1) {
            throw std::exception("Invalid input lenght");
        }

        return tryInput[0];
    }
    catch (std::exception& e) {

        std::cerr << "Error: " << e.what() << '\n';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return '0';
    }
}


void Menu::menu()
{
    DataBase::getConnection();

    std::cout << "Are you an admin or user?\n";


    char menuManagerAutorization;


    while (true) {

        std::cout << "If you are an admin, enter \'A\'\n";
        std::cout << "If you user, enter \'U\'\n";

        menuManagerAutorization = inputValidation();

        if (menuManagerAutorization == ChoiceMenu::adminMenuApperCase || menuManagerAutorization == ChoiceMenu::adminMenuLowerCase) {

            char menuManagerAutorizationAdmin;

            bool chekValidPassword = false;

            while (true) {

                std::cout << "Please, enter password:\n";

                chekValidPassword = inputPassword();

                if (!chekValidPassword) {
                    std::cout << "Incorrect password, try again, or login as user\n";
                    std::cout << "To login how user, return to the role selection step by entering \'U\'\n";


                    menuManagerAutorizationAdmin = inputValidation();

                    if (menuManagerAutorizationAdmin == ChoiceMenu::userMenuApperCase || menuManagerAutorizationAdmin == ChoiceMenu::userMenuLowerCase) {
                        break;
                    }

                }
                else {
                    char adminMenuManager;
                    while (true) {

                        std::cout << "You are in the admin menu, select an action:\n";

                        std::cout << "1: Show all accounts\n";
                        std::cout << "2: Create new account\n";
                        std::cout << "3: Show all Transactions\n";
                        std::cout << "0: Close the program\n";

                        adminMenuManager = inputValidation();

                        switch (adminMenuManager) {

                        case ChoiseInAdminMenu::showAllAccounts: {

                            setStrategy(new ShowAllAccountsStrategy);
                            executeStrategy();
                            break;
                        }

                        case ChoiseInAdminMenu::createNewAccount: {

                            setStrategy(new CreateNewAccountStrategy);
                            executeStrategy();
                            break;
                        }

                        case ChoiseInAdminMenu::showAllTransactions: {

                            setStrategy(new ShowAllTransactionsStrategy);
                            executeStrategy();
                            break;
                        }

                        case ChoiseInAdminMenu::closeAdminMenu: {

                            setStrategy(new CloseProgrammAndInsertDataInDB);
                            executeStrategy();
                            return;
                        }

                        default: {
                            std::cout << "Invalid data, try again\n";
                        }

                        }
                    }
                }
            }
        }
        else if (menuManagerAutorization == ChoiceMenu::userMenuApperCase || menuManagerAutorization == ChoiceMenu::userMenuLowerCase) {
            char userMenuManager;


            setStrategy(new SetUserAccountStrategy);

            try {
                executeStrategy();
            }
            catch (std::exception& e) {
                std::cerr << e.what() << '\n';
                return;
            }

            while (true) {

                std::cout << "You are in the user menu, select an action:\n";

                std::cout << "1: Insert money into your account\n";
                std::cout << "2: Transfer to another person\n";
                std::cout << "3: Show all my transactions\n";
                std::cout << "4: Show my transaction in interval\n";
                std::cout << "0: Close the program\n";

                userMenuManager = inputValidation();;


                switch (userMenuManager) {

                case ChoiseInUserMenu::insertBalanceToUserAccount: {

                    setStrategy(new InsertBalanceToUserAccountStrategy);
                    executeStrategy();
                    break;
                }

                case ChoiseInUserMenu::transferMoney: {

                    setStrategy(new TransferMoneyStrategy);
                    executeStrategy();
                    break;
                }

                case ChoiseInUserMenu::showAllTransactionsForUser: {

                    setStrategy(new ShowAllTransactionsForUserStrategy);
                    executeStrategy();
                    break;
                }

                case ChoiseInUserMenu::showTransactionsInUserInterval: {
                    setStrategy(new ShowTransactionsInUserIntervalStrategy);
                    executeStrategy();
                    break;
                }

                case ChoiseInUserMenu::closeUserMenu: {

                    setStrategy(new CloseProgrammAndInsertDataInDB);
                    executeStrategy();
                    return;
                }

                default: {
                    std::cout << "Invalid data, try again\n";
                }

                }
            }
        }
        else {
            std::cout << "Invalid data, try again\n";
        }

    }
}


