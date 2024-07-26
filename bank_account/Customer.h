#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>

using namespace std;

class Customer
{
private:
	// char *name = new char [120];
	// char *address = new char[120];
	typedef char *name;
	name* name1 = new name[120];

	typedef char *address;
	address* address1 = new address[120];

public:
	Customer(char *n, char *a);
	Customer(const Customer &c); // copy constructor ;
	Customer();
	~Customer();
	void setName(char *n)
	{
		name = n;
	}
	void setAdress(char *a)
	{
		address = a;
	}

	char *getName()
	{
		return name;
	}
	char *getAdress()
	{
		return address;
	}

	void display();
	void createCustomer();
};

#endif