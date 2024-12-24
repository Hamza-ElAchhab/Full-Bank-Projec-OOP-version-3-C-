#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



#include "headerOfScreens.h"
#include "Input_Validation.h"
#include "CenterClients.h"


class cls_Deposite : protected cls_Header
{

public :

	static void Deposite()
	{
		cls_Header::Header_Print("DEPOSITE SCREEN : ");

		string AcountNumber = clsInputValidation::_Read_String("\t\t\t\t\tEnter an Acount Number : ");

		while (!cls_CenterClients::isClientExists(AcountNumber))
		{
			cout << endl << "\t\t\t\t\t" << AcountNumber << "Does not Exists.\n";
			AcountNumber = clsInputValidation::_Read_String("\t\t\t\t\tEnter an Acount Number : ");
		}

		cls_CenterClients Object = cls_CenterClients::Find(AcountNumber);
		cout << endl << "Details Of Client : ";
		Object.Print();

		float Amount = clsInputValidation::_Read_Number("\n\t\t\t\t\tEnter Amount To Deposite it : ");

		while (Amount < 0)
		{
			Amount = clsInputValidation::_Read_Number("\n\t\t\t\t\tEnter Positive Amount : ");
		}

		char ans = 'n';
		cout << "\n\t\t\t\t\tAre You Sure : ";
		cin >> ans;

		if (toupper(ans) == 'Y')
		{
			Object.Deposite(Amount);
			cout << endl << "Added Successfully.\n";
			cout << endl << "New Balance is : " << Object.Balance << endl;
		}
		else
		{
			cout << endl << "Canecled";
		}
	}

};