//clsInputValidate
#pragma once
#include<iostream>
#include"clsDate.h"
#include"clsString.h"
using namespace std;

class clsInputValidate
{
public:
	static bool IsNumberBetween(short number, short from, short to) {
		return (number >= from && number <= to);
	}
	static bool IsNumberBetween(int number, int from, int to) {
		return (number >= from && number <= to);
	}
	static bool IsNumberBetween(float number, float from, float to) {
		return (number >= from && number <= to);
	}
	static bool IsNumberBetween(double number, double from, double to) {
		return (number >= from && number <= to);
	}

	static bool IsValidateDate(clsDate date) {
		return clsDate::isValidateDate(date);
	}

	static bool IsDateBetween(clsDate date, clsDate from, clsDate to) {
	
		if ((clsDate::isDate1AfterDate2(date, from) || clsDate::isDate1EqualsDate2(date, from))
			&&
			(clsDate::isDate1BeforeDate2(date, to) || clsDate::isDate1EqualsDate2(date, to)))
			return true;

		//Date>=to  && Date<=From
		if ((clsDate::isDate1AfterDate2(date, to) || clsDate::isDate1EqualsDate2(date, to))
			&&
			(clsDate::isDate1BeforeDate2(date, from) || clsDate::isDate1EqualsDate2(date, from)))
			return true;

		return false;
	}
	static string readString() {
		string s1 = "";
		getline(cin >> ws, s1);
		return s1;
	}

	static int ReadIntNumber(string errorMessage = "Invalid number, Enter again:") {
		int number;
		cin >> number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			cout << errorMessage << " \n";
			cin >> number;
		}
		return number;
	}
	static int ReadIntNumberBetween(int from, int to, string message = "Number is not within range, enter another number: ") {
		int  number = ReadIntNumber();

		while (!IsNumberBetween(number, from, to))
		{
			cout << message;
			number = ReadIntNumber();
		}
		return number;
	}

	static int ReadFloatNumber(string errorMessage = "Invalid number, Enter again:") {
		float number;
		cin >> number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			cout << errorMessage << " \n";
			cin >> number;
		}
		return number;
	}
	static int ReadFloatNumberBetween(float from, float to, string message = "Number is not within range, enter another number: ") {
		float  number = ReadFloatNumber();

		while (!IsNumberBetween(number, from, to))
		{
			cout << message;
			number = ReadFloatNumber();
		}
		return number;
	}

	static double ReadDblNumber(string errorMessage = "Invalid number, Enter again:") {
		double number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			cout << errorMessage << " \n";

		}
		return number;
	}

	static double ReadDblNumberBetween(double from, double to, string message = "Number is not within range, enter another number: ") {
		double number = ReadDblNumber();

		while (!IsNumberBetween(number, from, to))
		{
			cout << message;
			number = ReadDblNumber();
		}
		return number;
		return number;
	}
};
