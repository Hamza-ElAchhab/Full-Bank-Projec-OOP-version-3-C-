#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;



#include "headerOfScreens.h"
#include "CenterClients.h"




class cls_ClientsList
{

private:

	static void _Print_One_Record(cls_CenterClients obj)
	{
		cout << "|\t" << setw(10) << obj.Get_AcountNumber() << " |" << setw(20) << obj.FirstName + " " + obj.LastName << "    |" << setw(17) << obj.Phone << "   |" <<
			setw(17) << obj.Email << "   |" << setw(10) << obj.PinCode << "       |" << setw(10) << obj.Balance << "   |\n";
	}



public :

	static void ClientsList()
	{
		if (!CurrentUserr.CheckPermission(cls_CenterUsers::en_Permissions::e_ClientsList))
		{
			cls_CenterUsers::AccessDeniedMessage();
			return;
		}

		cls_Header::Header_Print("CLIENTS LIST SCREEN : ");

		vector<cls_CenterClients> vData = cls_CenterClients::Load_Data();

		if (vData.size() == 0)
		{
			cout << endl << "\tThere is no Client in The System.\n";
			return;
		}

		cout << endl << "\t\t\t\t\t\t    " << vData.size() << " Client(s).\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";
		cout << "|   Acount Number  |        Full Name       |      Phone         |        Email       |     PinCode     |   Balance   |\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";

		for (cls_CenterClients& o : vData)
		{
			_Print_One_Record(o);
		}
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	}


};