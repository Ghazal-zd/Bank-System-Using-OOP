
//clsDate
#pragma once
#pragma warning(disable:4996);
#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include"clsString.h"
using namespace std;
class clsDate
{
	short day;
	short month;
	int year;

public:
	clsDate()
	{
		clsDate date = getSystemDate();
		day = date.day;
		month = date.month;
		year = date.year;
		//OR:
		//time_t t = time(0);  //get time now
		//tm* now = localtime(&t);
		//year = now->tm_year + 1900;
		//month = now->tm_mon + 1;
		//day = now->tm_mday;
	}

	clsDate(string date) {
		vector<string> vDate;
		vDate = clsString::split(date, "/");

		day = stoi(vDate[0]);
		month = stoi(vDate[1]);
		year = stoi(vDate[2]);

	}

	clsDate(short day, short month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}

	clsDate(int numberOfDays, int Year) {
		clsDate date = dateFromDayOrderInYear(numberOfDays, Year);
		day = date.day;
		month = date.month;
		year = date.year;
	}

	void print() {
		cout << DateToString() << "\n";
	}

	static clsDate getSystemDate() {
		time_t t = time(0); 
		tm* now = localtime(&t);
		short day, month, year;
		year = now->tm_year + 1900;
		month = now->tm_mon + 1;
		day = now->tm_mday;

		return clsDate(day, month, year);
	}
	static string getSystemDateTimeString() {
		time_t t = time(0);  
		tm* now = localtime(&t);

		short day, month, year, hour, minute, second;

		year= now->tm_year + 1900 ;
		month= now->tm_mon + 1;
		day= now->tm_mday     ;
		hour=  now->tm_hour    ;
		minute= now->tm_min   ;
		second= now->tm_sec   ;

		return to_string(day) + "/" + to_string(month) + "/" + to_string(year) + " - " +
			to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
	}
	static string DateToString(clsDate date, string separator = "/") {
		return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
	}
	string DateToString() {
		return DateToString(*this);
	}

	static bool isLeapYear(short year)
	{

		return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	}
	bool isLeapYear() {
		return isLeapYear(year);
	}

	static short DaysInYear(int year)
	{
		return isLeapYear(year) ? 366 : 365;
	}
	short DaysInYear() {
		return DaysInYear(year);
	}

	static short hoursInYear(int year) {
		return DaysInYear(year) * 24;
	}
	short hoursInYear() {
		return hoursInYear(year);
	}
	static int minutesInYear(int year) {
		return hoursInYear(year) * 60;
	}
	int minutesInYear() {
		return minutesInYear(year);
	}

	static int secondsInYear(int year) {
		return minutesInYear(year) * 60;
	}

	int secondsInYear() {
		return secondsInYear(year);
	}
	static short NumberOfDaysInMonth(short month, short year)
	{
		if (month < 1 || month>12)
		{
			return 0;
		}

		short numberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (month == 2) ? (isLeapYear(year) ? 29 : 28) : numberOfDays[month - 1];
	}
	short NumberOfDaysInMonth() {
		return NumberOfDaysInMonth(month, year);
	}

	static string monthShortName(short numOfMonth) {
		string arrMonthName[13] = { "","Jan","Feb","Mar","Apr","May","Jun","July","Aug","Sep","Oct","Nov","Dec" };
		return arrMonthName[numOfMonth];
	}
	string monthShortName() {
		return monthShortName(this->month);
	}

	static string dayShortName(short dayNumber) {
		string arrDayName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayName[dayNumber];
	}
	string dayShortName() {
		return dayShortName(dayOfWeekOrder(day, month, year));
	}

	static short dayOfWeekOrder(short day, short month, short year)
	{
		short a, y, m;
		a = (14 - month) / 12;
		y = year - a;
		m = month + (12 * a) - 2;
		return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;
	}
	short dayOfWeekOrder() {
		return dayOfWeekOrder(day, month, year);
	}

