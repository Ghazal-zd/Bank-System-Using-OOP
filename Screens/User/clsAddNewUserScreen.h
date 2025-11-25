#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"clsString.h"
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsAddNewUserScreen : protected clsScreen
{
private: 
	
    static void _Print(clsUser user) {
		cout << "\nUser Info: ";
		cout << "\n----------------------";

		cout << "\nFirst Name     : " << user.FirstName;
		cout << "\nLast Name      : " << user.LastName;
		cout << "\nFull Name      : " << user.FirstName +" "+user.LastName;
		cout << "\nPhone number   : " << user.PhoneNumber;
		cout << "\nEmail          : " << user.Email;
		cout << "\nUser Name      : " << user.UserName;
		cout << "\nPassword       : " << user.Password;
		cout << "\nPermissions    : " << user.Permissions;
		cout << "\n----------------------";

	}

	static int _ReadPermissions() {
		int Permissions = 0;

		char access = 'y';
		cout << "\n Do you want to give full access? y/n? ";
		cin >> access;

		if (tolower(access) == 'y')
		{
			return -1;
		}
		else
		{
			cout << "\nDo you want to give access to : \n";
			cout << "\nShow client list ? y/n ?";
			cin >> access;
			if (tolower(access) == 'y')
				Permissions = clsUser::_enPermissions::eShowClientListPermission;

			cout << "\nShow Add New Client List ? y/n ?";
			cin >> access;
			if (tolower(access) == 'y')
				Permissions += clsUser::_enPermissions::eAddNewClientPermission;

			cout << "\nShow Delete Client List ? y/n ?";
			cin >> access;
			if (tolower(access) == 'y')
				Permissions += clsUser::_enPermissions::eDeleteClientPermission;

			cout << "\nShow Update Client List ? y/n ?";
			cin >> access;
			if (tolower(access) == 'y')
				Permissions += clsUser::_enPermissions::eUpdateClientInfoPermission;

			cout << "\nShow Find Client list ? y/n ?";
			cin >> access;
			if (tolower(access) == 'y')
				Permissions += clsUser::_enPermissions::eFindClientPermission;

			cout << "\nShow Transactions list ? y/n ?";
			cin >> access;
			if (tolower(access) == 'y')
				Permissions += clsUser::_enPermissions::eShowTransactionMenuPermission;

			cout << "\nShow Manage Users list ? y/n ?";
			cin >> access;
			if (tolower(access) == 'y')
				Permissions += clsUser::_enPermissions::eManageUsersPermission;

			cout << "\nShow Login Register List ? y/n ?";
			cin >> access;
			if (tolower(access) == 'y')
				Permissions += clsUser::_enPermissions::eRegisterLoginScreen;

			cout << "\nShow Currency Exchange Screen ? y/n ?";
			cin >> access;
			if (tolower(access) == 'y')
				Permissions += clsUser::_enPermissions::eCurrencyExchangeScreen;

		}
		return Permissions;
	}

	static void _ReadUserInfo(clsUser& user) {
		cout << "\nEnter First Name: ";
		user.FirstName = clsInputValidate::readString();
		cout << "\nEnter Last Name: ";
		user.LastName = clsInputValidate::readString();
		cout << "\nEnter Email: ";
		user.Email = clsInputValidate::readString();
		cout << "\nEnter phone number: ";
		user.PhoneNumber = clsInputValidate::readString();
		cout << "\nEnter Password: ";
		user.Password = clsInputValidate::readString();
		cout << "\nEnter Permissions: ";
		user.Permissions = _ReadPermissions();
		
	}

	static string _ReadUserName() {
		string userName = clsInputValidate::readString();
		return userName;
	}

public: 
	static void ShowAddNewUserScreen() {
		system("cls");
		_DrawScreenHeader("\t\tAdd New User Screen");

		char addMoreUsers = 'n';
    do{
		cout << "Enter User Name: ";
		string userName = _ReadUserName();

		while (clsUser::IsUserExist(userName)) 
		{
			cout << "\nUser Name [" << userName << "] is already exist, Enter another one: ";

		    userName = _ReadUserName();
		}

		clsUser user = clsUser::AddNewUser(userName);
		_ReadUserInfo(user);

		clsUser::enSaveResult saveResult;
		saveResult = user.Save();

		switch(saveResult) {
		case clsUser::enSaveResult::svSucceeded:
		{
			cout << "\nClient Added Successfully :-) ";
			_Print(user);
			break;
		}
		case clsUser::enSaveResult::svFaildEmptyObject:
		{
			cout << "Error, client cannot added because it is empty!.";
			break;
		}
		case clsUser::enSaveResult::svFailedUserNameIsUsed:
		{
			cout << "Error this account number is already used!.";
			break;
		}
		}
		cout << "\nDo You want to add more Users? y/n? ";
		cin >> addMoreUsers;
	   } while (toupper(addMoreUsers) == 'Y');
	}
	
};

