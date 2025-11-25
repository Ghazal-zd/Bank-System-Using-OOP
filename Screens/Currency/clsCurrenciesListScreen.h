#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"
using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{
private:
	static void printCurrencyRecordLine(clsCurrency currency)
	{
	
		cout << "\t| " << left << setw(30) << currency.Country();
		cout << "| " << left << setw(10) << currency. CurrencyCode();
		cout << "| " << left << setw(40) << currency. CurrencyName();
		cout << "| " << left << setw(20) << currency. Rate();
	}
public:

	static void ShowCurrenciesListScreen() {
		system("cls");
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\tCurrencies List Screen";
		string SubTitle = "\t\t" + to_string(vCurrencies.size()) + "Currency. ";
		_DrawScreenHeader(Title, SubTitle);


  		cout << "\n\t__________________________________________________________________";
		cout << "__________________________________________\n";
		cout << "\t| " << left << setw(30) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(40) << "Currency Name";
		cout << "| " << left << setw(20) << "Rate / (1$)";
		cout << "\n\t__________________________________________________________________";
		cout << "__________________________________________\n";

		if (vCurrencies.size() == 0)
		{
			cout << "\n\t\t\t\tNo Currencies available in this system! \n\n";
		}

		for (clsCurrency& c : vCurrencies) {
			printCurrencyRecordLine(c);
			cout << endl;
		}
		cout << "\n\t__________________________________________________________________";
		cout << "__________________________________________\n";

	}
};

