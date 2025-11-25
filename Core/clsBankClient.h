//clsBankClient
#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"clsString.h"
#include"clsPerson.h"
#include"Global.h"
using namespace std;
class clsBankClient : public clsPerson
{
private:
	enum _enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	_enMode _Mode;

	string _AccountNumber;
	string _PINCode;
	float _AccountBalance;
	bool _MarkForDeleted = false;

	struct stTransferLog;
	 static stTransferLog _ConvertLineToTransferLogRecord(string line, string delimiter="#//#") {
		stTransferLog transferLogRecord;
		vector<string> vTransfersLog = clsString::split(line,delimiter);
		transferLogRecord.Date_Time = vTransfersLog[0];
		transferLogRecord.sourceAccountNumber = vTransfersLog[1];
		transferLogRecord.DestinationAccountNumber = vTransfersLog[2];
		transferLogRecord.amount = stod(vTransfersLog[3]);
		transferLogRecord.sourceBalance = stod(vTransfersLog[4]);
		transferLogRecord.destinationBalance = stod(vTransfersLog[5]);
		transferLogRecord.userName = vTransfersLog[6];
		return transferLogRecord;


	}
	static clsBankClient _ConvertLineDataToClientObject(string line, string separator = "#//#") {

		vector<string> vClientData;

		vClientData = clsString::split(line, separator);

		return clsBankClient(_enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4]
			, vClientData[5], stod(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient client, string separator = "#//#") {
		string stClientObject = "";

		stClientObject += client.FirstName + separator;
		stClientObject += client.LastName + separator;
		stClientObject += client.Email + separator;
		stClientObject += client.PhoneNumber + separator;
		stClientObject += client.getAccountNumber() + separator;
		stClientObject += client.PINCode + separator;
		stClientObject += to_string(client.AccountBalance);

		return stClientObject;
	}

	static vector<clsBankClient> _LoadDataFromFile(string fileName) {
		vector<clsBankClient> vOfClients;
		fstream file1;
		file1.open(fileName, ios::in);
		if (file1.is_open())
		{
			string line;
			while (getline(file1, line))
			{
				clsBankClient client = _ConvertLineDataToClientObject(line);

				vOfClients.push_back(client);
			}
		}
		file1.close();
		return vOfClients;
	}

	static void _SaveClientDataToFile(vector<clsBankClient> vClients) {
		fstream file1;
		file1.open("Clients.txt", ios::out);
		string dataLine;

		if (file1.is_open())
		{
			for (clsBankClient& c : vClients)
			{
				if (c.markForDelete == false)
				{
					dataLine = _ConvertClientObjectToLine(c);
					file1 << dataLine << endl;
				}

			}
		}
		file1.close();
	}

	void _AddDataLineToFile(string dataLine) {
		fstream file1;
		file1.open("Clients.txt",  ios::app);
		if (file1.is_open())
		{
			file1 << dataLine << endl;
			file1.close();
		}
	}
	void _Update() {
		vector<clsBankClient> _vClients = _LoadDataFromFile("Clients.txt");
		for (clsBankClient& c : _vClients)
		{
			if (c.getAccountNumber() == getAccountNumber())
			{
				c = *this;
				break;
			}
		}

		_SaveClientDataToFile(_vClients);
	}

	void _AddNewClient()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));	
	}

	static clsBankClient _GetEmptyClientObject() 
	{
		return clsBankClient(_enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	string _PrepareTransferLog(float amount, clsBankClient DestinationClient,string userName, string separator = "#//#")
	{

		string transferOperation = "";

		transferOperation += clsDate::getSystemDateTimeString() + separator;
		transferOperation += getAccountNumber() + separator;
		transferOperation += DestinationClient.getAccountNumber() + separator;
		transferOperation += to_string(amount) + separator;
		transferOperation += to_string(AccountBalance) + separator;
		transferOperation += to_string(DestinationClient.AccountBalance) + separator;
		transferOperation += userName;

		return transferOperation;

	}

	void _RegisterTransferLog(float amount, clsBankClient destinationClient, string userName) {
		string line = _PrepareTransferLog(amount, destinationClient, userName);

		fstream file;
		file.open("TransferLog.txt", ios::app);
		if (file.is_open())
		{
			file << line << endl;
		}
		file.close();
	}
public:
	string getAccountNumber()
	{
		return _AccountNumber;
	}

	void setPINCode(string pinCode) 
	{
		_PINCode = pinCode;
	}

	string getPINCode() 
	{
		return _PINCode;
	}
	__declspec(property(get = getPINCode, put = setPINCode))string PINCode;


	void setMarkForDelete(bool markForDeleted) {
		_MarkForDeleted = markForDeleted;
	}
	bool getMarkForDelete() {
		return _MarkForDeleted;
	}
	__declspec(property(get = getMarkForDelete, put = setMarkForDelete))bool markForDelete;

	void setAccountBalance(float accountBalance) {
		_AccountBalance = accountBalance;
	}
	float getAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = getAccountBalance, put = setAccountBalance))float AccountBalance;

	clsBankClient(_enMode mode, string firstName, string lastName, string Email, string phoneNumber,
		string accountNumber, string PIN, float accountBalance) :
		clsPerson(firstName, lastName, Email, phoneNumber) {
		_Mode = mode;
		_AccountNumber = accountNumber;
		_PINCode = PIN;
		_AccountBalance = accountBalance;
	}
	struct stTransferLog {
		string Date_Time;
		string sourceAccountNumber;
		string DestinationAccountNumber;
		float amount;
		double sourceBalance;
		double destinationBalance;
		string userName;
	};

	static vector<stTransferLog> GetTransferLog() {
		fstream file;
		vector<stTransferLog> vClientsTransferLog;

		file.open("TransferLog.txt", ios::in);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				stTransferLog transferLog = _ConvertLineToTransferLogRecord(line);
				vClientsTransferLog.push_back(transferLog);
			}
			file.close();
		}
		return vClientsTransferLog;
	}

	bool IsEmpty()
	{
		return (_Mode == _enMode::EmptyMode);
	}

	static clsBankClient Find(string accountNumber) {
		vector<clsBankClient> vOfClients;
		fstream file1;

		file1.open("Clients.txt", ios::in);
		if (file1.is_open())
		{
			string line;
			while (getline(file1, line))
			{
				clsBankClient client = _ConvertLineDataToClientObject(line);
				if (client.getAccountNumber() == accountNumber) {
					file1.close();
					return client;
				}
				vOfClients.push_back(client);
			}
			file1.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string accountNumber, string pinCode) {
		vector<clsBankClient> vOfClients;
		fstream file1;

		file1.open("Clients.txt", ios::in);
		if (file1.is_open())
		{
			string line;
			while (getline(file1, line))
			{
				clsBankClient client = _ConvertLineDataToClientObject(line);
				if (client.getAccountNumber() == accountNumber && client.getPINCode() == pinCode) {
					file1.close();
					return client;
				}
				vOfClients.push_back(client);
			}
			file1.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string accountNumber) {
		clsBankClient client1 = clsBankClient::Find(accountNumber);
		return (!client1.IsEmpty());
	}

	enum enSaveResult { svFailedEmptyObject = 0, svSucceeded = 1, svFailedAccountNumberIsExist = 2 };

	enSaveResult Save() {
		switch (_Mode)
		{
		case _enMode::EmptyMode:
		{
		    return enSaveResult::svFailedEmptyObject;		
		}
		case _enMode::UpdateMode:
		{
			_Update();
			return enSaveResult::svSucceeded;
			break;
		}
		case _enMode::AddNewMode:
		{
			if (IsClientExist(getAccountNumber()))
			{
				return enSaveResult::svFailedAccountNumberIsExist;
			}
			else
			{
				_AddNewClient();
				_Mode = _enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
			break;
		}
		}
	}

	static clsBankClient GetAddNewClientObject(string accountNumber) {
		return clsBankClient(_enMode::AddNewMode, "", "", "", "", accountNumber, "", 0);
	}
	
	static vector<clsBankClient> GetClientsList() {
		return _LoadDataFromFile("Clients.txt");
	}

	bool Delete() {
		vector<clsBankClient> _vClients = GetClientsList();
		for (clsBankClient& c : _vClients)
		{
			if (c.getAccountNumber() == getAccountNumber())
			{
				c.markForDelete = true;
				break;
			}

		}
		_SaveClientDataToFile(_vClients);

		*this = _GetEmptyClientObject();

		return true;
	}

	static double getTotalBalances() {
		vector<clsBankClient> vClients = _LoadDataFromFile("Clients.txt");
		double totalBalances = 0.0;
		for (clsBankClient& c : vClients) {
			totalBalances += c.AccountBalance;
		}
		return totalBalances;
	}

	void Deposit(double amount) {
		AccountBalance += amount;
		Save();
	}
	bool Withdraw(double amount) {
		if(amount>AccountBalance)
		{
			return false;
		}
		else
		{
			AccountBalance -= amount;
			Save();
			return true;
		}
	
	}

	bool Transfer(double amount, clsBankClient& DestinationClient,string UserName) {
		if (amount > AccountBalance)
		{
			return false;
		}
		if (_AccountNumber == DestinationClient.getAccountNumber()) 
		{
			return false;
		}
		else
		{
			Withdraw(amount);
			DestinationClient.Deposit(amount);
			_RegisterTransferLog(amount, DestinationClient,UserName );
			return true;
		}
	}
		
};
