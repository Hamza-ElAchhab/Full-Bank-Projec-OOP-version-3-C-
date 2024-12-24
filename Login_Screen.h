#pragma once
#include <iostream>
using namespace std;



#include "GlobalUser.h"
#include "headerOfScreens.h"
#include "MainMenu_Screen.h"
#include "CenterUsers.h"
#include "Input_Validation.h"





class cls_Login : protected cls_Header
{


public :
	
	static bool Login()
	{
		bool isLoginFailed = false;
		string UserName;
		string PassWord;
		int counter = 3;

		do
		{
			cls_Header::Header_Print(" LOGIN SCREEN : ");

			UserName = clsInputValidation::_Read_String("\n\t\t\t\t\tEnter User Name : ");
			PassWord = clsInputValidation::_Read_String("\t\t\t\t\tEnter Pass Word : ");

			CurrentUserr = cls_CenterUsers::Find(UserName, PassWord);


			isLoginFailed = (CurrentUserr.Get_Mode() == (cls_CenterUsers::casting(0)));
			if (isLoginFailed)
			{
				counter--;
				if (counter == 0)
				{
					cout << "\n\tSystem Locked\n";
					return false;
				}

				cout << endl << "\n\t\t\t\t\tError, Invalid UserName or PassWord\n";
				cout << "\t\t\t\t\tYou Have " << counter << " More Logins\n";
				cout << "\n\n\t\t\t\t\tPress To Continue ...";
				system("pause>0");
			}

		} while (isLoginFailed);


		cls_MainMenu::Show_MainMenu();
		return true;
	}

};