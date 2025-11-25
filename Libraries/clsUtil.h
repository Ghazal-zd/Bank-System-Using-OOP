#pragma once
#include<iostream>
#include<cstdlib>
#include"clsDate.h"
#include"clsString.h"

using namespace std;

class clsUtil
{
public:
    enum enCharType { capitalletters = 1, smalletters = 2, digits = 3, MixChar = 4, specialCharacter = 5 };

    static int randomNumber(int from, int to) {
        int randomNumber = rand() % (to - from + 1) + from;
        return randomNumber;
    }

    static char getRandomCharacter(enCharType charType) {
        if (charType == MixChar)
        {
            charType = enCharType(randomNumber(1, 3));
        }

        switch (charType)
        {
        case enCharType::capitalletters:
            return char(randomNumber(65, 90));
        case enCharType::smalletters:
            return char(randomNumber(97, 122));
        case enCharType::digits:
            return char(randomNumber(48, 57));
        case enCharType::specialCharacter:
            return char(randomNumber(33, 47));
        default:
        {
            return char(randomNumber(65, 90));
        }

        }
    }

    static string generateWord(enCharType charType, short length) {
        string word = "";
        for (short i = 1; i <= length; i++) {
            word += getRandomCharacter(charType);
        }
        return word;
    }

    static string generateKey(enCharType charType) {
        string key = "";
        key = generateWord(charType, 4) + "-";
        key = key + generateWord(charType, 4) + "-";
        key = key + generateWord(charType, 4) + "-";
        key = key + generateWord(charType, 4);
        return key;
    }
    static void generateKeys(short numberOfKeys, enCharType charType) {
        for (int i = 1; i <= numberOfKeys; i++)
            cout << "Key [" << i << "] :" << generateKey(charType) << endl;
    }

    static void swap(int& num1, int& num2)
    {
        int temp;
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    static void swap(double& num1, double& num2)
    {
        double temp;
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    static void swap(string& s1, string& s2)
    {
        string temp;
        temp = s1;
        s1 = s2;
        s2 = temp;
    }
    static void swap(clsDate& date1, clsDate& date2)
    {
        clsDate::swapDates(date1, date2);
    }

    static void ShuffleArray(int array1[100], int length) {
        for (int i = 0; i < length; i++)
            swap(array1[randomNumber(1, length) - 1], array1[randomNumber(1, length) - 1]);
    }
    static void ShuffleArray(string array1[100], int length) {
        for (int i = 0; i < length; i++)
            swap(array1[randomNumber(1, length) - 1], array1[randomNumber(1, length) - 1]);
    }

    static void fillArrayWithRandomNumbers(int array1[100], int length, int from, int to) {
        for (int i = 0; i < length; i++)
        {
            array1[i] = randomNumber(from, to);
        }
    }
    static void fillArrayWithRandomKeys(string array1[100], int length, enCharType charType) {
        for (int i = 0; i < length; i++)
            array1[i] = generateKey(charType);
    }
    static void fillArrayWithRandomWords(string array1[100], int length, enCharType charType, int wordLength) {
        for (int i = 0; i < length; i++)
            array1[i] = generateWord(charType, wordLength);
    }

    static string Tabs(int num) {
        string t = "";
        for (int i = 0; i < num; i++)
        {
            t += "\t";
        }
        return t;
    }

    static string encryptText(string text, int encryptionKey) {
        for (int i = 0; i < text.length(); i++) {
            text[i] = char(text[i] + encryptionKey);
          
        }
        return text;
    }
    static string decryptText(string text, int encryptionKey) {
        for (int i = 0; i < text.length(); i++) {
            text[i] = char(text[i] - encryptionKey);
        }
        return text;
    }
    static string numberToText(int number) {
        if (number == 0)
        {
            return "";
        }
        if (number >= 1 && number <= 19)
        {
            string arr[] = { "","One","Tow","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
                "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
            return arr[number] + " ";
        }
        if (number >= 20 && number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return arr[number / 10] + " " + numberToText(number % 10);
        }
        if (number >= 100 && number <= 199)
        {
            return "One Hundred " + numberToText(number % 100);
        }
        if (number >= 200 && number <= 999)
        {
            return numberToText(number / 100) + "hundreds " + numberToText(number % 100);
        }
        if (number >= 1000 && number <= 1999)
        {
            return "One Thousand " + numberToText(number % 1000);
        }
        if (number >= 2000 && number <= 999999)
        {
            return numberToText(number / 1000) + "Thousands " + numberToText(number % 1000);
        }
        if (number >= 1000000 && number <= 1999999) {
            return "One million " + numberToText(number % 1000000);
        }
        if (number >= 2000000 && number <= 999999999) {
            return numberToText(number / 1000000) + "millions " + numberToText(number % 1000000);
        }
        if (number >= 1000000000 && number < 1999999999) {
            return"One Billion " + numberToText(number % 1000000000);
        }
        else
        {
            return numberToText(number / 1000000000) + "Billions " + numberToText(number % 1000000000);
        }
    }
};