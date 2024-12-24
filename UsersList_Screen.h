#pragma once
#include <iostream>
#include <vector>
using namespace std;



#include "headerOfScreens.h"
#include "CenterUsers.h"



class cls_UsersList : protected cls_Header
{

private :

	static void _PrintRecord(cls_CenterUsers obj)
	{
		cout << " |\t" << setw(10) << obj.Get_UserName() << "    |" << setw(20) << obj.FirstName + " " + obj.LastName << "    |" << setw(15) << obj.Email << "   |" <<
			setw(15) << obj.Phone << "   |" << setw(10) << obj.PassWord << "       |" << setw(10) << obj.Permissions << "   |\n";
	}


public :

	static void UsersList()
	{
		cls_Header::Header_Print("USERS LIST SCREEN : ");

		vector<cls_CenterUsers> vData = cls_CenterUsers::Load_Users_Data();

		if (vData.size() == 0)
		{
			cout << "\nThere is No User\n";
			return;
		}

		cout << endl << "\t\t\t\t\t\t\t" << vData.size() << " User(s).";

		cout << endl << " _____________________________________________________________________________________________________________________\n";
		cout << " |      User Name     |        Full Name       |      Email       |       Phone      |     PassWord    | Permissions |\n";
		cout << " _____________________________________________________________________________________________________________________\n";

		for (cls_CenterUsers& O : vData)
		{
			_PrintRecord(O);
		}

		cout << " _____________________________________________________________________________________________________________________\n";


	}

};
