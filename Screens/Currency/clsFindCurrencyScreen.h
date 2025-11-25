#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
using namespace std;
class clsFindCurrencyScreen :protected clsScreen
{
	static void _PrintCurrencyCard(clsCurrency currency) {
		cout << "\n\nCurrency Card: ";
		cout << "\n__________________________";
		cout << "\nCountry      : " << currency.Country();
		cout << "\nCurrency Code: " << currency.CurrencyCode();
		cout << "\nCurrency Name: " << currency.CurrencyName();
		cout << "\nRate         : " << currency.Rate();
		cout << "\n__________________________\n";


	}
	static void _ShowResult(clsCurrency currency) 
	{
		if (!currency.IsEmpty())
	    {
		  	cout << "\nCurrency Found Successfully :-)";
		  	_PrintCurrencyCard(currency);
	    }
		else
		{
		  	cout << "\nCurrency Not Found!";
		}
	}
	
public:
	static void ShowFindCurrencyScreen() {
		system("cls");
		_DrawScreenHeader("\t\tFind currency Screen");

		short choice;
		cout << "\nFind By: [1] Code or [2] Country? ";
		cin >> choice;
		if (choice == 1) {
			cout << "\nEnter Currency Code? ";
			string code = clsInputValidate::readString();
			clsCurrency currency = clsCurrency::FindByCode(code);
			_ShowResult(currency);
		}
		else
		{
			cout << "\nEnter Country Name? ";
			string country = clsInputValidate::readString();
			clsCurrency currency = clsCurrency::FindByCountry(country);
			_ShowResult(currency);
		}
	}
};

/*
static void FindCurrency(short choice) {
		switch (choice)
		{
		case 1:
		{
			cout << "\nEnter Currency Code? ";
			string code = clsInputValidate::readString();
			clsCurrency currency = clsCurrency::FindByCode(code);
			if (!currency.IsEmpty())
			{
				cout << "\nCurrency Found Successfully :-)";
				_PrintCurrencyCard(currency);
			}
			else
			{
				cout << "\nCurrency Not Found!";
			}
			break;
		}
		case 2:
		{
			cout << "\nEnter Country Name? ";
			string country = clsInputValidate::readString();
			clsCurrency currency = clsCurrency::FindByCountry(country);
			if (!currency.IsEmpty())
			{
				cout << "\nCurrency Found Successfully :-)";
				_PrintCurrencyCard(currency);
			}
			else
			{
				cout << "\nCurrency Not Found!";
			}
			break;
		}
		}
	}
	*/