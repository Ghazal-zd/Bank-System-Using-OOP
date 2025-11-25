#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
using namespace std;

class clsClientListScreen : protected clsScreen
{
private:
	static void printClientRecordLine(clsBankClient client) 
	{
		cout << "\t| " << left << setw(15) << client.getAccountNumber();
		cout << "| " << left << setw(20) << client.FirstName + "  " + client.LastName;
		cout << "| " << left << setw(12) << client.PhoneNumber;
		cout << "| " << left << setw(20) << client.Email;
		cout << "| " << left << setw(12) << client.PINCode;
		cout << "| " << left << setw(12) << client.AccountBalance;
	}
public:

	static void showClientsList() {
		system("cls");

		vector<clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "\t\tClient List Screen";
		string subTitle = "\t\t(" + to_string(vClients.size()) + ") Client(s).";
		clsScreen::_DrawScreenHeader(Title, subTitle);

		cout <<"\n\t__________________________________________________________________";
		cout << "__________________________________________\n";

		cout << "\t| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone Number";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(12) << "PIN Code";
		cout << "| " << left << setw(12) << "Account Balance";

		cout << "\n\t__________________________________________________________________";
		cout << "__________________________________________\n";

		if (vClients.size() == 0)
		{
			cout << "\n\t\t\t\tNo clients available in this system! \n\n";
		}

		for (clsBankClient& client : vClients) {
			printClientRecordLine(client);
			cout << endl;
		}
		cout <<"\n\t__________________________________________________________________";
		cout << "__________________________________________\n";

	}
};

