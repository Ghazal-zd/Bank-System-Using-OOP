#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include"clsBankClient.h"
#include"clsUsersListScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{
	enum enManageUsersOption { eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eShowMainMenu2 = 6 };

	static short _ReadManageUsersOption() {
		cout << "\n\t\t\t\t\tChoose what do you want to do [1 to 6]? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 6, "\nPlease enter a number between 1 and 6: ");
		return choice;
	}

	static void _GoBackToManageUsersScreen() {
		cout<<"\nPress any key to go back to manage users screen...";
		system("Pause>0");
		showManageUserScreen();
	}

	static void	_ShowUsersList() {
		clsUsersListScreen::ShowUsersListScreen();
	}
	static void _ShowAddUsersScreen() {
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void  _ShowDeleteUserScreen() {
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen() {
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen() {
		clsFindUserScreen::ShowFindUserScreen();
	}
	static void _ShowMainMenu() {

	}

	static void performManageUsersOption(enManageUsersOption mangeMenuOption) 
	{
		switch (mangeMenuOption)
		{
		case enManageUsersOption::eListUsers:
		{
			system("cls");
			_ShowUsersList();
			_GoBackToManageUsersScreen();
			break;
		}
		case enManageUsersOption::eAddNewUser:
		{
			system("cls");
			_ShowAddUsersScreen();
			_GoBackToManageUsersScreen();
			break;
		}
		case enManageUsersOption::eDeleteUser:
		{
			 system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersScreen();
			break;
		}
		case enManageUsersOption::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersScreen();
			break;
		}
		case enManageUsersOption::eFindUser :
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersScreen();	
			break;
		}
		case enManageUsersOption::eShowMainMenu2:
		{
		}

	}
}
public:
	static void showManageUserScreen() {
		system("cls");
		_DrawScreenHeader("\t\tManage Users Screen");

		cout <<setw(37) << left << "\n\t\t\t\t\t============================================";
		cout <<setw(37)  << left << "\n\t\t\t\t\t            Manage Users Menu Screen             ";
		cout <<setw(37)  << left << "\n\t\t\t\t\t============================================";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[1] List Users.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[2] Add New User.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[3] Delete User.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[4] Update User.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[5] Find User.";
		cout <<setw(37)  << left << "\n\t\t\t\t\t[6] Main Menu";
		cout <<setw(37)  << left << "\n\t\t\t\t\t============================================";
		performManageUsersOption((enManageUsersOption)_ReadManageUsersOption());
	}
};

