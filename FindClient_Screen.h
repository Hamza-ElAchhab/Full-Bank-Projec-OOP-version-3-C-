#pragma once
#include <iostream>
#include <string>
using namespace std;



#include "Input_Validation.h"
#include "headerOfScreens.h"
#include "CenterClients.h"






class cls_FindClient : protected cls_Header
{

private :

	static void PrintClient(cls_CenterClients obj)
	{
		cout << endl << "\t\t\t\t\t-----------------------------";
		cout << "\n\t\t\t\t\tFirst Name  : " << obj.FirstName << endl;
		cout << "\t\t\t\t\tLast Name   : " << obj.LastName << endl;
		cout << "\t\t\t\t\tFull Name   : " << obj.FullName() << endl;
		cout << "\t\t\t\t\tYour Email  : " << obj.Email << endl;
		cout << "\t\t\t\t\tYour Phone  : " << obj.Phone << endl;
		cout << "\t\t\t\t\tAcount Num  : " << obj.Get_AcountNumber() << endl;
		cout << "\t\t\t\t\tPin Code    : " << obj.PinCode << endl;
		cout << "\t\t\t\t\tBalance     : " << obj.Balance << endl;
		cout << "\t\t\t\t\t-----------------------------\n";
	}


public :

	static void FindClient()
	{
		if (!CurrentUserr.CheckPermission(cls_CenterUsers::en_Permissions::e_FindClient))
		{
			cls_CenterUsers::AccessDeniedMessage();
			return;
		}


		cls_Header::Header_Print("FIND CLIENT SCREEN : ");

		string AcountNumber = clsInputValidation::_Read_String("\t\t\t\t\tEnter an Acount Number : ");

		while (!cls_CenterClients::isClientExists(AcountNumber))
		{
			cout << endl << "\t\t\t\t\tAcount Number Not Found.\n";
			AcountNumber = clsInputValidation::_Read_String("\t\t\t\t\tEnter an Exists Acount Number : ");
		}

		cls_CenterClients obj = cls_CenterClients::Find(AcountNumber);

		if (!obj.is_EmptyObject())
		{
			cout << endl << "\n\n\t\t\t\t\t* Client Found\n";
			PrintClient(obj);
		}
		else
		{
			cout << endl << "Empty Object\n";
		}
	}


};
