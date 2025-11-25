#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"clsString.h"
#include"clsPerson.h"
#include"clsDate.h"
#include"clsUtil.h"
using namespace std;
class clsUser : public clsPerson
{
	enum _enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 3 };

	_enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;

	bool  markForDeleted = false;

	struct stLoginRegister;
	static stLoginRegister _ConvertLineToUserRecord(string line, string separator = "#//#") {
		stLoginRegister userRecord;
		vector<string> vUsers = clsString::split(line, separator);

		userRecord.Date_Time = vUsers[0];
		userRecord.userName = vUsers[1];
		userRecord.password = clsUtil::decryptText(vUsers[2],2);
		userRecord.permissions = stoi(vUsers[3]);
		return userRecord;

	}

	 static clsUser _ConvertDataLineToUserObject(string line, string separator="#//#") {
		vector<string> vUsers = clsString::split(line,separator);
		return clsUser (_enMode::UpdateMode, vUsers[0], vUsers[1], vUsers[2], vUsers[3]
			, vUsers[4], clsUtil::decryptText(vUsers[5],2), stoi(vUsers[6]));
	}

	 static string _ConvertUserObjectToLine(clsUser user, string separator = "#//#") {
		 string UserObject = "";

		 UserObject += user.FirstName + separator;
		 UserObject += user.LastName + separator;
		 UserObject += user.Email + separator;
		 UserObject += user.PhoneNumber + separator;
		 UserObject += user.UserName + separator;
		 UserObject += clsUtil::encryptText(user.Password,2) + separator;
		 UserObject += to_string(user.getPermissions());

		 return UserObject;
	 }

	 static clsUser _GetEmptyUserObject()
	 {
		 return clsUser(_enMode::EmptyMode, " ", " ", " ", " ", " ", " ", 0);
	 }

	 static vector<clsUser> _LoadDataFromFile(string fileName) {
		 vector<clsUser> vUsers;
		 fstream myFile;
		 myFile.open("Users.txt", ios::in);
		 if (myFile.is_open())
		 {
			 string line;
			 while (getline(myFile, line))
			 {
				 clsUser user = _ConvertDataLineToUserObject(line);

				 vUsers.push_back(user);
			 }
		 }
		 myFile.close();
		 return vUsers;
	 }

	 static void _SaveUserDateToFile(vector<clsUser> vUsers) {
		 fstream myFile;
		 myFile.open("Users.txt", ios::out );
		 if (myFile.is_open())
		 {
			 string dataLine;
			 for (clsUser& u : vUsers)
			 {
				 if (u.markForDeleted == false)
				 {
					 dataLine = _ConvertUserObjectToLine(u);
					 myFile << dataLine << endl;
				 }
			 }
		 }
		 myFile.close();
	 }

	 void _AddDataLineToFile(string dataLine)
	 {
		 fstream file1;
		 file1.open("Users.txt", ios::out);
		 if (file1.is_open())
		 {
			 file1 << dataLine << endl;
			 file1.close();
		 }
	 }

	 void _Update()
	 {
		 vector<clsUser> vUsers = _LoadDataFromFile("Users.txt");
		 for (clsUser& u : vUsers)
		 {
			 if (u.UserName == UserName)
			 {
				 u = *this;
				 break;
			 }
		 }
		 _SaveUserDateToFile(vUsers);
	 }

	 void _AddNewUser()
	 {
		 //_AddDataLineToFile(_ConvertUserObjectToLine(*this));
		 vector<clsUser> vUsers = _LoadDataFromFile("Users.txt");
		 vUsers.push_back(*this);
		 _SaveUserDateToFile(vUsers);
	 }

	

	 string _PrepareLigInRecord(string separator = "#//#") {
		 string LoginRecord = "";

		 LoginRecord += clsDate::getSystemDateTimeString() + separator;
		 LoginRecord += UserName + separator;
		 LoginRecord += clsUtil::encryptText(Password,2)+ separator;
		 LoginRecord += to_string(getPermissions());

		 return LoginRecord;
	 }

	  
