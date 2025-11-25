#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include"clsBankClient.h"
class clsTransferLogScreen : protected clsScreen
{ 
	static void _PrintTransferRecord(clsBankClient::stTransferLog transferRecord) 
	{
		cout << "\t| " << left << setw(20) << transferRecord.Date_Time;
		cout << "| " << left << setw(10) << transferRecord.sourceAccountNumber;
		cout << "| " << left << setw(10) << transferRecord.DestinationAccountNumber;
		cout << "| " << left << setw(10) << transferRecord.amount;
		cout << "| " << left << setw(12) << transferRecord.sourceBalance;
		cout << "| " << left << setw(12) << transferRecord.destinationBalance;
		cout << "| " << left << setw(12) << transferRecord.userName;
	}
public:
	static void ShowTransferLogScreen() {
		system("cls");
		_DrawScreenHeader("\t\tTransfer Log Screen");

		vector<clsBankClient::stTransferLog> vTransferLog = clsBankClient::GetTransferLog();

		cout << "\n\t__________________________________________________________________";
		cout << "_____________________________________\n";

		cout << "\t| " << left << setw(20) << "Date/Time";
		cout << "| " << left << setw(10) << "s.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(12) << "s.Balance";
		cout << "| " << left << setw(12) << "d.Balance";
		cout << "| " << left << setw(12) << "User";

		cout << "\n\t__________________________________________________________________";
		cout << "_____________________________________\n";

		for (clsBankClient::stTransferLog& transferLog : vTransferLog)
		{
			_PrintTransferRecord(transferLog);
			cout << endl;
		}
	}
};

