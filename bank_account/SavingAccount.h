
/*Saving Account class */

#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
#include "BankAccount.h"

using namespace std;

class SavingAccount : public BankAccount // saving account derived class
{
private:
	double interestRate;
	// static int numTrsansactions;

public:
	SavingAccount() // default constructor
	{
		balance = 0;
		accountNumber = 0;
		interestRate = 0.0;
		deposit = 0;
		withdraw = 0;
		endingBalance = 0;
		numTrsansactions++;
	}
	SavingAccount(double b, int acc, double i, double d, double w, double end) // constructor
	{
		balance = b;
		accountNumber = acc;
		interestRate = i;
		deposit = d;
		withdraw = w;
		endingBalance = end;
		numTrsansactions++;
	}
	~SavingAccount() { numTrsansactions--; }; // deconstructor

	template <class T>
	void makeDeposit(T d);
	double makeWithdrawal();
	void transactionsReport();
	void checkBalance();
	void savingAccountCreated();
	void create();
	void showMenu();

	void setInterestRate(double r);
	double getInterestRate()
	{
		return interestRate;
	}

	class InvalidInput
	{
	};
};

#endif