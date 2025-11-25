#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include"clsBankClient.h"

class clsFindClientScreen:protected clsScreen
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
	static void ShowFindClientScreen() {
		_DrawScreenHeader("\t\Find Client Screen");

		string accountNumber = "";

		cout << "\nPlease enter an account number to check: ";
		accountNumber = clsInputValidate::readString();

		while(!clsBankClient::IsClientExist(accountNumber))
		{
			cout << "Account Number is not found, Choose another one: ";
			accountNumber = clsInputValidate::readString();
		}
		clsBankClient client = clsBankClient::Find(accountNumber);
		if(!client.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient is not found!.\n";
		}
		_Print(client);
	}
};