public:
	enum _enPermissions
	{
		eFullAccess = -1, eShowClientListPermission = 1, eAddNewClientPermission = 2, eDeleteClientPermission = 4, eUpdateClientInfoPermission = 8, eFindClientPermission = 16,
		eShowTransactionMenuPermission = 32, eManageUsersPermission = 64 , eRegisterLoginScreen = 128 , eCurrencyExchangeScreen = 256
	};
	struct stLoginRegister
	{
		string Date_Time;
		string userName;
		string password;
		int permissions;
	};

	void setUserName(string userName) {
	    _UserName = userName;
	}
	string getUserName() {
		return _UserName;
	}
	__declspec(property(get = getUserName, put = setUserName))string UserName;

	void setPassword(string password) {
		_Password = password;
	}
	string getPassword() {
		return _Password;
	}
	__declspec(property(get = getPassword, put = setPassword))string Password;

	void setPermissions(int permissions) {
		_Permissions = permissions;
	}
	int getPermissions() {
		return _Permissions;
	}
	__declspec(property(get = getPermissions, put = setPermissions))int Permissions;

	clsUser(_enMode mode,string FirstName, string LastName, string Email, string Phone
		 ,string userName,string password,int permissions) 
		: clsPerson(FirstName,LastName,Email,Phone) {
		_UserName = userName;
		_Password = password;
		_Permissions = permissions;
		_Mode = mode;
	}
	
	 bool IsEmpty() 
	 {
		 return(_Mode == _enMode::EmptyMode);
	 }

	static clsUser Find(string userName) 
	{
		fstream myFile;
		vector<clsUser> vUsers;
		myFile.open("Users.txt", ios::in);
		if (myFile.is_open()) 
		{
			string line;
			while (getline(myFile, line)) {
				clsUser user = _ConvertDataLineToUserObject(line);
				if (user.UserName == userName) {
					myFile.close();
					return user;
				}
				vUsers.push_back(user);
			}
			myFile.close();
		}
		return _GetEmptyUserObject();
	}

	static clsUser Find(string userName,string password) {
		fstream myFile;
		vector<clsUser> vUsers;
		myFile.open("Users.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsUser user = _ConvertDataLineToUserObject(line);
				if (user._UserName == userName && user.Password==password) {
					myFile.close();
					return user;
				}
				vUsers.push_back(user);
			}
			myFile.close();
		}
		return _GetEmptyUserObject();
	}
	
	static bool IsUserExist(string userName)
	{
		clsUser user = clsUser::Find(userName);
		return(!user.IsEmpty());
	}

	static vector<clsUser> GetUsersList() {
		return _LoadDataFromFile("Users.txt");
	}

	static clsUser AddNewUser(string userName) {
		return clsUser(_enMode::AddNewMode, " ", " ", " ", " ", userName, " ", 0);
	}

	 bool Delete() {
		vector<clsUser> vUsers = GetUsersList();
		for (clsUser& u : vUsers)
		{
			if (u.UserName == UserName)
			{
				u.markForDeleted = true;
				break;
			}

		}
		_SaveUserDateToFile(vUsers);

		*this = _GetEmptyUserObject();

		return true;
	}
	
	 enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1, svFailedUserNameIsUsed = 2 };

	 enSaveResult Save() 
	 {
		 switch (_Mode)
		 {
		 case _enMode::EmptyMode:
		 {
			 return enSaveResult::svFaildEmptyObject;
			 break;
		 }
		 case _enMode::UpdateMode:
		 {
			 _Update();
			 return enSaveResult::svSucceeded;
			 break;
		 }
		 case _enMode::AddNewMode:
		 {
			 if (IsUserExist(UserName))
			 {
				 return enSaveResult::svFailedUserNameIsUsed;
		   	 }
			 else
			 {
				 _AddNewUser();
				 _Mode = _enMode::UpdateMode;
				 return enSaveResult::svSucceeded;
			 }
			 break;
		 }
		 }
	 }

	 bool checkAccessPermission(clsUser::_enPermissions permission) {

		 if (this->Permissions == clsUser::_enPermissions::eFullAccess)
			 return true;

		 if ((permission & this->Permissions) == permission)
			 return true;

		 return false;
	 }

	  void RegisterLogIn() {
		 fstream myFile;
		 string line;

		 line = _PrepareLigInRecord();

		 myFile.open("LoginRegister.txt", ios::app);
		 if (myFile.is_open())
		 {
			 myFile << line << endl;
		 }
		 myFile.close();
	 }		

	  static vector<stLoginRegister> GetLoginRegisterList() {
		  vector<stLoginRegister> vLoginRegisterRecord;
		  fstream myFile;
		  myFile.open("LoginRegister.txt", ios::in);
		  if (myFile.is_open())
		  {
			  string line;
			  while (getline(myFile, line))
			  {
				  stLoginRegister user = _ConvertLineToUserRecord(line);

				  vLoginRegisterRecord.push_back(user);
			  }
		  }
		  myFile.close();
		  return vLoginRegisterRecord;
	  
	  }
};

