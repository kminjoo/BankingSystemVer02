/*
* Name: Minjoo Kwon
* Project: BankingSystemVer02
* Account.cpp
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(char *name_in, int ID_in, int balance_in)
{
	const int LEN = strlen(name_in) + 1;
	cusName = new char[LEN];
	strcpy(cusName, name_in);

	accountID = ID_in;
	balance = balance_in;
}

char* Account::GetName() const
{
	return cusName;
}

int Account::GetID() const
{
	return accountID;
}

int Account::GetBalance() const
{
	return balance;
}

void Account:: AddBalance(int balance_in)
{
	balance += balance_in;
}

void Account:: Withdrawl(int withdrawl_in)
{
	balance -= withdrawl_in;
}

void Account::ShowInfos(int numPeople_in) const
{
	cout << "Account ID: " << accountID << endl;
	cout << "Name: " << cusName << endl;
	cout << "Balance: $" << balance << endl;
}
Account::~Account()
{
	delete []cusName;
}
