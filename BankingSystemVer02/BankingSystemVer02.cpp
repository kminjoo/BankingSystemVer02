/*
* Name: Minjoo Kwon
* BankingSystemVer02
* BankingSystemVer02.cpp
*/

/*
	구조체 Account 를 클래스 Account로 변경해보겠다. 
	어떻게 캡슐화를 시키고 정보를 은닉해야할까? 
	생성자와 소멸자는 어떻게 정의해야할까?
	추가로, 구현하는데 두가지 제약으르 하겠다. 버전0.1의 Account 구조체는 char형 배열을 멤버로둬서 고객의 이름을 저장했는데, 버전 2의 클래스에서는 이를
	동적 할당의 형태로 구현하기로 하자. 즉Account클래스는 멤버변수로 문자열 포인터(char 형 포인터)를 지니고 있어야한다.
	또 한가지는 객체를 저장하는 배열에 관한것이다. 객체 배열을 선언하지 말고, 객체 포인터 배열을 선언해서 객체를 저장하기 바란다.
	버전 0.1에서는 구조체 배열을 선언하였으니, 이를 포인터 배열로 변경해야한다.
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
	char* GetName(){ return cusName; }
	void createAccount(Account *customers, int numPeople_in);
	void deposit(Account *customers, int numPeople_in);
	void viewInfo(Account *customers, int numPeople) const;
	void withdrawl(Account *customers, int numPeople_in);
	~Account()
	{

	}

};

void ShowMenu();

int main()
{
	int numPeople = 0;
	Account *customers = new Account[100];

	enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
	while (1){
		ShowMenu();
		int choice;
		cin >> choice;

		switch (choice)
		{
		case MAKE:
			customers->createAccount(customers, numPeople);
			++numPeople;
			break;
		case DEPOSIT:
			customers->deposit(customers, numPeople);
			break;
		case WITHDRAW:
			customers->withdrawl(customers, numPeople); 
			break;
		case INQUIRE:
			customers->viewInfo(customers, numPeople); 
			break;
		case EXIT:
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


void Account::createAccount(Account *customers, int numPeople_in)
{
	int accountID_in;
	char *name_in;
	int balance_in;

	cout << "[Create a New Account]" << endl;
	cout << "Name: "; cin >> name_in;
	const int LEN = strlen(name_in);
	name_in = new char[LEN];
	strcpy(customers->GetName(), name_in);

	cout << "Account ID: "; cin >> accountID_in;
	cout << "Deposit Amount: $"; cin >> balance_in;
	cout << endl;

	customers[numPeople_in].accountID = accountID_in;
	customers[numPeople_in].cusName = name_in;
	customers[numPeople_in].balance += balance_in;

}

void Account::deposit(Account *customers, int numPeople_in)
{
	int accID_in;
	int deposit;
	cout << "[Deposit]" << endl;
	cout << "Account ID: "; cin >> accID_in;

	for (int i = 0; i < numPeople_in; ++i)
	{
		if (customers[i].accountID == accID_in)
		{
			cout << "Deposit amount: $"; cin >> deposit;
			customers[i].balance += deposit;
			cout << "Desposited successfully." << endl;
			return;
		}
	}
	cout << "ID not found.";
	cout << endl;
	cout << endl;
}

void Account::withdrawl(Account *customers, int numPeople_in)
{
	cout << "[Withdrawl]" << endl;
	int accID;
	cout << "Account ID: "; cin >> accID;
	int withdrawl;
	for (int i = 0; i < numPeople_in; ++i)
	{
		if (customers[i].accountID == accID)
		{
			cout << "Withdrawl amount: $"; cin >> withdrawl;
			customers[i].balance -= withdrawl;
			cout << "Withdrawn successfully." << endl;
			return;
		}
	}
	cout << "ID not found" << endl;

}
void Account::viewInfo(Account *customers, int numPeople)
{
	for (int i = 0; i < numPeople; ++i)
	{
		cout << "Account ID: " << customers[i].accountID << endl;
		cout << "Name: " << customers[i].cusName << endl;
		cout << "Balance: $" << customers[i].balance << endl;
		cout << endl << endl;
	}

}