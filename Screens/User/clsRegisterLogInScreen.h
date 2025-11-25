#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"clsString.h"
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsRegisterLogInScreen : protected clsScreen
{
	static void _PrintUserRecordLine(clsUser::stLoginRegister user) {
	    cout << "\t\t\t| " << left << setw(30) << user.Date_Time;
		cout << "| " << left << setw(15) << user.userName;
		cout << "| " << left << setw(15) << user.password;
		cout << "| " << left << setw(15) << user.permissions;
	}

public:
	static void ShowRegisterLogInScreen() 
	{
		system("cls");

		vector<clsUser::stLoginRegister> vUsersInLoginRegister = clsUser::GetLoginRegisterList();

		string title = "\t  Login Register List Screen";
		string subTitle = "\t\t" + to_string(vUsersInLoginRegister.size()) + " Records. ";
		_DrawScreenHeader(title, subTitle);

		cout << "\n\t\t\t______________________________________________________________";
		cout<<"______________________\n"; 
		cout << "\n\t\t\t| " << left << setw(30) << "Date/Time";
		cout << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(15) << "Password";
		cout << "| " << left << setw(15) << "permissions";
		cout << "\n\t\t\t______________________________________________________________";
		cout << "______________________\n";

		for (clsUser::stLoginRegister  u : vUsersInLoginRegister)
		{
			_PrintUserRecordLine(u);
			cout << endl;
		}
	}
};


