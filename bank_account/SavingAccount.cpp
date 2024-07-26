#include "SavingAccount.h"
#include "BankAccount.h"
#include <string>

using namespace std;

// int SavingAccount::numTrsansactions ;

void SavingAccount::create()
{
	cout << endl
		 << endl
		 << " Create your Saving account" << endl;
	cout << endl
		 << "please enter your Saving account number (4 numbers)   :   ";
	while ((!(cin >> accountNumber)) || accountNumber < 0)
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << " Please enter a numeric and positive:   ";
	}

	// throw exception

	if (accountNumber < 1000 || accountNumber > 9999)
	{
		throw InvalidInput();
	}

	cout << endl
		 << " please make a deposite as a begining balance of your Saving account :  ";
	while ((!(cin >> balance)) || balance < 0)
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << " Please enter a numeric and positive input :   ";
	}
}

void SavingAccount::setInterestRate(double r)
{
	double annuallInterets = 4.0;
	r = ((endingBalance * annuallInterets * 0.01) / 12);
	interestRate = r;
}

template <class T>
void SavingAccount::makeDeposit(T d)
{

	cout << " Please enter the amount you want to deposit : ";
	while ((!(cin >> deposit)) || deposit < 0)
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << " Pleas enter a numeric and positive data:   ";
	}

	//  numTrsansactions++;

	d = deposit;
	endingBalance += deposit;
}

double SavingAccount::makeWithdrawal()
{

	cout << " Please enter the amount you want to withdraw : ";
	while ((!(cin >> withdraw)) || withdraw < 0)
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << " Pleas enter a numeric and positive data:   ";
	}
	if (balance < 100 || withdraw > balance)
	{
		cout << " There is not enough fund to withdraw please make a deposit, ";
	}
	else if (withdraw > balance)
	{
		withdraw = 0;
		endingBalance = balance;
	}

	// numTrsansactions++;

	return endingBalance -= withdraw;
}

void SavingAccount::checkBalance()
{
	cout << endl
		 << " The balance in your Saving Account is :   $" << balance << endl
		 << endl;
}

void SavingAccount::showMenu()
{
	cout << endl
		 << " Please choose from the menu of your Saving account " << endl;
	cout << "               Menu :  " << endl;
	cout << 1 << "        ** Make Deposit " << endl;
	cout << 2 << "        ** Make Withdrawal " << endl;
	cout << 3 << "        ** Check Balance  " << endl;
	cout << 4 << "        ** See your transactions report " << endl;

	int option;
	cout << endl;
	cin >> option;
	if (cin.fail() || option < 1 || option > 4)
	{
		do
		{
			cin.clear();
			fflush(stdin);
			// throw InvalidInput();
			cout << " The option you choose does not much, Please enter a number between 1 and 4  :    ";
			cin >> option;
		} while (cin.fail() || option < 1 || option > 4);
	}
	switch (option)
	{
	case 1:

		makeDeposit(deposit);
		break;
	case 2:
		makeWithdrawal();
		break;
	case 3:
		checkBalance();
		break;
	case 4:
		transactionsReport();
	}
}

void SavingAccount::savingAccountCreated()
{
	cout << endl
		 << " The Saving Account you created   : " << endl
		 << endl;
	cout << " account Number :     S-" << accountNumber << endl;
	cout << " begining balance : " << balance << endl;
	cout << "****************************************************" << endl;
}

void SavingAccount::transactionsReport()
{
	endingBalance = (balance + deposit) - withdraw;

	cout << endl
		 << endl
		 << " Saving Account report : " << endl;
	cout << " account Number : " << accountNumber << endl;
	cout << " begining balance :  $ " << balance << endl;
	cout << " deposit  :   $" << deposit << endl;
	cout << " Withrawal :    $" << withdraw << endl;
	cout << " Ending balance :    $" << endingBalance << endl;
	cout << "your earned interest :   $" << interestRate << endl;
	cout << " Number of accounts created :  " << numTrsansactions << endl;
}
