#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;
class clsAddNewClientScreen : protected clsScreen
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
		cout << "\nFull Name      : " << client.FirstName +" "+client.LastName;
		cout << "\nPhone number   : " << client.PhoneNumber;
		cout << "\nEmail          : " << client.Email;
		cout << "\nAccount Number : " << client.getAccountNumber();
		cout << "\nPIN Code       : " << client.PINCode;
		cout << "\nAccount Balance: " << client.AccountBalance;
		cout << "\n----------------------";

	}
public:
	static void ShowAddNewClientScreen()
	{
		
		_DrawScreenHeader("\t\tAdd New Client Screen");

		char addMoreClient = 'n';
		do
		{
			string accountNumber = "";
			cout << "Please enter an account number: ";
			accountNumber = clsInputValidate::readString();

			while (clsBankClient::IsClientExist(accountNumber))
			{
				cout << "this account number is already exist, choose another one: ";
				accountNumber = clsInputValidate::readString();
			}
			clsBankClient client = clsBankClient::GetAddNewClientObject(accountNumber);

			_ReadClientInfo(client);

			clsBankClient::enSaveResult saveResult;
			saveResult=client.Save();

			switch (saveResult)
			{
			case clsBankClient::enSaveResult::svSucceeded:
			{
				cout << "\nClient Added Successfully :-) ";
				_Print(client);
				break;
			}
			case clsBankClient::enSaveResult::svFailedEmptyObject:
			{
				cout << "Error, client cannot added because it is empty!.";
				break;
			}
			case clsBankClient::enSaveResult::svFailedAccountNumberIsExist:
			{
				cout << "Error this account number is already used!.";
				break;
			}
			}
			cout << "\nDo You want to add more clients? y/n? ";
			cin >> addMoreClient;
		} while (toupper(addMoreClient) == 'Y');
    }
};

