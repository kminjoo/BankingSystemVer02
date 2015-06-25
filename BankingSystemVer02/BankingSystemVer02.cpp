#define _CRT_SECURE_NO_WARNINGS
/*
* Name: Minjoo Kwon
* BankingSystemVer02
* BankingSystemVer02.cpp
*/

/*
	����ü Account �� Ŭ���� Account�� �����غ��ڴ�. 
	��� ĸ��ȭ�� ��Ű�� ������ �����ؾ��ұ�? 
	�����ڿ� �Ҹ��ڴ� ��� �����ؾ��ұ�?
	�߰���, �����ϴµ� �ΰ��� �������� �ϰڴ�. ����0.1�� Account ����ü�� char�� �迭�� ����εּ� ���� �̸��� �����ߴµ�, ���� 2�� Ŭ���������� �̸�
	���� �Ҵ��� ���·� �����ϱ�� ����. ��AccountŬ������ ��������� ���ڿ� ������(char �� ������)�� ���ϰ� �־���Ѵ�.
	�� �Ѱ����� ��ü�� �����ϴ� �迭�� ���Ѱ��̴�. ��ü �迭�� �������� ����, ��ü ������ �迭�� �����ؼ� ��ü�� �����ϱ� �ٶ���.
	���� 0.1������ ����ü �迭�� �����Ͽ�����, �̸� ������ �迭�� �����ؾ��Ѵ�.
*/

#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
	int accountID;
	int balance;
	char *cusName;
public:
	Account() : accountID(0), balance(0) {}
	Account(char *name_in, int ID_in, int balance_in);
	char* GetName() const
	{
		return cusName;
	}
	int GetID() const
	{
		return accountID;
	}
	int GetBalance() const
	{
		return balance;
	}

	void AddBalance(int balance_in)
	{
		balance += balance_in;
	}
	void Withdrawl(int withdrawl_in)
	{
		balance -= withdrawl_in;
	}
	
	~Account()
	{
		delete cusName;
	}
};

Account::Account(char *name_in, int ID_in, int balance_in)
{
	const int LEN = strlen(name_in);
	cusName = new char[LEN];
	strcpy(cusName, name_in);

	accountID = ID_in;
	balance = balance_in;
}

void ShowMenu();
void createAccount(Account *customers[], int numPeople_in);
void deposit(Account *customers[], int numPeople_in);
void withdrawl(Account *customers[], int numPeople_in);
void viewInfo(Account *customers[], int numPeople);

int main()
{
	int numPeople = 0;
	Account *customers[100];

	enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
	while (1){
		ShowMenu();
		int choice;
		cin >> choice;

		switch (choice)
		{
		case MAKE:
			createAccount(customers, numPeople);
			++numPeople;
			break;
		case DEPOSIT:
			deposit(customers, numPeople);
			break;
		case WITHDRAW:
			withdrawl(customers, numPeople); 
			break;
		case INQUIRE:
			viewInfo(customers, numPeople); 
			break;
		case EXIT:
			for (int i = 0; i < numPeople; ++i)
				delete customers[i];
			return 0;
		default:
			cout << "Illegal selection." << endl;
		}
	}
}

void ShowMenu()
{
	cout << "----------------- Menu --------------" << endl;
	cout << "1. Create new account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdrawl" << endl;
	cout << "4. View all the Account informations" << endl;
	cout << "5. Exit" << endl;
	cout << "Choose: ";
}


void createAccount(Account *customers[], int numPeople_in)
{
	int accountID_in;
	char name_in[100];
	int balance_in;

	cout << "[Create a New Account]" << endl;
	cout << "First Name: "; cin >> name_in;
	cout << "Account ID: "; cin >> accountID_in;
	cout << "Deposit Amount: $"; cin >> balance_in;
	cout << endl;

	customers[numPeople_in] = new Account(name_in, accountID_in, balance_in);
}

void deposit(Account *customers[], int numPeople_in)
{
	int accID_in;
	int deposit;
	cout << "[Deposit]" << endl;
	cout << "Account ID: "; cin >> accID_in;
	for (int i = 0; i < numPeople_in; ++i)
	{
		if (customers[i]->GetID() == accID_in)
		{
			cout << "Deposit amount: $"; cin >> deposit;
			customers[i]->AddBalance(deposit);
			cout << "Desposited successfully." << endl;
			return;
		}
	}
	cout << "ID not found.";
	cout << endl;
	cout << endl;
}

void withdrawl(Account *customers[], int numPeople_in)
{
	cout << "[Withdrawl]" << endl;
	int accID;
	cout << "Account ID: "; cin >> accID;
	int withdrawl;
	for (int i = 0; i < numPeople_in; ++i)
	{
		if (customers[i]->GetID() == accID)
		{
			cout << "Withdrawl amount: $"; cin >> withdrawl;
			customers[i]->Withdrawl(withdrawl);
			cout << "Withdrawn successfully." << endl;
			return;
		}
	}
	cout << "ID not found" << endl;

}

void viewInfo(Account *customers[], int numPeople) 
{
	for (int i = 0; i < numPeople; ++i)
	{
		cout << "Account ID: " << customers[i]->GetID() << endl;
		cout << "Name: " << customers[i]->GetName()<< endl;
		cout << "Balance: $" << customers[i]->GetBalance()<< endl;
		cout << endl << endl;
	}

}