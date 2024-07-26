/*
In this program I will create a base class Bank Account and
create two derived classes saving and checking account .
in addition to customer class the will prompt the user for his name and adress
in order to create a saving and checking account.
then , it will propmt the user for an account number for both accounts.
and a begining balance for each account
- after that the program will save those information in a file .
then the program will give the user to choose one account, either saving account or checking account to make changes
a menu will be disolayed in order to give the user the chance to
make deposite, withdraw and so on...
at the end the user can check his transactions report in addition to the number of his transactions.

Final Project CIT-237
Naima Matahri
*/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>

using namespace std;

class BankAccount // base class bank account
{
protected:
	int accountNumber;
	double balance;
	double interestRate;
	double deposit;
	double withdraw;
	double endingBalance;
	static int numTrsansactions;

public:
	// static void prelude();
	// static void auditTrail();

	// virtual double getInterestRate() = 0;

	void setEndingBalance(double e);
	double getEndingBalance()
	{
		return endingBalance;
	}
	void setDeposit(double d);
	double getDeposit()
	{
		return deposit;
	}
	void setWithdraw(double w);
	double getWithdraw()
	{
		return withdraw;
	}
	double getBalance() // function to return the balance
	{
		return balance;
	}
	void setBalance(double b); // function to set the balance
	void setAccountNumber(int);
	int getAccountNumber()
	{
		return accountNumber;
	}
	// virtual class InvalidInput{};
	// template<class T>
	//  virtual void makeDeposit(double)=0 ;
	virtual double makeWithdrawal() = 0;
	// virtual	void setInterestRate(double ) = 0;
	virtual void transactionsReport() = 0;
	virtual void create() = 0;
	virtual void showMenu() = 0;
	virtual void checkBalance() = 0;
};

#endif