	static void printMonthCalendar(short month, short year)
	{
		short current = dayOfWeekOrder(1, month, year);
		short numberOfDays = NumberOfDaysInMonth(month, year);
		printf("\n____________________%s_________________\n\n", monthShortName(month).c_str());
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		short i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (short j = 1; j <= numberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		cout << "\n________________________________________\n";

	}
	void printMonthCalendar() {
		return printMonthCalendar(month, year);
	}

	static void printYearCalendar(short year) {
		printf("\n\n__________________________________________\n\n");
		printf("              Calendar_%d                  ", year);
		printf("\n__________________________________________\n\n");
		for (short i = 1; i <= 12; i++)
		{
			printMonthCalendar(i, year);
		}
	}
	void printYearCalendar() {
		return printYearCalendar(this->year);
	}

	static short dayFromtheBeginning(clsDate date) {
		short totalDays = 0;

		for (short i = 1; i <= date.month - 1; i++)
		{
			totalDays += NumberOfDaysInMonth(i, date.year);

		}

		totalDays += date.day;

		return totalDays;

	}
	short dayFromtheBeginning() {
		return dayFromtheBeginning(*this);
	}

	static clsDate dateFromDayOrderInYear(short dateOrderInYear, short year)
	{
		clsDate date;
		short remainingDays = dateOrderInYear;
		short monthDays = 0;
		date.year = year;
		date.month = 1;
		while (true)
		{
			monthDays = NumberOfDaysInMonth(date.month, year);
			if (remainingDays > monthDays)
			{
				remainingDays -= monthDays;
				date.month++;
			}
			else
			{
				date.day = remainingDays;
				break;
			}
		}
		return date;
	}

	static clsDate dateAddDays(short numberOfDays, clsDate& Date)
	{
		short remainingDays = numberOfDays + dayFromtheBeginning(Date);
		short monthDays = 0;
		Date.month = 1;

		while (true)
		{
			monthDays = NumberOfDaysInMonth(Date.month, Date.year);

			if (remainingDays > monthDays)
			{
				remainingDays -= monthDays;
				Date.month++;

				if (Date.month > 12)
				{
					Date.month = 1;
					Date.year++;
				}
			}

			else
			{
				Date.day = remainingDays;
				break;
			}
		}
		return Date;
	}
	clsDate dateAddDays(short numberOfDays) {
		return dateAddDays(numberOfDays, *this);
	}

	static bool isDate1BeforeDate2(clsDate date1, clsDate date2) {
		return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
	}
	bool isDate1BeforeDate2(clsDate date2) {
		return isDate1BeforeDate2(*this, date2);
	}

	static bool isDate1EqualsDate2(clsDate date1, clsDate date2) {
		return (date1.year == date2.year) ? (date1.month == date2.month ? (date1.day == date2.day) : false) : false;
	}
	bool isDate1EqualsDate2(clsDate date2) {
		return isDate1EqualsDate2(*this, date2);
	}

	static bool isLastDayInMonth(clsDate Date)
	{
		return (Date.day == NumberOfDaysInMonth(Date.month, Date.year));
	}
	bool isLastDayInMonth() {
		return isLastDayInMonth(*this);
	}

	static bool isLastMonthInYear(short month) {
		return (month == 12);
	}
	bool isLastMonthInYear() {
		return isLastMonthInYear(month);
	}

	static void swapDates(clsDate& date1, clsDate& date2) {
		clsDate tempDate;

		tempDate.day = date1.day;
		tempDate.month = date1.month;
		tempDate.year = date1.year;

		date1.day = date2.day;
		date1.month = date2.month;
		date1.year = date2.year;

		date2.day = tempDate.day;
		date2.month = tempDate.month;
		date2.year = tempDate.year;
	}

	static short diffInDays(clsDate Date1, clsDate Date2, bool includeDay = false) {
		short Day = 0;

		short swapFlagValue = 1;

		if (!isDate1BeforeDate2(Date1, Date2))
		{
			swapDates(Date1, Date2);
			swapFlagValue = -1;
		}

		while (isDate1BeforeDate2(Date1, Date2))
		{
			Day++;
			Date1 = increaseDateByOneDay(Date1);
		}
		return includeDay ? ++Day * swapFlagValue : Day * swapFlagValue;
	}
	short diffInDays(clsDate Date2, bool includeDay = false) {
		return diffInDays(*this, Date2, includeDay);
	}

	static bool isDate1AfterDate2(clsDate date1, clsDate date2) {
		return(!isDate1BeforeDate2(date1, date2) && !isDate1EqualsDate2(date1, date2));
	}
	bool isDate1AfterDate2(clsDate date2) {
		return isDate1AfterDate2(*this, date2);
	}

	static bool isValidateDate(clsDate date) {
		if (date.day < 1 || date.day>31)
			return false;
		if (date.month < 1 || date.month>31)
			return false;
		if (date.month == 2)
		{
			if (isLeapYear(date.year))
			{
				if (date.day > 29)
					return false;
			}
			else
			{
				if (date.day > 28)
					return false;
			}
		}

		short numOfDaysInMonth = NumberOfDaysInMonth(date.month, date.year);

		if (date.day > numOfDaysInMonth)
			return false;

		return true;
	}
	bool isValidateDate() {
		return isValidateDate(*this);
	}

	static clsDate increaseDateByOneDay(clsDate& date) {
		if (isLastDayInMonth(date))
		{
			if (isLastMonthInYear(date.month))
			{
				date.day = 1;
				date.month = 1;
				date.year++;
			}
			else
			{
				date.day = 1;
				date.month++;
			}
		}
		else
		{
			date.day++;
		}

		return date;
	}
	clsDate increaseDateByOneDay()
	{
		return increaseDateByOneDay(*this);
	}

	static clsDate increaseDateByXDay(clsDate& date, short x) {
		for (short i = 1; i <= x; i++) {
			date = increaseDateByOneDay(date);
		}
		return date;
	}
	clsDate increaseDateByXDay(short x) {
		return increaseDateByXDay(*this, x);
	}

	static clsDate increaseDateByOneWeek(clsDate& date) {
		for (short i = 1; i <= 7; i++) {
			date = increaseDateByOneDay(date);
		}
		return date;
	}
	clsDate increaseDateByOneWeek() {
		return increaseDateByOneWeek(*this);
	}

	static clsDate increaseDateByXWeeks(clsDate& date, short numOfWeeks) {

		//date = dateAddDays(numOfWeeks * 7, date); 
		for (short i = 1; i <= numOfWeeks; i++) {
			date = increaseDateByOneWeek(date);
		}
		return date;
	}
	clsDate increaseDateByXWeeks(short numOfWeeks) {
		return increaseDateByXWeeks(*this, numOfWeeks);
	}

	static clsDate increaseDateByOneMonth(clsDate& date, short numOfMonth = 1) {

		if (date.month == 12) {
			date.month = 1;
			date.year++;
		}
		else
		{
			date.month++;
		}
		//last check day in date should not exceed max day in the current month
		//example if date is 31/1/2022 increasing one month shouldn't be 31/2/2022, it should de 28/2/2022
		short numberOfDaysInCurrentMonth = NumberOfDaysInMonth(date.month, date.year);
		if (date.day > numberOfDaysInCurrentMonth) {
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}
	clsDate increaseDateByOneMonth() {
		return increaseDateByOneMonth(*this);
	}

	static clsDate increaseDateByXMonth(clsDate& date, short numOfMonth) {
		for (short i = 1; i <= numOfMonth; i++)
		{
			date = increaseDateByOneMonth(date);
		}
		return date;
	}
	clsDate increaseDateByXMonth(short numOfMonths) {
		return increaseDateByXMonth(*this, numOfMonths);
	}

	static clsDate increaseDateByOneYear(clsDate& date) {

		/*
		short numOfDays = numberOfDaysInYear(date.year);
		date = dateAddDays(numOfDays, date);
		*/

		date.year++;

		short numberOfDaysInCurrentMonth = NumberOfDaysInMonth(date.month, date.year);
		if (date.day > numberOfDaysInCurrentMonth) {
			date.day = numberOfDaysInCurrentMonth;
		}

		return date;
	}
	clsDate increaseDateByOneYear() {
		return increaseDateByOneYear(*this);
	}

	static clsDate increaseDateByXYear(clsDate& date, short years) {
		for (short i = 1; i <= years; i++) {
			date = increaseDateByOneYear(date);
		}
		return date;
	}
	clsDate increaseDateByXYear(short numOfYears) {
		return increaseDateByXYear(*this, numOfYears);
	}

	static clsDate increaseDateByXYearFaster(clsDate& date, short years) {
		date.year += years;
		return date;
	}
	clsDate increaseDateByXYearFaster(short numOfYears) {
		return increaseDateByXYearFaster(*this, numOfYears);
	}

	static clsDate increaseDateByOneDecade(clsDate& date) {
		date.year += 10;
		return date;
	}
	clsDate increaseDateByOneDecade() {
		return increaseDateByOneDecade(*this);
	}

	static clsDate increaseDateByXDecades(clsDate& date, short Decade) {

		for (short i = 1; i <= Decade * 10; i++)
		{
			date = increaseDateByOneYear(date);
		}
		return date;
	}
	clsDate increaseDateByXDecades(short Decade) {
		return increaseDateByXDecades(*this, Decade);
	}

	static  clsDate increaseDateByXDecadesFaster(clsDate& date, short Decade) {
		date.year += Decade * 10;
		return date;
	}
	clsDate increaseDateByXDecadesFaster(short Decade) {
		return increaseDateByXDecadesFaster(*this, Decade);
	}

	static clsDate increaseDateByCentury(clsDate date) {
		date.year += 100;
		return date;
	}
	clsDate increaseDateByCentury() {
		return increaseDateByCentury(*this);
	}

	static clsDate increaseDateByMillennium(clsDate date) {
		date.year += 1000;
		return date;
	}
	clsDate increaseDateByMillennium() {
		return increaseDateByMillennium(*this);
	}
	static bool isFirstDayInMonth(short day)
	{
		return (day == 1);
	}
	bool isFirstDayInMonth() {
		return isFirstDayInMonth(this->day);
	}

	static bool isFirstMonthInYear(short month) {
		return (month == 1);
	}
	bool isFirstMonthInYear() {
		return isFirstMonthInYear(this->month);
	}

	static clsDate decreaseDateByOneDay(clsDate& date) {

		if (isFirstDayInMonth(date.day))
		{
			if (isFirstMonthInYear(date.month))
			{
				date.month = 12;
				date.day = 31;
				date.year--;
			}
			else
			{
				date.month--;
				date.day = NumberOfDaysInMonth(date.month, date.year);
			}
		}
		else
		{
			date.day--;
		}

		return date;
	}
	clsDate decreaseDateByOneDay() {
		return decreaseDateByOneDay(*this);
	}

	static clsDate decreaseDateByXDay(clsDate& date, short x) {
		for (short i = 1; i <= x; i++) {
			date = decreaseDateByOneDay(date);
		}
		return date;
	}
	clsDate decreaseDateByXDay(short x) {
		return decreaseDateByXDay(*this, x);
	}

	static clsDate decreaseDateByOneWeek(clsDate& date) {
		for (short i = 1; i <= 7; i++) {
			date = decreaseDateByOneDay(date);
		}
		return date;
	}
	clsDate decreaseDateByOneWeek() {
		return decreaseDateByOneWeek(*this);
	}

	static clsDate decreaseDateByXWeeks(clsDate& date, short numOfWeeks) {
		for (short i = 1; i <= numOfWeeks; i++) {
			date = decreaseDateByOneWeek(date);
		}
		return date;
	}
	clsDate decreaseDateByXWeeks(short numOfWeeks) {
		return decreaseDateByXWeeks(*this, numOfWeeks);
	}

	static clsDate decreaseDateByOneMonth(clsDate& date, short numOfMonth = 1) {

		if (date.month == 1) {
			date.month = 12;
			date.year--;
		}
		else
		{
			date.month--;
		}

		//last check day in date should not exceed max day in the current month
		//example if date is 31/3/2022 increasing one month shouldn't be 31/2/2022, it should de 28/2/2022

		short numberOfDaysInCurrentMonth = NumberOfDaysInMonth(date.month, date.year);
		if (date.day > numberOfDaysInCurrentMonth) {
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}
	clsDate decreaseDateByOneMonth(short numOfMonth) {
		decreaseDateByOneMonth(*this);
	}

	static clsDate decreaseDateByXMonth(clsDate& date, short numOfMonth) {
		for (short i = 1; i <= numOfMonth; i++) {
			date = decreaseDateByOneMonth(date);
		}

		return date;
	}
	clsDate decreaseDateByXMonth(short numOfMonth) {
		decreaseDateByXMonth(*this, numOfMonth);
	}

	static clsDate decreaseDateByOneYear(clsDate& date) {

		date.year--;
		return date;
	}
	clsDate decreaseDateByOneYear() {
		return decreaseDateByOneYear(*this);
	}

	static clsDate decreaseDateByXYear(clsDate& date, short years) {
		for (short i = 1; i <= years; i++) {
			date = decreaseDateByOneYear(date);
		}
		return date;
	}
	clsDate decreaseDateByXYear(short numOfYears) {
		return decreaseDateByXYear(*this, numOfYears);
	}

	static clsDate decreaseDateByXYearFaster(clsDate& date, short years) {
		date.year -= years;
		return date;
	}
	clsDate decreaseDateByXYearFaster(short numOfYears) {
		return decreaseDateByXYearFaster(*this, numOfYears);
	}

	static clsDate decreaseDateByOneDecade(clsDate& date) {
		date.year -= 10;
		return date;
	}
	clsDate decreaseDateByOneDecade() {
		decreaseDateByOneDecade(*this);
	}

	static clsDate decreaseDateByXDecades(clsDate& date, short Decade) {

		for (short i = 1; i <= Decade * 10; i++)
		{
			date = decreaseDateByOneYear(date);
		}
		return date;
	}
	clsDate decreaseDateByXDecades(short Decade) {
		return decreaseDateByXDecades(*this, Decade);
	}

	static clsDate decreaseDateByXDecadesFaster(clsDate& date, short Decade) {
		date.year -= Decade * 10;
		return date;
	}
	clsDate decreaseDateByXDecadesFaster(short Decade) {
		return decreaseDateByXDecadesFaster(*this, Decade);
	}

	static clsDate decreaseDateByCentury(clsDate& date) {
		date.year -= 100;
		return date;
	}
	clsDate decreaseDateByCentury() {
		return decreaseDateByCentury(*this);
	}

	static clsDate decreaseDateByMillennium(clsDate& date) {
		date.year -= 1000;
		return date;
	}
	clsDate decreaseDateByMillennium() {
		return decreaseDateByMillennium(*this);
	}

	static bool isEndOfWeek(clsDate date) {
		return (date.dayShortName() == "Sat");
	}
	bool isEndOfWeek() {
		return isEndOfWeek(*this);
	}

	static bool isWeekEnd(clsDate date) {
		return (date.dayShortName() == "Sat" || date.dayShortName() == "Fri");
	}
	bool isWeekEnd() {
		return isWeekEnd(*this);
	}

	static bool isBusinessDay(clsDate date) {
		return (!isWeekEnd(date));
	}
	bool isBusinessDay()
	{
		return isBusinessDay(*this);
	}

	static short daysUntilEndOfWeek(clsDate date) {
		short count = 0;
		while (date.dayShortName() != "Sat")
		{
			count++;
			date = increaseDateByOneDay(date);
			date.dayShortName() = dayShortName(dayOfWeekOrder(date.day, date.month, date.year));
		}
		return count;
	}
	short daysUntilEndOfWeek() {
		return daysUntilEndOfWeek(*this);
	}

	static short daysUntilEndOfMonth(clsDate date) {
		short count = 1;
		short numOfDaysInMonth = NumberOfDaysInMonth(date.month, date.year);
		while (date.day != numOfDaysInMonth)
		{
			count++;
			date = increaseDateByOneDay(date);
		}
		return count;
	}
	short daysUntilEndOfMonth() {
		return daysUntilEndOfMonth(*this);
	}

	static short daysUntilEndOfYear(clsDate date) {
		short count = 1;
		short numOfDaysInYear = DaysInYear(date.year);
		while (dayFromtheBeginning(date) != numOfDaysInYear)
		{
			count++;
			date = increaseDateByOneDay(date);
		}
		return count;
	}
	short daysUntilEndOfYear() {
		return daysUntilEndOfYear(*this);
	}

	static int calculateMyAgeInDays(clsDate Date) {
		return diffInDays(Date, clsDate::getSystemDate());
	}
};