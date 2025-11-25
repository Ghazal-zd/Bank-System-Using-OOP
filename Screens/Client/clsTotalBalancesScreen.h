#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include"clsBankClient.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsUtil.h"
class clsTotalBalancesScreen:protected clsScreen
{
	static void _PrintClientRecordBalanceLine(clsBankClient client)
	{
		cout << "\t\t\t\t| " << setw(15) << client.getAccountNumber();
		cout << "| " << left << setw(20) << client.FirstName + "  " + client.LastName;
		cout << "| " << left << setw(12) << client.AccountBalance;
	}

public:
	static void ShowTotalBalancesScreen() {
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\tTotal Balances Screen";
		string subTitle = "\tBalances List(" + to_string(vClients.size()) + ") Client(s).\n";
		_DrawScreenHeader(Title,subTitle);


			cout <<"\n\t\t\t\t__________________________________________________________________\n";

			cout << "\n\t\t\t\t| " << left << setw(15) << "Account Number";
			cout << "| " << left << setw(20) << "Client Name";
			cout << "| " << left << setw(12) << "Account Balance";

			cout << "\n\t\t\t\t__________________________________________________________________\n";


			for (clsBankClient& client : vClients) {
			    _PrintClientRecordBalanceLine(client);
				cout << endl;
			}
			cout << "\n\t\t\t\t__________________________________________________________________\n";

			double totalBalances = clsBankClient::getTotalBalances();
			cout << clsUtil::Tabs(5) << "Total Balance is : " << totalBalances << endl;
			cout << clsUtil::Tabs(5) << clsUtil::numberToText(totalBalances) << endl;
		
	}
};

