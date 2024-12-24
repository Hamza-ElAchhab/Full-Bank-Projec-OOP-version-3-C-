#pragma once
#include <iostream>
#include <string>
using namespace std;


#include "headerOfScreens.h"
#include "Input_Validation.h"
#include "CenterUsers.h"






class cls_DeleteUser : protected cls_Header
{


public:

	static void DeleteUser()
	{
		cls_Header::Header_Print("DELETE USER SCREEN : ");

		string UserName = clsInputValidation::_Read_String("\t\t\t\t\tEnter a User Name : ");

		while (!cls_CenterUsers::isUserExists(UserName))
		{
			cout << "\n\t\t\t\t\tUser Name Does't Exists.\n";
			UserName = clsInputValidation::_Read_String("\t\t\t\t\tEnter a Exists User Name : ");
		}

		cls_CenterUsers obj = cls_CenterUsers::Find(UserName);

		cout << endl << "\nUser Info : ";
		obj.Print();

		char ans = 'n';
		cout << endl << "\n\t\t\t\t\t* Are You Sure : ";
		cin >> ans;

		if (toupper(ans) == 'Y')
		{
			obj.Delete();
			obj.Print();
			cout << endl << "\t\t\t\t\t* User Deleted Successfully.\n";
		}
		else
		{
			cout << "\n\t\t\t\t\t* Canceled.\n";
		}
	}

};