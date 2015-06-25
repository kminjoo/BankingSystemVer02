#include <iostream>

class Account
{
private:
	int accountID;
	int balance;
	char *cusName;
public:
	Account() : accountID(0), balance(0) {}
	Account(char *name_in, int ID_in, int balance_in);
	char* GetName() const;
	int GetID() const;
	int GetBalance() const;
	void AddBalance(int balance_in);
	void Withdrawl(int withdrawl_in);
	~Account();
};
