#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"clsScreen.h"
#include"clsString.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen : protected clsScreen
{
	enum _enCurrencyExchange {
		eCurrenciesList = 1, eFindCurrency = 2, eUpdateCurrency = 3,
		eCurrencyCalculator = 4, eMainMenu = 5
	};
	static short _ReadCurrencyExchangeMenuOption() {
		cout << "\n\t\t\t\t\tChoose What Do You Want To Do? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 5, "\nPlease enter number between 1 and 5: ");
		return choice;
	}

	static void _ShowCurrenciesList()
	{
		//cout << "Currencies List screen will bw here...\n";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "Find Currency screen will be here...\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyScreen()
	{

		//cout << "Update currency screen will be here...\n";
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "Currency Calculator Screen will be here...\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}



	static void _GoBackToCurrencyExchangeScreen() {
		cout << "\n\tPress any key to go back to main menu...";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}

	static void performCurrencyExchangeMenuOption(_enCurrencyExchange currencyExchangeOption) {
		switch (currencyExchangeOption)
		{
		case _enCurrencyExchange::eCurrenciesList:
		{
			system("cls");
			_ShowCurrenciesList();
			_GoBackToCurrencyExchangeScreen();
			break;
		}
		case _enCurrencyExchange::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeScreen();
			break;
		}
		case _enCurrencyExchange::eUpdateCurrency:
		{
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoBackToCurrencyExchangeScreen();
			break;
		}
		case _enCurrencyExchange::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeScreen();
			break;
		}

		case _enCurrencyExchange::eMainMenu:
		{
			break;
		}
		}
	}

public:
	static void ShowCurrencyExchangeScreen() {
		system("cls");
		_DrawScreenHeader("\t Currency Exchange Screen");

		cout << setw(37) << left << "\n\t\t\t\t\t============================================";
		cout << setw(37) << left << "\n\t\t\t\t\t             Transaction menu Screen             ";
		cout << setw(37) << left << "\n\t\t\t\t\t============================================";
		cout << setw(37) << left << "\n\t\t\t\t\t[1] Currencies List.";
		cout << setw(37) << left << "\n\t\t\t\t\t[2] Find Currency.";
		cout << setw(37) << left << "\n\t\t\t\t\t[3] Update Currency.";
		cout << setw(37) << left << "\n\t\t\t\t\t[4] Currency Calculator.";
		cout << setw(37) << left << "\n\t\t\t\t\t[5] Main Menu";
		cout << setw(37) << left << "\n\t\t\t\t\t============================================";
		performCurrencyExchangeMenuOption((_enCurrencyExchange)_ReadCurrencyExchangeMenuOption());
	}

};
