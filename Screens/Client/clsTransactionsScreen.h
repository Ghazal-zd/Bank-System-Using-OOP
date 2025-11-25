#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include"clsBankClient.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionsScreen : protected clsScreen
{
	enum _enTransactionMenuOptions { eDeposit = 1, eWithdrow = 2, eTotalBalance = 3, eTeransfer = 4, eTransferLogScreen=5, eShowMainMenu = 6 };

	static short _ReadTransactionMenuOption()
	{
		cout << "\n\t\t\t\t\tChoose what do you want to do [1 to 6]? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Please enter a number between 1 and 6: ");
		return choice;
	}

	static void _GoBackToTransactionMenu() {
		cout << "\nPress any key to go back to transaction menu..";
		system("pause>0");
		ShowTransactionScreen();
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen() {
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen() {
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void performTransactionMenuOption(_enTransactionMenuOptions transactionMenuOption) {
		switch (transactionMenuOption)
		{
		case _enTransactionMenuOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case _enTransactionMenuOptions::eWithdrow:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case _enTransactionMenuOptions::eTotalBalance:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case _enTransactionMenuOptions::eTeransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case _enTransactionMenuOptions::eTransferLogScreen:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenu();
			break;
		}
		

		case _enTransactionMenuOptions::eShowMainMenu:
		{
			//system("cls");
			break;
		}
		}
	}
public:

	static void ShowTransactionScreen() {
		system("cls");
		_DrawScreenHeader("\t\tTransactions Screen");

		cout <<setw(37)  << left << "\n\t\t\t\t\t============================================";
		cout <<setw(37)  << left << "\n\t\t\t\t\t             Transaction menu Screen             ";
		cout <<setw(37)  << left << "\n\t\t\t\t\t============================================";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[1] Deposit.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[2] Withdraw.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[3] Total Balances.";
		cout << setw(37) << left << "\n\t\t\t\t\t[4] Transfer.";
		cout << setw(37) << left << "\n\t\t\t\t\t[5] Transfer Log.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[6] Main Menu";
		cout <<setw(37)  << left << "\n\t\t\t\t\t============================================";
		performTransactionMenuOption((_enTransactionMenuOptions)_ReadTransactionMenuOption());
	}
};

