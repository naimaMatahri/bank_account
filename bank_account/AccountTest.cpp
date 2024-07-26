#include "BankAccount.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include "Customer.h"
#include <curses.h>
#include <fstream>

using namespace std;

int main()
{

	cout << endl
		 << " Welcome to your Bank please follow the instructions to create your Saving and Checking accounts " << endl
		 << endl;

	Customer c;

	SavingAccount s;

	CheckingAccount ck;

	fstream fileName;
	fileName.open("bankAccount.dat", ios::out | ios::in | ios::binary); // open the file for binary output
	if (!fileName.fail())
	{
		// write the data to the file
		fileName.write(reinterpret_cast<char *>(&c), sizeof(c));
		c.createCustomer();
		fileName.write(reinterpret_cast<char *>(&s), sizeof(s));
		try
		{
			s.create();
		}
		catch (SavingAccount::InvalidInput)
		{
			cout << " Invalid input, account number must be 4 digits :  ";
		}

		fileName.write(reinterpret_cast<char *>(&ck), sizeof(ck));
		try
		{
			ck.create();
		}
		catch (CheckingAccount::InvalidInput)
		{
			cout << " Invalid input, account number must be 4 digits :  ";
		}
		cout << endl
			 << "*******************************************************" << endl;
		// close the file
		fileName.close();
	}

	else
	{
		cout << " error, cannot open file "; // display error message if the file dose not exist
		exit(0);
	}
	cout << endl
		 << " read the data " << endl
		 << endl;
	fileName.seekg(0L, ios::beg);
	fileName.read(reinterpret_cast<char *>(&c), sizeof(c));
	c.display();
	fileName.read(reinterpret_cast<char *>(&s), sizeof(s));
	s.savingAccountCreated();
	fileName.read(reinterpret_cast<char *>(&s), sizeof(s));
	ck.checkingAccountCreated();
	do
	{
		char option;
		cout << endl
			 << " Please enter the account to which you want to make changes , enter s for Saving account and C for checking account : " << endl;
		cin >> option;

		if (option == 's' || option == 'S')
		{
			s.showMenu();
		}
		else if (option == 'C' || option == 'c')
		{
			ck.showMenu();
		}
		else if (cin.fail() || option != 's' || option != 'S' || option != 'c' || option != 'C')

		{
			cout << " The option you choose does not much, Please type eaither 'S' or 'C'  :    " << endl;
			cin >> option;
		}
		cout << endl
			 << " Do you want to make other changes to your accounts  (Y/N)" << endl;
	} while (toupper(getch()) != 'N');

	ck.transactionsReport();
	s.transactionsReport();

	// close the file
	fileName.close();

	getch();
	return 0;
}