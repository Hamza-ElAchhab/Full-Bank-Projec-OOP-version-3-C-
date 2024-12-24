#pragma once
#include <iostream>
using namespace std;



#include "headerOfScreens.h"
#include "Input_Validation.h"
#include "CenterUsers.h"




class cls_UpdateUser : protected cls_Header
{

private :

	static void _Reading_User_Info(cls_CenterUsers& obj)
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

	static void UpDateUser()
	{
		cls_Header::Header_Print("UPDATE USER SCREEN : ");

		string UserName = clsInputValidation::_Read_String("\n\t\t\t\t\tEnter a User Name : ");

		while (!cls_CenterUsers::isUserExists(UserName))
		{
			cout << endl << "\t\t\t\t\tUser Name Does't Exist : \n";
			UserName = clsInputValidation::_Read_String("\t\t\t\t\tEnter a Exists User Name : ");
		}

		cls_CenterUsers obj = cls_CenterUsers::Find(UserName);
		cout << endl << "\nUSER NAME : ";
		obj.Print();

		_Reading_User_Info(obj);

		char ans = 'n';
		cout << endl << "\t\t\t\t\t* Are You Sure [Y/N] : ";
		cin >> ans;

		if (toupper(ans) == 'Y')
		{
			if (obj.Save() == cls_CenterUsers::en_SaveResult::e_SaveSuccess)
			{
				cout << endl << "New Information : ";
				obj.Print();
				cout << "\n\t\t\t\t\t* User Updated Successfully.\n";
			}
			else
			{
				cout << "\tError, Empty Object.\n";
			}
		}
		else
		{
			cout << endl << "\t\t\t\t\t* Canceled\n";
		}
	}

};