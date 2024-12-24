#pragma once
#include <iostream>
#include <string>
using namespace std;


#include "Input_Validation.h"
#include "headerOfScreens.h"
#include "headerOfScreens.h"
#include "AddNewClient_Screen.h"
#include "ClientsList_Screen.h"
#include "DeleteClient_Screen.h"
#include "UpDateClient_Screen.h"
#include "FindClient_Screen.h"
#include "TransactionsMenu_Screen.h"
#include "ManageUsersMenu_Screen.h"
#include "GlobalUser.h"




class cls_MainMenu : protected cls_Header
{

private:

	enum en_MainMenuOptions
	{
		e_ClientsList = 1, e_AddClient = 2, e_DeleteClient = 3, e_UpdateClient = 4, e_FindClient = 5, e_TransactionsMenu = 6, e_ManageUserMneu = 7, e_Logout = 8
	};

	static en_MainMenuOptions _Read_MainMenu_Option()
	{
		int num = 0;
		cout << setw(32) << "" << "Enter Your Option [1 -> 8] : ";
		num = clsInputValidation::_Read_Number("");

		while (num < 1 || num > 8)
		{
			cout << endl << setw(32) << "" << "Enter Your Option Between [1 -> 8] : ";
			num = clsInputValidation::_Read_Number("");
		}

		return en_MainMenuOptions(num);
	}



	static void _ClientsList()
	{
		cls_ClientsList::ClientsList();
	}

	static void _AddClient()
	{
		cls_AddNewClinet::AddNewClient();
	}

	static void _DeleteClient()
	{
		cls_DeleteClient::DeleteClient();
	}

	static void _UpdateClient()
	{
		cls_UpDateClient::UpdateClient();
	}

	static void _FindClient()
	{
		cls_FindClient::FindClient();
	}

	static void _TransactionsMenu()
	{
		cls_TransactionsMenu::Show_TransactionsMenu();
	}

	static void _ManageUsersMenu()
	{
		cls_ManageUsersMenu::Show_ManageUsersMenu();
	}

	static void _LogOut()
	{
		CurrentUserr = cls_CenterUsers::Find("", "");
	}



	static void _PauseAndBack()
	{
		cout << endl << "\nPress Any Key To Go Back ...";
		system("pause>0");
		Show_MainMenu();
	}

	static void _Working_MainMenu(en_MainMenuOptions option)
	{
		switch (option)
		{

		case en_MainMenuOptions::e_ClientsList:
			_ClientsList();
			_PauseAndBack();
			break;

		case en_MainMenuOptions::e_AddClient:
			_AddClient();
			_PauseAndBack();
			break;

		case en_MainMenuOptions::e_DeleteClient:
			_DeleteClient();
			_PauseAndBack();
			break;

		case en_MainMenuOptions::e_UpdateClient:
			_UpdateClient();
			_PauseAndBack();
			break;

		case en_MainMenuOptions::e_FindClient:
			_FindClient();
			_PauseAndBack();
			break;

		case en_MainMenuOptions::e_TransactionsMenu:
			_TransactionsMenu();
			_PauseAndBack();
			break;

		case en_MainMenuOptions::e_ManageUserMneu:
			_ManageUsersMenu();
			_PauseAndBack();
			break;

		case en_MainMenuOptions::e_Logout:
			_LogOut();
			break;

		default:
			cout << endl << "Wrong Choice ...\n";
			break;

		}
	}


public :
	
	static void Show_MainMenu()
	{
		cls_Header::Header_Print("MAIN MENU SCREEN : ");

		cout << setw(32) << "" << "=====================================================\n";
		cout << setw(32) << "\t\t\t\t\t     Main Menu :\n";
		cout << setw(32) << "" << "=====================================================\n";
		cout << setw(32) << "" << "\t\t [1] : Clients List.\n";
		cout << setw(32) << "" << "\t\t [2] : Add Client.\n";
		cout << setw(32) << "" << "\t\t [3] : Delete Client.\n";
		cout << setw(32) << "" << "\t\t [4] : UpDate Client.\n";
		cout << setw(32) << "" << "\t\t [5] : Find Client.\n";
		cout << setw(32) << "" << "\t\t [6] : Transactions Menu.\n";
		cout << setw(32) << "" << "\t\t [7] : Manage Users Menu.\n";
		cout << setw(32) << "" << "\t\t [8] : LogOut.\n";
		cout << setw(32) << "" << "=====================================================\n\n";

		_Working_MainMenu(_Read_MainMenu_Option());
	}

};