#pragma once
#include <iostream>
#include <string>
using namespace std;


#include "headerOfScreens.h"
#include "Input_Validation.h"
#include "CenterUsers.h"



class cls_AddNewUser : protected cls_Header
{

private :

	static void _Reading_User_Info(cls_CenterUsers &obj)
	{
		cout << "\n\n\t\t\t\t\tREADING INFORMATIONS : \n";
		cout << "\t\t\t\t\t-----------------------------------\n";
		obj.FirstName = clsInputValidation::_Read_String("\t\t\t\t\tEnter First Name : ");
		obj.LastName = clsInputValidation::_Read_String("\t\t\t\t\tEnter Last Name  : ");
		obj.Email = clsInputValidation::_Read_String("\t\t\t\t\tEnter Your Email : ");
		obj.Phone = clsInputValidation::_Read_String("\t\t\t\t\tEnter Your Phone : ");
		obj.PassWord = clsInputValidation::_Read_String("\t\t\t\t\tEnter Pass Word  : ");
		obj.Permissions = cls_CenterUsers::Read_User_Permissions();
		cout << "\t\t\t\t\t-----------------------------------\n";
	}


public :

	static void AddUser()
	{
		cls_Header::Header_Print("ADD USER SCREEN : ");

		string UserName = clsInputValidation::_Read_String("\t\t\t\t\tEnter a User Name : ");

		while (cls_CenterUsers::isUserExists(UserName))
		{
			cout << "\n\t\t\t\t\tUser Name Already Exists.\n";
			UserName = clsInputValidation::_Read_String("\t\t\t\t\tEnter a New User Name : ");
		}

		cls_CenterUsers obj = cls_CenterUsers::Get_AddNew_Mode(UserName);
		_Reading_User_Info(obj);

		cout << endl << "User Info : ";
		obj.Print();

		char ans = 'n';
		cout << endl << "\n\t\t\t\t\t* Are You Sure : ";
		cin >> ans;

		if (toupper(ans) == 'Y')
		{
			switch (obj.Save())
			{

			case cls_CenterUsers::en_SaveResult::e_SaveFailed_Empty:
				cout << endl << "Error, Empty Object\n";
				break;


			case cls_CenterUsers::en_SaveResult::e_SaveFailed_Exists:
				cout << "\tError, Already Exists\n";
				break;


			case cls_CenterUsers::en_SaveResult::e_SaveSuccess:
				cout << endl << "\t\t\t\t\t* Added Successfully.\n";
				break;
			}
		}
		else
		{
			cout << endl << "\t\t\t\t\t* Canceled.\n";
		}
	}

	
};