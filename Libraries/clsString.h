#pragma once
#include<iostream>
#include<vector>
using namespace std;
class clsString
{
	string _Value;
public:

	clsString() {

	}
	clsString(string value) {
		_Value = value;
	}

	void setValue(string value)
	{
		_Value = value;
	}
	string getValue()
	{
		return _Value;
	}

	__declspec(property(get = getValue, put = setValue)) string Value;

	static short length(string s1) {
		s1.length();
	}
	short length() {
		return length(_Value);
	}

	static short countWords(string s1) {
		int counter = 0;
		string delim = " ";
		short pos = 0;
		string sWord;

		while ((pos = s1.find(delim)) != std::string::npos)
		{
			sWord = s1.substr(0, pos);

			if (sWord != "")
			{
				counter++;
			}

			s1.erase(0, pos + delim.length());
		}
		if (s1 != "")
			counter++;
		return counter;
	}
	short countWords() {
		return countWords(_Value);
	}

	static void printFirstLetterOfEachWord(string s1) {
		bool isFirstLetter = true;
		cout << "\nFirst letters of this string: " << endl;
		for (short i = 0; i < s1.length(); i++)
		{
			if (s1[i] != ' ' && isFirstLetter)
			{
				cout << s1[i] << endl;
			}
			isFirstLetter = (s1[i] == ' ' ? true : false);
		}

	}
	void printFirstLetterOfEachWord()
	{
		return printFirstLetterOfEachWord(_Value);
	}

	static string upperFirstLetterOfEachWord(string s1) {
		bool isFirstLetter = true;
		for (short i = 0; i < s1.length(); i++)
		{
			if (s1[i] != ' ' && isFirstLetter)
			{
				s1[i] = toupper(s1[i]);
			}
			isFirstLetter = (s1[i] == ' ' ? true : false);
		}
		return s1;
	}
	void upperFirstLetterOfEachWord()
	{
		_Value = upperFirstLetterOfEachWord(_Value);
	}

