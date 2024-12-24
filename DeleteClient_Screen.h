#pragma once


#include "headerOfScreens.h"
#include "Input_Validation.h"
#include "CenterClients.h"




class cls_DeleteClient : protected cls_Header
{

private :

	static void _Reading_Info_Of_Client(cls_CenterClients& obj)
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

	static void DeleteClient()
	{
		if (!CurrentUserr.CheckPermission(cls_CenterUsers::en_Permissions::e_DeleteClient))
		{
			cls_CenterUsers::AccessDeniedMessage();
			return;
		}


		cls_Header::Header_Print("DELETE CLIENT SCREEN : ");

		string AcountNumber = clsInputValidation::_Read_String("\t\t\t\t\tEnter an Acount Number : ");

		while (!cls_CenterClients::isClientExists(AcountNumber))
		{
			AcountNumber = clsInputValidation::_Read_String("\n\t\t\t\t\tAcount Number Not Found\n\t\t\t\t\tEnter an Exists Acount Number : ");
		}

		cls_CenterClients client_obj = cls_CenterClients::Find(AcountNumber);
		cout << "\n\nInforamtion Of Client : ";
		client_obj.Print();

		char ans = 'n';
		cout << "\n\t\t\t\t\t* Are You Sure [Y/N] : ";
		cin >> ans;

		if (toupper(ans) == 'Y')
		{
			client_obj.Delete();
			client_obj.Print();
			cout << endl << "\t\t\t\t\t* Client Deleted Successfully.\n";
		}
		else
		{
			cout << endl << "Canceled\n";
		}
	}


};