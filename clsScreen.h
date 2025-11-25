#pragma once
#include<iostream>
#include"Global.h"
#include"clsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title,string subTitle="") {
		cout << "\n\t\t\t\t\t  _______________________________________\n";
		cout << "\n\t\t\t\t\t" << Title;
		if (subTitle != "")
		{
			cout << "\n\t\t\t\t\t" << subTitle;
		}
		cout << "\n\t\t\t\t\t  _______________________________________\n";
		cout << "\n\t\t\t\t\t  User: " << CurrentUser.UserName;
		cout << "\n\t\t\t\t\t  Date: " << clsDate::DateToString(clsDate()) << "\n";

	}

	static bool CheckRightPermissions(clsUser::_enPermissions permission) {
		if (!CurrentUser.checkAccessPermission(permission)) {
			cout << "\n\t\t\t\t\t  _______________________________________\n";
			cout << "\n\t\t\t\t\t  Access Denied! Contact Your Admin.";
			cout << "\n\t\t\t\t\t  _______________________________________\n";
			return false;
		}
		else
		{
			return true;
		}
	}

};

