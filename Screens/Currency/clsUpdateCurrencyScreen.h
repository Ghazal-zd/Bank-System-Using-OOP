#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
class clsUpdateCurrencyScreen :protected clsScreen
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
	static float _ReadRate() {
		float rate = 0;
		cout << "\nEnter new rate: ";
		rate = clsInputValidate::ReadFloatNumber();
		return rate;
	}
public:
	static void ShowUpdateCurrencyScreen() 
	{
		system("cls");
		_DrawScreenHeader("\t\tUpdate currency Screen");

		string currencyCode;
		cout << "\nPlease Enter Currency Code? ";
        currencyCode= clsInputValidate::readString();

		while (!clsCurrency::IsCurrencyExist(currencyCode))
		{
			cout << "Currency is not found, enter another one: ";
			currencyCode = clsInputValidate::readString();

		}
		clsCurrency currency = clsCurrency::FindByCode(currencyCode);
		_PrintCurrencyCard(currency);


		char Answer = 'y';
		cout << "\nAre you sure you want to update this currency rate? y/n? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			
			cout << "\n\nUpdate Currency Rate";
			cout << "\n___________________________";
			
		  	currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Updated Successfully :-)\n";

			_PrintCurrencyCard(currency);
		}
	}
};

