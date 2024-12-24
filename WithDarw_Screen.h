#pragma once
#include <iostream>
using namespace std;


#include "Input_Validation.h"
#include "headerOfScreens.h"
#include "CenterClients.h"



class cls_WithDraw : protected cls_Header
{


public :

	static void WithDraw()
	{
		cls_Header::Header_Print("WithDraw Screen : ");

		string AcountNumber = clsInputValidation::_Read_String("\n\t\t\t\t\tEnter an Acount Number : ");

		while (!cls_CenterClients::isClientExists(AcountNumber))
		{
			cout << endl << "\t\t\t\t\tClient Does not Exists.\n";
			AcountNumber = clsInputValidation::_Read_String("\n\t\t\t\t\tEnter an Exists Acount Number : ");
		}

		cls_CenterClients obj = cls_CenterClients::Find(AcountNumber);
		cout << endl << "Client Info : ";
		obj.Print();

		float Amount = 0;
		cout << endl << "\t\t\t\t\tEnter Amount To Draw it : ";
		Amount = clsInputValidation::_Read_Number("");

		while (Amount < 0)
		{
			Amount = clsInputValidation::_Read_Number("\t\t\t\t\tEnter Positive Number : ");
		}

		char ans = 'n';
		cout << endl << "\t\t\t\t\tAre You Sure [Y/N] : ";
		cin >> ans;

		if (toupper(ans) == 'Y')
		{
			if (obj.WithDraw(Amount))
			{
				cout << endl << "\t\t\t\t\tDone Successfully.\n";
				cout << "\t\t\t\t\tNew Balance is : " << obj.Balance << endl;
			}
			else
			{
				cout << "\nError, Balance is Less Than Amount to Draw.\n";
			}
		}
		else
		{
			cout << endl << "Canceled\n";
		}
	}


};