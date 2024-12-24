#pragma once
#include <iostream>
#include <string>
using namespace std;

#pragma warning (disable : 4996)


class clsInputValidation
{
public :

	static string _Read_String(string Message)
	{
		string str = "";
		cout << Message;
		getline(cin >> ws, str);
		return str;
	}

	static float _Read_Number(string Message)
	{
		float Number = 0;
		cout << Message;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			cout << "\t\t\t\t\tInvalid Number, Enter a valid one : ";
			cin >> Number;
		}
		return Number;
	}

	static string GetSystemDateTimeString()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		short Day, Month, Year, Hour, Minute, Second;
		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));
	}


};