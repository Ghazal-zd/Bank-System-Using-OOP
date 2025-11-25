#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include"clsBankClient.h"
class clsTransferScreen : protected clsScreen
{

	static void _PrintClientCard(clsBankClient client)
	{
		cout << "\n\nClient Card: ";
		cout << "\n___________________________";
		cout << "\nClient Name: "<< client.FirstName + "  " + client.LastName;
		cout << "\nAccount Number: "<<client.getAccountNumber();
		cout << "\nAccount Balance: "<<client.AccountBalance;
		cout << "\n___________________________";
	}
	static string _ReadAccountNumber(string message) {
		cout << message;
		string accountNumber = clsInputValidate::readString();

		while (!clsBankClient::IsClientExist(accountNumber)) {
			cout << "Account number is not found,Enter another one: ";
			accountNumber = clsInputValidate::readString();
		}
		return accountNumber;
	}
	static float ReadAmount(clsBankClient sourceClient) {
		float amount;
		cout << "\n\nEnter Transfer Amount? ";
		amount = clsInputValidate::ReadDblNumber();

		//while(amount>sourceClient.AccountBalance)/*(!sourceClient.Transfer(amount))*/
		//{
		//	cout << "\nAmount exceeds the available balance, Enter another amount? ";
		//	amount = clsInputValidate::ReadIntNumber();
		//}

		return amount;
	}
public:
	static void ShowTransferScreen() {
		
		system("cls");
		_DrawScreenHeader("\t\tTransfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("\n\nPlease Enter Account Number To Transfer From: "));
		_PrintClientCard(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\n\nPlease Enter Account Number To Transfer To: "));
		_PrintClientCard(DestinationClient);

	
		float amount = ReadAmount(SourceClient);

		char sure = 'y';
		cout << "\nAre you sure you want to perform this operation? y/n? ";
		cin >> sure;

		if (tolower(sure) == 'y')
		{
			if (SourceClient.Transfer(amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\n\nTransfer Done Successfully. ";
			}
			else
			{
				cout << "\nTransfer Failed!\n";
				return;
			}
		}

		_PrintClientCard(SourceClient);
		_PrintClientCard(DestinationClient);
	}
};

/*
         system("cls");
		_DrawScreenHeader("\t\tTransfer Screen");

		cout << "\nPlease Enter Account Number To Transfer From: ";
		string accountNumber1 = _ReadAccountNumber();
		clsBankClient fromClient = clsBankClient::Find(accountNumber1);
		_PrintClientCard(fromClient);

		cout << "\nPlease Enter Account Number To Transfer To: ";
		string accountNumber2 = _ReadAccountNumber();
		clsBankClient toClient = clsBankClient::Find(accountNumber2);
		_PrintClientCard(toClient);

		int amount = 0;
		cout << "\nEnter Transfer Amount? ";
		amount = clsInputValidate::ReadIntNumber();

        while(!fromClient.Transfer(amount))
        {
			cout << "\nAmount exceeds the available balance, Enter another amount? ";
			amount = clsInputValidate::ReadIntNumber();
		}

		char sure = 'n';
		cout << "\nAre you sure you want to perform this operation? y/n?";
		cin >> sure;

		if(tolower(sure)=='y')
		{
			toClient.AccountBalance += amount;
			fromClient.AccountBalance -= amount;

			toClient.Save();
			fromClient.Save();

			cout << "\n\nTransfer Done Successfully. ";

			_PrintClientCard(fromClient);
			_PrintClientCard(toClient);

		}
*/