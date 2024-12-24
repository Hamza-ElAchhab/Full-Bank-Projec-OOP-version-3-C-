#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


#include "CenterClients.h"
#include "headerOfScreens.h"
#include "Input_Validation.h"
#include "CenterUsers.h"



class cls_AddNewClinet : protected cls_Header
{

private:

	static void _Reading_Info_Of_Client(cls_CenterClients &obj)
	{
		cout << endl << endl << "\t\t\t\t\tReading Info : \n\t\t\t\t\t--------------------------------\n";
		obj.FirstName = clsInputValidation::_Read_String("\t\t\t\t\tEnter First Name : ");
		obj.LastName = clsInputValidation::_Read_String("\t\t\t\t\tEnter Last Name  : ");
		obj.Email = clsInputValidation::_Read_String("\t\t\t\t\tEnter Your Email : ");
		obj.Phone = clsInputValidation::_Read_String("\t\t\t\t\tEnter Your Phone : ");
		obj.PinCode = clsInputValidation::_Read_String("\t\t\t\t\tEnter Pin Code   : ");
		obj.Balance = clsInputValidation::_Read_Number("\t\t\t\t\tEnter Balance    : ");
		cout << "\t\t\t\t\t--------------------------------\n";
	}


public :

	static void AddNewClient()
	{

		if (!CurrentUserr.CheckPermission(cls_CenterUsers::en_Permissions::e_AddClient))
		{
			cls_CenterUsers::AccessDeniedMessage();
			return;
		}

		cls_Header::Header_Print("ADD NEW CLIENT SCREEN : ");

		string AcountNumber = clsInputValidation::_Read_String("\t\t\t\t\tEnter an Acount Number : ");

		while (cls_CenterClients::isClientExists(AcountNumber))
		{
			AcountNumber = clsInputValidation::_Read_String("\n\t\t\t\t\tAcount Number Already in User\n\t\t\t\t\tEnter an Acount Number : ");
		}

		cls_CenterClients client_obj = cls_CenterClients::Get_AddNew_Obj(AcountNumber);
		_Reading_Info_Of_Client(client_obj);

		cout << "\n\nInforamtion Of Client : ";
		client_obj.Print();

		char ans = 'n';
		cout << "\n\t\t\t\t\t* Are You Sure [Y/N] : ";
		cin >> ans;

		if (toupper(ans) == 'Y')
		{
			if (client_obj.Save() == cls_CenterClients::en_SaveResult::e_SaveSuccessfully)
			{
				cout << endl << "\t\t\t\t\t* Client Added Successfully.\n\n";
			}
			else
			{
				cout << endl << "Error, Already Exists Or Empty Obj\n";
			}
		}
		else
		{
			cout << endl << "Canceled\n";
		}
	}

};