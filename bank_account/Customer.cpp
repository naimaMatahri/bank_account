#include "Customer.h"
#include "BankAccount.h"
#include <iostream>
// #include <cstring>
// #define __STDC_WANT_LIB_EXT1__ 1
#define strcpy_s
#include <string.h>

using namespace std;

Customer::Customer(char *n, char *a)
{

	name = new char(strlen(n) + 1); // allocate just enough memory for the name

	address = new char(strlen(a) + 1);
}

Customer::Customer()
{
	name = new char[20];

	address = new char[50];
}

Customer::~Customer()
{
	delete[] name;
	delete[] address;
}

Customer::Customer(const Customer &c) // copy constructor ;
{

	name = new char[strlen(c.name) + 1];
	strcpy_s(name, strlen(c.name) + 1, c.name);
	address = new char[strlen(c.address) + 1];
	strcpy_s(address, strlen(c.address) + 1, c.address);
}

void Customer::createCustomer()
{

	cout << " Please enter you name : ";
	cin.ignore();
	cin.getline(name, 20);
	cout << " Please enter your adress : ";
	cin.ignore();
	cin.getline(address, 50);
}

void Customer::display()
{

	cout << endl
		 << " Name : " << name << endl;
	cout << " Adress : " << *address << endl
		 << endl;
}
