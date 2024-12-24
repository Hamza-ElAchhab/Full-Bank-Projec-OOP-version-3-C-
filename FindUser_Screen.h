#pragma once
#include <iostream>
using namespace std;




#include "headerOfScreens.h"
#include "CenterUsers.h"
#include "Input_Validation.h"





class cls_FindUser : protected cls_Header
{

private :

	static void PrintUserCard(cls_CenterUsers obj)
	{
		cout << "\n\t\t\t\t--------------------------------------\n";
		cout << "\t\t\t\t\tFirst Name : " << obj.FirstName << endl;
		cout << "\t\t\t\t\tLast  Name : " << obj.LastName << endl;
		cout << "\t\t\t\t\tFull  Name : " << obj.FirstName + " " + obj.LastName << endl;
		cout << "\t\t\t\t\tYour Email : " << obj.Email << endl;
		cout << "\t\t\t\t\tYour Phone : " << obj.Phone << endl;
		cout << "\t\t\t\t\tUser Name  : " << obj.Get_UserName() << endl;
		cout << "\t\t\t\t\tPass Word  : " << obj.PassWord << endl;
		cout << "\t\t\t\t\tPermissions: " << obj.Permissions << endl;
		cout << "\t\t\t\t--------------------------------------\n";
	}


public :

	static void FindUser()
	{
		cls_Header::Header_Print("FIND USER SCREEN : ");

		string UserName = clsInputValidation::_Read_String("\n\t\t\t\t\tEnter a User Name : ");

		while (!cls_CenterUsers::isUserExists(UserName))
		{
			cout << endl << "\t\t\t\t\tUser Doen't Exist\n";
			UserName = clsInputValidation::_Read_String("\t\t\t\t\tEnter a Valid User Name : ");
		}

		cls_CenterUsers obj = cls_CenterUsers::Find(UserName);

		if (obj.Get_Mode() == cls_CenterUsers::casting(1))
		{
			cout << "\n\n\t\t\t\tUser Info : ";
			PrintUserCard(obj);
		}
		else
		{
			cout << endl << "Error.\n";
		}
	}
};