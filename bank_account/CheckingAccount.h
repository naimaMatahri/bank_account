#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "BankAccount.h"

using namespace std;

class CheckingAccount : public BankAccount // checking account derived class
{
private:
	// static int numTrsansactions;
public:
	CheckingAccount() // default constructor
	{
		balance = 0;
		accountNumber = 0;
		deposit = 0;
		withdraw = 0;
		endingBalance = 0;
		numTrsansactions++;
	}
	CheckingAccount(double b, int acc, double d, double w, double end) // constructor
	{
		balance = b;
		accountNumber = acc;
		deposit = d;
		withdraw = w;
		endingBalance = end;
		numTrsansactions++;
	}
	~CheckingAccount() { numTrsansactions--; }; // deconstructor

	// static void prelude();
	// static void auditTrail();

	template <class T>
	void makeDeposit(T d);
	double makeWithdrawal();
	void setInterestRate(double i){};
	void showMenu();
	void create();
	void checkBalance();
	void checkingAccountCreated();
	void transactionsReport();
	class InvalidInput
	{
	};
};

#endif