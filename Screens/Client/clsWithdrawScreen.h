#pragma once
#include"clsScreen.h"
#include "clsInputValidate.h"
#include"clsBankClient.h"
class clsWithdrawScreen :protected clsScreen
{
	static void _Print(clsBankClient client) {
		cout << "\nClient Info: ";
		cout << "\n----------------------";
		cout << "\nFirst Name     : " << client.FirstName;
		cout << "\nLast Name      : " << client.LastName;
		cout << "\nFull Name      : " << client.FirstName + " " + client.LastName;
		cout << "\nPhone number   : " << client.PhoneNumber;
		cout << "\nEmail          : " << client.Email;
		cout << "\nAccount Number : " << client.getAccountNumber();
		cout << "\nPIN Code       : " << client.PINCode;
		cout << "\nAccount Balance: " << client.AccountBalance;
		cout << "\n----------------------";

	}
	static string _ReadAccountNumber() {

		string accountNumber = "";
		cout << "Please enter an account number: ";
		accountNumber = clsInputValidate::readString();
		return accountNumber;
	}
public:
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t\tWithdraw Screen");


		string accountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(accountNumber))
		{
			cout << "\nClient with [" << accountNumber << "] does not exist. \n";
			accountNumber = _ReadAccountNumber();
		}
		clsBankClient client = clsBankClient::Find(accountNumber);

		_Print(client);

		double amount = 0;
		cout << "\nPlease enter withdraw amount? ";
		amount = clsInputValidate::ReadDblNumber();


		char answer = 'n';
		cout << "\n\nAre you sure you want perform this transactions? y/n? ";
		cin >> answer;

		if (tolower(answer) == 'y')
		{
			if(client.Withdraw(amount))
			{
				cout << "\nAmount Withdraw successfully :-)\n";
				cout << "\n New Account Balance is " << client.AccountBalance << endl;
			}
			else
			{
				cout << "\nFailed!";
				cout << "\nAccount Balance is: " << client.AccountBalance;
				cout << "\nAmount is: " << amount;
			}
		}
		else
		{
			cout << "\nOperation was canceled";
		}
	}
};

