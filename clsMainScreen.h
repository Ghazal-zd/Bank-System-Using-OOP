#pragma once
#include<iostream>
#include<iomanip>
#include<string>

#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsBankClient.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"clsRegisterLogInScreen.h"
#include"clsCurrencyExchangeScreen.h"
#include"Global.h"


using namespace std; 
class clsMainScreen : protected clsScreen
{
	enum _enMainMenuOptions { eListClient = 1, eAddNewClients = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5,
		eShowTransactionMenu = 6, eManageUsers = 7, eRegisterLogIn=8 , eCurrencyExchange=9, eLogout=10 };

	static short _ReadManageMenuOption() 
	{
		cout << "\n\t\t\t\t\tChoose What Do You Want To Do? [1 to 10]? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 10,"\nPlease Enter Number Between 1 and 10: ");
		return choice;
	}

	static void _ShowAllClientsScreen() 
	{
		if (!CheckRightPermissions(clsUser::_enPermissions::eShowClientListPermission)) {
			return;
		}
		clsClientListScreen::showClientsList();
	}

	static void _AddNewClients()
	{
		if (!CheckRightPermissions(clsUser::_enPermissions::eAddNewClientPermission)) {
			return;
		}
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		if (!CheckRightPermissions(clsUser::_enPermissions::eDeleteClientPermission)) {
			return;
		}
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen() 
	{
		if (!CheckRightPermissions(clsUser::_enPermissions::eUpdateClientInfoPermission)) {
			return;
		}
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		if (!CheckRightPermissions(clsUser::_enPermissions::eFindClientPermission)) {
			return;
		}
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionMenu() 
	{
		if (!CheckRightPermissions(clsUser::_enPermissions::eShowTransactionMenuPermission)) {
			return;
		}
		clsTransactionsScreen::ShowTransactionScreen();
	}

	static void _ShowManageUsersScreen()
	{
		if (!CheckRightPermissions(clsUser::_enPermissions::eManageUsersPermission)) {
			return;
		}
		clsManageUsersScreen::showManageUserScreen();
	}

	static void _ShowRegisterLogin() {
		if (!CheckRightPermissions(clsUser::_enPermissions::eRegisterLoginScreen)) {
			return;
		}
		clsRegisterLogInScreen::ShowRegisterLogInScreen();

	}

	static void _ShowCurrencyExchangeScreen() {
		if (!CheckRightPermissions(clsUser::_enPermissions::eCurrencyExchangeScreen)) {
			return;
		}
		clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
	}

	static void _ShowEndScreen() {
		CurrentUser = clsUser::Find("", "");
	}

	
	static void _GoBackToMainMenu() {
		cout << "\n\tPress any key to go back to main menu...";
		system("pause>0");
		showMainMenu();
	}


	static void performMainMenuOption(_enMainMenuOptions mainMenuOption) {
		switch (mainMenuOption)
		{
		case _enMainMenuOptions::eListClient:
		{
			 system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case _enMainMenuOptions::eAddNewClients:
		{
			system("cls");
			_AddNewClients();
			_GoBackToMainMenu();
			break;
		}
		case _enMainMenuOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case _enMainMenuOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case _enMainMenuOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case _enMainMenuOptions::eShowTransactionMenu:
		{
			system("cls");
			_ShowTransactionMenu();
			_GoBackToMainMenu();
			break;
		}
		case _enMainMenuOptions::eManageUsers:
		{
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenu();
			break;
		}
		case _enMainMenuOptions::eRegisterLogIn:
		{
			system("cls");
			_ShowRegisterLogin();
			_GoBackToMainMenu();
			break;
		}
		case _enMainMenuOptions::eCurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenu();
			break;
		}
		case _enMainMenuOptions::eLogout:
		{
			system("cls");
			CurrentUser = clsUser::Find("", "");
			break;
		}
		}
	}
public:
	static void showMainMenu() {
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "\n\t\t\t\t\t============================================";
		cout << setw(37) << left << "\n\t\t\t\t\t           Main Menu             ";
		cout << setw(37) << left << "\n\t\t\t\t\t============================================";
		cout << setw(37) << left << "\n\t\t\t\t\t[1] List Clients.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[2] Add New Client.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[3] Delete Client.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[4] Update Client.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[5] Find Client.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[6] Transaction.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[7] Manage Users.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[8] Login Register.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[9] Currency Exchange.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[10] Logout";
		cout <<setw(37)  << left << "\n\t\t\t\t\t============================================";
		performMainMenuOption((_enMainMenuOptions)_ReadManageMenuOption());
	}
};


/*
bool checkUserPermission(sUser user, enPermissions permission) {

	if (user.permissions == enPermissions::eFullAccess)
		return true;

	if ((permission & user.permissions) == permission)
		return true;

	return false;
}
void ShowAllClientsScreen()
{
	if (!checkUserPermission(currentUser, enPermissions::eShowClientListPermission))
	{
		showDeniedScreen();
		return;
	}
}
*/