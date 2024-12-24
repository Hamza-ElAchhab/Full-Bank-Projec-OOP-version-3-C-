#pragma once
#include <iostream>
#include <iomanip>
using namespace std;


#include "Input_Validation.h"



class cls_Header
{

public :

	static void Header_Print(string Title)
	{
		system("cls");
		cout << setw(40) << "" << "_____________________________________\n";
		cout << endl << setw(40) << "" << "\t  " << Title << endl;
		cout << endl << "\t\t\t\t\t     Date : " << clsInputValidation::GetSystemDateTimeString() << endl;
		cout << setw(40) << "" << "_____________________________________\n\n";
		cout << endl << endl;
	}


};