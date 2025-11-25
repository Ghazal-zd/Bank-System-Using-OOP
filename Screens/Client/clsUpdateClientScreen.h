#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
class clsUpdateClientScreen:protected clsScreen
{
	static void _ReadClientInfo(clsBankClient& client)
	{
		cout << "\nEnter First Name: ";
		client.FirstName = clsInputValidate::readString();
		cout << "\nEnter Last Name: ";
		client.LastName = clsInputValidate::readString();
		cout << "\nEnter Email : ";
		client.Email = clsInputValidate::readString();
		cout << "\nEnter Phone Number: ";
		client.PhoneNumber = clsInputValidate::readString();
		cout << "\nEnter PIN code : ";
		client.PINCode = clsInputValidate::readString();
		cout << "\nEnter your account Balance: ";
		client.AccountBalance = clsInputValidate::ReadDblNumber();
	}

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
	static void ShowUpdateClientScreen() 
	{
		_DrawScreenHeader("\t\tUpdate Client Screen");

		char updateClient = 'n';

		string accountNumber = "";
		cout << "Please enter an account number: ";
		accountNumber = clsInputValidate::readString();
		while (!clsBankClient::IsClientExist(accountNumber))
		{
			cout << "Account Number Is Not Found, Enter Another One: ";
			accountNumber = clsInputValidate::readString();
		}
		clsBankClient client = clsBankClient::Find(accountNumber);
		_Print(client);
		cout << "\nAre you sure you want to update this client? y/n? ";
		cin >> updateClient;
		if(tolower(updateClient)=='y')
		{
			cout << "\nUpdate Client Info:";
			cout << "\n_________________________\n";

			_ReadClientInfo(client);

			clsBankClient::enSaveResult saveResult;
			saveResult = client.Save();

			switch (saveResult)
			{
			case clsBankClient::enSaveResult::svSucceeded:
			{
				cout << "\nClient Updated Successfully :-)\n";
				_Print(client);
				break;
			}
			case clsBankClient::enSaveResult::svFailedEmptyObject:
			{
				cout << "\nError, Client cannot saved because it is empty!";
				break;
			}
			case clsBankClient::enSaveResult::svFailedAccountNumberIsExist:
			{
				cout << "Error, This account is already used!";
				break;
			}
			}
		}
    }
};

