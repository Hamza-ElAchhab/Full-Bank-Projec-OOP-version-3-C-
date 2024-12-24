#pragma once
#include <iostream>
#include <string>
using namespace std;



#include "headerOfScreens.h"
#include "Input_Validation.h"
#include "UsersList_Screen.h"
#include "AddNewUser_Screen.h"
#include "DeleteUser_Screen.h"
#include "UpdateUser_Screen.h"
#include "FindUser_Screen.h"




class cls_ManageUsersMenu : protected cls_Header
{

private:

	enum en_ManageUsersMenu_Options
	{
		e_UsersList = 1, e_AddUser = 2, e_DeleteUser = 3, e_UpDateUser = 4, e_FindUser = 5, e_BackMainMenu = 6
	};

	static en_ManageUsersMenu_Options _Read_ManageUsersMenu_Option()
	{
		int num = 0;
		cout << endl << setw(32) << "";
		num = clsInputValidation::_Read_Number("Enter Your Choice [1 -> 6] : ");

		while (num < 1 || num > 6)
		{
			num = clsInputValidation::_Read_Number("\t\t\t\t\tEnter Your Choice Between [1 -> 6] : ");
		}

		return (en_ManageUsersMenu_Options)num;
	}


	static void _UsersList()
	{
		cls_UsersList::UsersList();
	}

	static void _AddUser()
	{
		cls_AddNewUser::AddUser();
	}

	static void _DeleteUser()
	{
		cls_DeleteUser::DeleteUser();
	}

	static void _UpdateUser()
	{
		cls_UpdateUser::UpDateUser();
	}

	static void _FindUser()
	{
		cls_FindUser::FindUser();
	}


	static void _System_Pause_And_Back()
	{
		cout << endl << endl << "\nPress Any Key To Go Back ...";
		system("pause>0");
		Show_ManageUsersMenu();
	}

	static void _Working_ManageUsersMenu(en_ManageUsersMenu_Options option)
	{
		switch (option)
		{

		case en_ManageUsersMenu_Options::e_AddUser:
			_AddUser();
			_System_Pause_And_Back();
			break;

		case en_ManageUsersMenu_Options::e_DeleteUser:
			_DeleteUser();
			_System_Pause_And_Back();
			break;

		case en_ManageUsersMenu_Options::e_FindUser:
			_FindUser();
			_System_Pause_And_Back();
			break;

		case en_ManageUsersMenu_Options::e_UpDateUser:
			_UpdateUser();
			_System_Pause_And_Back();
			break;

		case en_ManageUsersMenu_Options::e_UsersList:
			_UsersList();
			_System_Pause_And_Back();
			break;

		case en_ManageUsersMenu_Options::e_BackMainMenu:
			break;


		default :
			cout << endl << "Wrong Choice ...\n";
			break;
		}
	}

public :

	static void Show_ManageUsersMenu()
	{
		if (!CurrentUserr.CheckPermission(cls_CenterUsers::en_Permissions::e_ManageUsersM))
		{
			cls_CenterUsers::AccessDeniedMessage();
			return;
		}


		cls_Header::Header_Print("MANAGE USERS MENU : ");

		cout << setw(32) << "" << "=======================================================\n";
		cout << setw(32) << "\t\t\t\t\t\t    Manage Users Menu :\n";
		cout << setw(32) << "" << "=======================================================\n";
		cout << setw(32) << "" << "\t\t  [1] : Users List.\n";
		cout << setw(32) << "" << "\t\t  [2] : Add User.\n";
		cout << setw(32) << "" << "\t\t  [3] : Delete User.\n";
		cout << setw(32) << "" << "\t\t  [4] : UpDate User.\n";
		cout << setw(32) << "" << "\t\t  [5] : Find User.\n";
		cout << setw(32) << "" << "\t\t  [6] : Go Back To Main Menu.\n";
		cout << setw(32) << "" << "=======================================================\n";

		_Working_ManageUsersMenu(_Read_ManageUsersMenu_Option());
	}

};