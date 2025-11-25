#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"clsString.h"
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsDeleteUserScreen : protected clsScreen
{
	static void _Print(clsUser user) {
		cout << "\nUser Info: ";
		cout << "\n----------------------";

		cout << "\nFirst Name     : " << user.FirstName;
		cout << "\nLast Name      : " << user.LastName;
		cout << "\nFull Name      : " << user.FirstName + " " + user.LastName;
		cout << "\nPhone number   : " << user.PhoneNumber;
		cout << "\nEmail          : " << user.Email;
		cout << "\nUser Name      : " << user.UserName;
		cout << "\nPassword       : " << user.Password;
		cout << "\nPermissions    : " << user.Permissions;
		cout << "\n----------------------";

	}

	static string _ReadUserName() {
		string userName = clsInputValidate::readString();
		return userName;
	}
public:
	static void ShowDeleteUserScreen() {
		system("cls");
		_DrawScreenHeader("\t\tDelete User Screen");

		cout << "\nEnter User Name: ";
		string userName = _ReadUserName();

		while (!clsUser::IsUserExist(userName)) {
			cout << "\nUserName is not Found, Enter another one: ";
			userName = _ReadUserName();
		}
		clsUser user = clsUser::Find(userName);
		_Print(user);

		char sure = 'n';
		cout << "\nAre you sure you want to delete this user? ";
		cin >> sure;

		if(tolower(sure)=='y')
		{
			if(user.Delete())
			{
				cout << "\nUser Deleted Successfully :-)";
				_Print(user);
			}
		}
		else
		{
			cout << "\nOperation Cancelled!";
		}
	}
};