	static string lowerFirstLetterOfEachWord(string s) {
		bool isFirstLetter = true;
		for (short i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ' && isFirstLetter) {
				s[i] = tolower(s[i]);
			}
			isFirstLetter = (s[i] == ' ' ? true : false);
		}
		return s;
	}
	void lowerFirstLetterOfEachWord() {
		_Value = lowerFirstLetterOfEachWord(_Value);
	}

	static string upperAllLetters(string s1) {
		for (short i = 0; i < s1.length(); i++)
		{
			s1[i] = toupper(s1[i]);
		}
		return s1;
	}
	void upperAllLetters() {
		_Value = upperAllLetters(_Value);
	}

	static string lowerAllLetters(string s1) {
		for (short i = 0; i < s1.length(); i++)
		{
			s1[i] = tolower(s1[i]);
		}
		return s1;
	}
	void lowerAllLetters() {
		_Value = lowerAllLetters(_Value);
	}

	static char invertLetterCase(char ch) {
		return (isupper(ch) ? tolower(ch) : toupper(ch));
	}

	static string invertAllStringLettersCase(string s1) {
		for (short i = 0; i < s1.length(); i++)
		{
			s1[i] = invertLetterCase(s1[i]);
		}
		return s1;
	}
	void invertAllStringLettersCase() {
		_Value = invertAllStringLettersCase(_Value);
	}

	enum enWhatToCount { CapitalLetters = 1, SmallLetters = 2, AllLetters = 3 };
	static short countLetters(string s1, enWhatToCount letter = enWhatToCount::AllLetters) {
		short counter = 0;
		for (short i = 0; i < s1.length(); i++)
		{
			if (letter == enWhatToCount::AllLetters)
			{
				return s1.length();
			}
			if (letter == enWhatToCount::CapitalLetters && isupper(s1[i]))
			{
				counter++;
			}
			if (letter == enWhatToCount::SmallLetters && islower(s1[i]))
			{
				counter++;
			}
		}
		return counter;
	}

	static short countSmallLetters(string s1) {
		int counter = 0;
		for (short i = 0; i < s1.length(); i++) {
			if (islower(s1[i]))
				counter++;
		}
		counter++;
	}
	short countSmallLetters() {
		return countSmallLetters(_Value);
	}

	static short countCapitalLetters(string s1) {
		int counter = 0;
		for (short i = 0; i < s1.length(); i++) {
			if (isupper(s1[i]))
				counter++;
		}
		counter++;
	}
	short countCapitalLetters() {
		return countCapitalLetters(_Value);
	}

	static short countSpecificLetters(string s1, char letter, bool matchCase = true) {
		short counter = 0;
		for (short i = 0; i < s1.length(); i++)
		{
			if (matchCase)
			{
				if ((s1[i]) == letter)
					counter++;
			}
			else
			{
				if (toupper(s1[i]) == toupper(letter))
					counter++;
			}
		}
		return counter;
	}
	short countSpecificLetters(char letter, bool matchCase = true) {
		return countSpecificLetters(_Value, letter, matchCase);
	}

	static bool isVowel(char ch1) {
		ch1 = tolower(ch1);
		return((ch1 == 'a') || (ch1 == 'o') || (ch1 == 'i') || (ch1 == 'u') || (ch1 == 'e'));
	}

	static void printVowelLetters(string s1) {
		cout << "\nVowel letters in this string are: ";
		for (short i = 0; i < s1.length(); i++)
		{
			if (isVowel(s1[i]))
				cout << s1[i] << "    ";
		}
		/*cout << endl;*/
	}
	void printVowelLetters() {
		return printVowelLetters(_Value);
	}

	static short countVowels(string s1) {
		int counter = 0;
		for (short i = 0; i < s1.length(); i++)
		{
			if (isVowel(s1[i]))
				counter++;
		}
		return counter;
	}
	short countVowels() {
		return countVowels(_Value);
	}

	static void printEachWordInString(string s1) {
		string delim = " ";//delimiter
		cout << "\nYour string words are: " << endl;
		short pos = 0;
		string sWord;

		while ((pos = s1.find(delim)) != std::string::npos)
		{
			sWord = s1.substr(0, pos);//store the word

			if (sWord != "")
			{
				cout << sWord << endl;
			}

			s1.erase(0, pos + delim.length());
		}
		if (s1 != "")
		{
			cout << s1 << endl;
		}
	}
	void printEachWordInString() {
		return printEachWordInString(_Value);
	}

	static vector<string> split(string s1, string delimiter) {
		vector<string> vString;
		short pos = 0;
		string sWord;
		while ((pos = s1.find(delimiter)) != std::string::npos) {
			sWord = s1.substr(0, pos);
			/*if (sWord != " ")
			{*/
			vString.push_back(sWord);
			//}
			s1.erase(0, pos + delimiter.length());
		}
		/*if (s1 != "")
		{*/
		vString.push_back(s1);
		//}

		return vString;
	}
	vector<string> split(string delimiter) {
		return split(_Value, delimiter);
	}

	static string trimLeft(string s1) {
		for (short i = 0; i < s1.length(); i++) {
			if (s1[i] != ' ')
				return s1.substr(i, s1.length() - i);
		}
		return "";
	}
	void trimLeft() {
		_Value = trimLeft(_Value);
	}

	static string trimRight(string s1) {
		for (short i = s1.length() - 1; i >= 0; i--) {
			if (s1[i] != ' ')
			{
				return s1.substr(0, i + 1);
			}
		}
		return "";
	}
	void trimRight() {
		_Value = trimRight(_Value);
	}

	static string trim(string s1) {
		return trimLeft(trimRight(s1));
	}
	void trim() {
		_Value = trim(_Value);
	}

	static string joinString(vector<string> v, string delimiter = " ") {
		string s1 = "";

		for (string& s : v)
		{
			s1 = s1 + s + delimiter;
		}

		return s1.substr(0, s1.length() - delimiter.length());
	}
	static string joinString(string arrString[], short length, string delimiter) {
		string s1 = "";

		for (short i = 0; i < length; i++)
		{
			s1 = s1 + arrString[i] + delimiter;
		}

		return s1.erase(s1.length() - delimiter.length());
		//or: return s1.substr(0, s1.length() - delimiter.length());
	}

	static string reverseWordsInString(string s1) {
		vector<string> vString = split(s1, " ");
		string s2 = "";

		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{

			iter--;

			s2 = s2 + *iter + " ";
		}

		s2 = s2.substr(0, s2.length() - 1);
		return s2;
	}
	string reverseWordsInString() {
		return reverseWordsInString(_Value);
	}

	static string ReplaceWordInString(string s1, string stringToReplace, string replaceTo, bool matchCase = true) {
		vector<string> vString = split(s1, " ");
		for (string& s : vString)
		{
			if (matchCase)
			{
				if (s == stringToReplace)
				{
					s = replaceTo;
				}
			}
			else
			{
				if (lowerAllLetters(s) == lowerAllLetters(stringToReplace))
				{
					s = replaceTo;
				}
			}
		}
		return joinString(vString, " ");
	}
	void ReplaceWordInString(string stringToReplace, string replaceTo) {
		_Value = ReplaceWordInString(_Value, stringToReplace, replaceTo);
	}

	static string removePunctuationsFromString(string s1) {
		string s2 = "";
		for (short i = 0; i < s1.length(); i++)
		{
			if (!ispunct(s1[i]))
			{
				s2 += s1[i];
			}
		}
		return s2;
	}
	void removePunctuationsFromString() {
		_Value = removePunctuationsFromString(_Value);
	}
	
};

