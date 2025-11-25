#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include"clsBankClient.h"

class clsDeleteClientScreen:protected clsScreen
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
public:
	static void ShowDeleteClientScreen() {
		_DrawScreenHeader("\t\tDelete Client Screen");

		string accountNumber = "";

		cout << "Please enter an account number to check: \n";
		accountNumber = clsInputValidate::readString();

		while (!clsBankClient::IsClientExist(accountNumber))
		{
			cout << "\nAccount number is not found, Choose another one: ";
			accountNumber = clsInputValidate::readString();
		}

		clsBankClient client = clsBankClient::Find(accountNumber);
	    _Print(client);

		char answer = 'n';
		cout << "\nAre you sure you want to delete this client? y/n? ";
		cin >> answer;
		if (tolower(answer) == 'y')
		{
			if (client.Delete())
			{
				cout << "\nClient Deleted Successfully :-)";
				_Print(client);
			}
			else
			{
				cout << "\nError client was not deleted";
			}
		}
	}
};

