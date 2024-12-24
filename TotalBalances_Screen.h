#pragma once
#include <iostream>
#include <string>
using namespace std;



#include "headerOfScreens.h"
#include "CenterClients.h"






class cls_TotalBalances : protected cls_Header
{
private :

	static void _PrintRecord(cls_CenterClients obj)
	{
		cout << "\t|" << setw(20) << obj.Get_AcountNumber() << "\t\t  |" << setw(25) << obj.FirstName + " " + obj.LastName << "          |" << setw(16) << obj.Balance << "           |\n";
	}



public :

	static void TotalBalances()
	{
		cls_Header::Header_Print("TOTAL BALANCES SCREEN : ");

		vector<cls_CenterClients> vData = cls_CenterClients::Load_Data();

		if (vData.size() == 0)
		{
			cout << endl << "\tThere is no Client in The System.\n";
			return;
		}

		cout << "\t\t\t\t\t\t    " << vData.size() << " Client(s).\n\n";
		cout << "\t---------------------------------------------------------------------------------------------------\n";
		cout << "\t|	    Acount Number         |		Full Name	      |		Balance		  |\n";
		cout << "\t---------------------------------------------------------------------------------------------------\n";
		for (cls_CenterClients& o : vData)
		{
			_PrintRecord(o);
		}
		cout << "\t|-------------------------------------------------------------------------------------------------|\n";
		cout << "\t|_________________________________________________________________________________________________|\n";
		cout << "\t|\t\t\t\t\tTOTAL BALANCES : " << cls_CenterClients::TotalBalances() << "\t\t\t\t\t  |" << endl;
		cout << "\t---------------------------------------------------------------------------------------------------\n";
	}

	

};