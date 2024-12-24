#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



#include "headerOfScreens.h"
#include "Input_Validation.h"
#include "MainMenu_Screen.h"
#include "Deposite_Screen.h"
#include "WithDarw_Screen.h"
#include "TotalBalances_Screen.h"




class cls_TransactionsMenu : protected cls_Header
{

private :

	enum en_Transactions_Options
	{
		e_TotalBalances = 3, e_Deposite = 1, e_WithDraw = 2, e_GoBackToMainMenu = 4
	};

	static en_Transactions_Options _Read_Option()
	{
		int num = 0;
		cout << endl << setw(35) << "" << "Enter Your Choice [1 -> 4] : ";
		num = clsInputValidation::_Read_Number("");

		while (num < 1 || num > 4)
		{
			cout << endl << setw(35) << "" << "Enter Your Choice Between [1 -> 4] : ";
			num = clsInputValidation::_Read_Number("");
		}

		return (en_Transactions_Options)num;
	}


	
	static void _Deposite()
	{
		cls_Deposite::Deposite();
	}

	static void _WithDraw()
	{
		cls_WithDraw::WithDraw();
	}

	static void	_TotalBalances()
	{
		cls_TotalBalances::TotalBalances();
	}

	static void _Pause_And_Back()
	{
		cout << endl << endl << "Press Any Key To Go Back ...";
		system("pause>0");
		Show_TransactionsMenu();
	}

	static void _Working_TransactionsMenu(en_Transactions_Options option)
	{

		switch (option)
		{

		case en_Transactions_Options::e_Deposite:
			_Deposite();
			_Pause_And_Back();
			break;


		case en_Transactions_Options::e_WithDraw:
			_WithDraw();
			_Pause_And_Back();
			break;


		case en_Transactions_Options::e_TotalBalances:
			_TotalBalances();
			_Pause_And_Back();
			break;


		case en_Transactions_Options::e_GoBackToMainMenu:
			//cls_MainMenu::Show_MainMenu(); Error Working;
			break;


		default:
			cout << endl << "Wrong Choice ...\n";
			break;
		}

	}



public :

	static void Show_TransactionsMenu()
	{
		if (!CurrentUserr.CheckPermission(cls_CenterUsers::en_Permissions::e_TransactionsM))
		{
			cls_CenterUsers::AccessDeniedMessage();
			return;
		}


		cls_Header::Header_Print("TRANSACTIONS MENU : ");

		cout << setw(35) << "" << "==============================================\n";
		cout << setw(35) << "" << "\t\tTransactions Menu : " << endl;
		cout << setw(35) << "" << "==============================================\n";
		cout << setw(35) << "" << "\t\t[1] : Deposite.\n";
		cout << setw(35) << "" << "\t\t[2] : WithDraw.\n";
		cout << setw(35) << "" << "\t\t[3] : Total Balances.\n";
		cout << setw(35) << "" << "\t\t[4] : Go Back To Main Menu.\n";
		cout << setw(35) << "" << "==============================================\n";

		_Working_TransactionsMenu(_Read_Option());
	}

};