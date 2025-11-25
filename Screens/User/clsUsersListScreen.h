#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include"clsBankClient.h"
#include "clsUser.h"
#include "clsUtil.h"

class clsUsersListScreen : protected clsScreen
{
	static void _PrintUserRecordLine(clsUser user) {
		cout << "\t\t\t\t| " << left << setw(15) << user.UserName;
		cout << "| " << left << setw(15) << user.Password;
		cout << "| " << left << setw(15) << user.getPermissions();
	}
public:
	static void ShowUsersListScreen() {
		system("cls");
		vector<clsUser> vUsers = clsUser::GetUsersList();
		_DrawScreenHeader("\tUsers List (" + to_string(vUsers.size()) + ") User(s).");

			cout << "\n\t\t\t\t______________________________________________________________\n";
			cout << "\n\t\t\t\t| " << left << setw(15) << "User Name";
			cout << "| " << left << setw(15) << "Password";
			cout << "| " << left << setw(15) << "permissions";
			cout << "\n\t\t\t\t______________________________________________________________\n";
			for (clsUser& u : vUsers) 
			{
				_PrintUserRecordLine(u);
				cout << endl;
			}

	}
};

