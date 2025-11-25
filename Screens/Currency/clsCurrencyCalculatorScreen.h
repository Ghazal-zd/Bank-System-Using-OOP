#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
class clsCurrencyCalculatorScreen : protected clsScreen
{
	static void _PrintCurrencyCard(clsCurrency currency) 
	{
		cout << "\nCurrency Card: ";
		cout << "\n__________________________";
		cout << "\nCountry      : " << currency.	Country();
		cout << "\nCurrency Code: " << currency.CurrencyCode();
		cout << "\nCurrency Name: " << currency.CurrencyName();
		cout << "\nRate         : " << currency.Rate();
		cout << "\n__________________________\n";
	}
	static float _ReadAmount() {
		float amount = 0;
		cout << "\nEnter amount to exchange: ";
		amount = clsInputValidate::ReadFloatNumber();
		return amount;
	}

	static clsCurrency _GetCurrency(string message)
	{
		cout << message ;
		string currencyCode = clsInputValidate::readString();

		while (!clsCurrency::IsCurrencyExist(currencyCode))
		{
			cout << "\nCurrency is not found, enter another currency code: ";
		    currencyCode = clsInputValidate::readString();
		}

		clsCurrency currency = clsCurrency::FindByCode(currencyCode);
		return currency;
	}
	static void _PrintCalculationResults(clsCurrency currencyFrom, clsCurrency currencyTo, float amount) 
	{
		_PrintCurrencyCard(currencyFrom);

		float amountInUsd = currencyFrom.ConvertToUsd(amount);

		cout << amount << " " << currencyFrom.CurrencyCode() << " = "
			 << amountInUsd << " USD \n";

		if (currencyTo.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting From USD To: ";
		_PrintCurrencyCard(currencyTo);

		float amountInCurrency2 = currencyFrom.ConvertToOtherCurrency(amount, currencyTo);

		cout << amount << " " << currencyFrom.CurrencyCode() << " = "
			<< amountInCurrency2 << " " << currencyTo.CurrencyCode() << "\n";

	}
public:
	static void ShowCurrencyCalculatorScreen() {
		char Continue = 'y';

		while (tolower(Continue) == 'y')
		{
			system("cls");
			_DrawScreenHeader("\tCurrency Calculator Screen");

			clsCurrency currency1 = _GetCurrency("\nPlease enter currency1 code: ");
			clsCurrency currency2 = _GetCurrency("\nPlease enter currency2 code: ");
			float amount = _ReadAmount();

			_PrintCalculationResults(currency1, currency2, amount);

			cout << "Do you want to perform another calculation? y/n? ";
			cin >> Continue;
		}
	}
};

