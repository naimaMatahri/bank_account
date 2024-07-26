
#include "CheckingAccount.h"
#include "BankAccount.h"
#include <string>

using namespace std;

// int CheckingAccount::numTrsansactions ;

void CheckingAccount::create()
{
	cout << endl
		 << " Create your Checking account" << endl;
	cout << endl
		 << "please enter your Checking account number (4 numbers) :   ";
	while ((!(cin >> accountNumber)) || accountNumber < 0) // clearthe non numeric and negative numbers
	{
		cin.clear(); // reset the input
		while (cin.get() != '\n')
			continue; // get rid of bad input
		cout << " Please enter a numeric and positive data  : ";
	}

	// throw exception
	if (accountNumber < 1000 || accountNumber > 9999)
	{
		throw InvalidInput();
	}

	cout << endl
		 << " please make a deposite as a begining balance of your checking account :  ";
	while ((!(cin >> balance)) || balance < 0)
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << " Please enter a numeric and positive data:   ";
	}
}
template <class T>
void CheckingAccount::makeDeposit(T d)
{

	cout << " Please enter the amount you want to deposit : ";
	while ((!(cin >> deposit)) || deposit < 0)
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << " Pleas enter a numeric and positive data:   ";
	}

	// numTrsansactions++;
	d = deposit;
	endingBalance += deposit;
}

double CheckingAccount::makeWithdrawal()
{
	cout << " Please enter the amount you want to withdraw : ";
	while ((!(cin >> withdraw)) || withdraw < 0)
	{
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << " Pleas enter a numeric and positive data:   ";
		}
	}
	if (balance < 50 || withdraw > balance)
	{
		cout << " There is not enough fund to withdraw please make a deposit, ";
	}
	else if (withdraw > balance)
	{
		withdraw = 0;
	}

	// numTrsansactions++;

	return endingBalance -= withdraw;
}

void CheckingAccount::checkBalance()
{
	cout << " The balance in your Checking account is :  $" << balance << endl
		 << endl;
}

void CheckingAccount::showMenu()
{

	cout << endl
		 << " Please choose from the menu of your Checking account " << endl;
	cout << "             Menu :  " << endl;
	cout << 1 << "        ** Make Deposit " << endl;
	cout << 2 << "        ** Make Withdrawal " << endl;
	cout << 3 << "        ** Check Balance  " << endl;
	cout << 4 << "        ** See your transactions report " << endl;

	int option;
	cin >> option;
	if (cin.fail() || option < 1 || option > 4)
	{
		do
		{

			cin.clear();
			fflush(stdin);

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

void CheckingAccount::checkingAccountCreated()
{
	cout << endl
		 << " The Checking Account you created  : " << endl
		 << endl;
	cout << " account Number :     C-" << accountNumber << endl;
	cout << " begining balance : " << balance << endl;
	cout << "****************************************************" << endl;
}

void CheckingAccount::transactionsReport()
{
	endingBalance = (balance + deposit) - withdraw;

	cout << endl
		 << endl
		 << " Checking Account report : " << endl;
	cout << " account Number : " << accountNumber << endl;
	cout << " begining balance :   $ " << balance << endl;
	cout << " deposit  :     $" << deposit << endl;
	cout << " Withrawal :    $" << withdraw << endl;
	cout << " Ending balance :  $" << endingBalance << endl;
	// cout << numTrsansactions << endl;
}
