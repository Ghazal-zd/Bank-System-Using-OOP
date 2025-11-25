#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
#include"clsMainScreen.h"
#include"clsDate.h"
#include"Global.h"
class clsLoginScreen : protected clsScreen
{

	static bool _Login() {
		bool loginFailed = false;

		short numOfTrials = 3;

		string password, userName;
		
			do {

				if (loginFailed)
				{
					numOfTrials--;
					cout << "\nInvalid user name/password! ";
					cout << "\nYou have " << numOfTrials << " Trials to login.\n";

					if (numOfTrials == 0) 
					{
						cout << "\n\nYou are locked after 3 failed trials.\n";
						return false;
					}
					
				}
				cout << "\nEnter User Name: ";
				cin >> userName;
				cout << "Enter Password: ";
				cin >> password;

				CurrentUser = clsUser::Find(userName, password);

				loginFailed = CurrentUser.IsEmpty();

			} while (loginFailed );

			CurrentUser.RegisterLogIn();
			clsMainScreen::showMainMenu();
			return true;
}
public:
	static bool ShowLoginScreen()
	{
	
			 system("cls");
			_DrawScreenHeader("\t\tLogin Screen");
			return _Login();
			

	}
};


/*	//static string _ConvertUserObjectToLine(clsUser user, string separator = "#//#") {
	//	string UserObject = "";

	//	UserObject += clsDate::getSystemDateTimeString() + separator;
	//	UserObject += user.UserName + separator;
	//	UserObject += user.Password + separator;
	//	UserObject += to_string(user.getPermissions());

	//	return UserObject;
	//}
	//static void _AddUserToLoginRegisterFile() {
	//	vector<clsUser>vUsers;
	//	fstream myFile;
	//	myFile.open("LoginRegister.txt", ios::app);
	//	if (myFile.is_open())
	//	{
	//		string line;
	//		line = _ConvertUserObjectToLine(CurrentUser);
	//		myFile << line << endl;
	//	}
	//	myFile.close();
	//}
*/