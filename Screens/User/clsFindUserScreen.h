#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"clsString.h"
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsFindUserScreen : protected clsScreen
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

	static void ShowFindUserScreen() {
		system("cls");
		_DrawScreenHeader("\t\tFind Users Screen");

		cout << "\nPlease enter user name: ";
		string userName = _ReadUserName();
		while (!clsUser::IsUserExist(userName)) {
			cout << "\nUserName is not Found, Enter another one: ";
			userName = _ReadUserName();
		}
		clsUser user = clsUser::Find(userName);

		if (!user.IsEmpty())
		{
			cout << "\nUser Found :-)\n";
		}
		else
		{
			cout << "\nUser is not found!.\n";
		}
		_Print(user);

	}
};

