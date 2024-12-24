#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


#include "FilesNames.h"
#include "Person.h"
#include "headerOfScreens.h"
#include "GlobalUser.h"


class cls_CenterUsers : public cls_Person
{

private:

	enum en_UserMode
	{
		e_EmptyMode = 0, e_UpdateMode = 1, e_AddNewMode = 2
	};

	en_UserMode _Mode;
	string		_UserName;
	string		_PassWord;
	int			_Permissions;
	bool		_MarkFoDelete = false;


	static vector<string> _Split(string str, string delm = "#//#")
	{
		vector<string> vStrings;
		string Word = "";
		int Pos = 0;

		while ((Pos = str.find(delm)) != str.npos)
		{
			Word = str.substr(0, Pos);
			vStrings.push_back(Word);

			str = str.erase(0, (Pos + delm.length()));
		}

		if (str != "")
		{
			vStrings.push_back(str);
		}

		return vStrings;
	}

	static cls_CenterUsers _Fill_ObjectOfUser_From_Line(string Line)
	{
		vector<string> vStrings = _Split(Line);
		return cls_CenterUsers(en_UserMode::e_UpdateMode, vStrings[0], vStrings[1], vStrings[2], vStrings[3], vStrings[4], vStrings[5], stoi(vStrings[6]));
	}

	static cls_CenterUsers _Empty_Object()
	{
		return cls_CenterUsers(en_UserMode::e_EmptyMode, "", "", "", "", "", "", 0);
	}

	string _Convert_Obj_Info_To_String(cls_CenterUsers obj, string sep = "#//#")
	{
		string str = "";

		str += obj.FirstName + sep;
		str += obj.LastName + sep;
		str += obj.Email + sep;
		str += obj.Phone + sep;
		str += obj.Get_UserName() + sep;
		str += obj.PassWord + sep;
		str += to_string(obj.Permissions);

		return str;
	}

	void _Save_UsersData_To_File(vector<cls_CenterUsers> vData)
	{
		fstream file;
		file.open(UsersFile, ios::out);

		if (file.is_open())
		{

			for (cls_CenterUsers& obj : vData)
			{
				if (obj.MarkForDelete == false)
				{
					file << _Convert_Obj_Info_To_String(obj) << endl;
				}
			}

			file.close();
		}
	}

	static vector<cls_CenterUsers> _Load_UsersData_From_File()
	{
		vector<cls_CenterUsers> vData;
		fstream file;
		file.open(UsersFile, ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				cls_CenterUsers obj = _Fill_ObjectOfUser_From_Line(line);
				obj.MarkForDelete = false;

				vData.push_back(obj);
			}

			file.close();
		}
		return vData;
	}

	void _Add_RecLine_ToFile(string RecordLine)
	{
		fstream file;
		file.open(UsersFile, ios::out | ios::app);

		if (file.is_open())
		{
			file << RecordLine << endl;
		}

		file.close();
	}


	void _Update()
	{
		vector<cls_CenterUsers> vData = _Load_UsersData_From_File();

		for (cls_CenterUsers& Obj : vData)
		{
			if (this->Get_UserName() == Obj.Get_UserName())
			{
				Obj = *this;
				break;
			}
		}
		_Save_UsersData_To_File(vData);
	}

	void _AddNew()
	{
		_Add_RecLine_ToFile(_Convert_Obj_Info_To_String(*this));
	}

	/*string PerpareRecord()
	{

	}*/


public :

	cls_CenterUsers(en_UserMode mode, string first, string last, string email, string phone, string UserName, string PassWord, int Permissions)
		:cls_Person(first, last, email, phone)
	{

		_Mode = mode;
		_UserName = UserName;
		_PassWord = PassWord;
		_Permissions = Permissions;

	}

	enum en_Permissions
	{
		e_fullAccess = -1, e_ClientsList = 1, e_AddClient = 2, e_DeleteClient = 4, e_UpDateClient = 8, e_FindClient = 16, e_TransactionsM = 32, e_ManageUsersM = 64
	};


	//read only
	en_UserMode Get_Mode()
	{
		return this->_Mode;
	}
	string Get_UserName()
	{
		return this->_UserName;
	}

	string Get_PassWord()
	{
		return this->_PassWord;
	}
	void Set_PassWord(string PassWord)
	{
		this->_PassWord = PassWord;
	}
	__declspec(property(get = Get_PassWord, put = Set_PassWord)) string PassWord;

	int Get_Permissions()
	{
		return this->_Permissions;
	}
	void Set_Permissions(int per)
	{
		this->_Permissions = per;
	}
	__declspec(property(get = Get_Permissions, put = Set_Permissions)) int Permissions;

	bool Get_MarkFoDelete()
	{
		return this->_MarkFoDelete;
	}
	void Set_MarkFoDelete(bool mark)
	{
		this->_MarkFoDelete = mark;
	}
	__declspec(property(get = Get_MarkFoDelete, put = Set_MarkFoDelete)) bool MarkForDelete;


	void Print()
	{
		cout << endl << "\n---------------------------------\n";
		cout << "First Name : " << FirstName << endl;
		cout << "Last  Name : " << LastName << endl;
		cout << "Full  Name : " << FirstName + " " + LastName << endl;
		cout << "Your Email : " << Email << endl;
		cout << "Your Phone : " << Phone << endl;
		cout << "User Name  : " << Get_UserName() << endl;
		cout << "Pass Word  : " << PassWord << endl;
		cout << "Permissions: " << Permissions << endl;
		cout << "---------------------------------\n";
	}


	static en_UserMode casting(int n)
	{
		return (en_UserMode)n;
	}
	
	enum en_SaveResult
	{
		e_SaveSuccess = 1, e_SaveFailed_Empty = 2, e_SaveFailed_Exists = 3
	};

	en_SaveResult Save()
	{
		switch (this->Get_Mode())
		{

		case en_UserMode::e_AddNewMode:
			if (isUserExists(this->Get_UserName()))
			{
				return en_SaveResult::e_SaveFailed_Exists;
			}
			else
			{
				_AddNew();
				return en_SaveResult::e_SaveSuccess;
			}


		case en_UserMode::e_EmptyMode:
			return en_SaveResult::e_SaveFailed_Empty;


		case en_UserMode::e_UpdateMode:
			_Update();
			return en_SaveResult::e_SaveSuccess;
		}
	}



	static vector<cls_CenterUsers> Load_Users_Data()
	{
		return _Load_UsersData_From_File();
	}

	static cls_CenterUsers Find(string UserName)
	{
		fstream file;
		file.open(UsersFile, ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				cls_CenterUsers obj = _Fill_ObjectOfUser_From_Line(line);

				if (obj.Get_UserName() == UserName)
				{
					file.close();
					return obj;
				}
			}
		}
		file.close();
		return _Empty_Object();
	}

	static cls_CenterUsers Find(string UserName, string PassWord)
	{
		fstream file;
		file.open(UsersFile, ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				cls_CenterUsers obj = _Fill_ObjectOfUser_From_Line(line);

				if (obj.Get_UserName() == UserName && obj.PassWord == PassWord)
				{
					file.close();
					return obj;
				}
			}
		}
		file.close();
		return _Empty_Object();
	}

	static cls_CenterUsers Get_AddNew_Mode(string UserName)
	{
		return cls_CenterUsers(en_UserMode::e_AddNewMode, "", "", "", "", UserName, "", 0);
	}

	void Delete() 
	{
		vector<cls_CenterUsers> vData = _Load_UsersData_From_File();

		for (cls_CenterUsers& Obj : vData)
		{
			if (this->Get_UserName() == Obj.Get_UserName())
			{
				Obj.MarkForDelete = true;
				break;
			}
		}
		*this = _Empty_Object();
		_Save_UsersData_To_File(vData);
	}

	static bool isUserExists(string UserName)
	{
		cls_CenterUsers obj = Find(UserName);
		return (obj.Get_Mode() != en_UserMode::e_EmptyMode);
	}


	static int Read_User_Permissions()
	{
		int total = 0;

		char ans = 'n';
		cout << endl << "\t\t\t\t\tDo You Want To Give User Full Access [Y/N] : ";
		cin >> ans;
		if (toupper(ans) == 'Y')
		{
			return -1;
		}

		cout << "\n\t\t\t\t\t__________________________________________";
		cout << "\n\t\t\t\t\tReading Permissions : \n";

		cout << "\t\t\t\t\tGive this User Access To Clients List : ";
		cin >> ans;
		if (toupper(ans) == 'Y')
		{
			total += (int)en_Permissions::e_ClientsList;
		}

		cout << "\t\t\t\t\tGive this User Access To Add Client : ";
		cin >> ans;
		if (toupper(ans) == 'Y')
		{
			total += (int)en_Permissions::e_AddClient;
		}

		cout << "\t\t\t\t\tGive this User Access To Delete Client : ";
		cin >> ans;
		if (toupper(ans) == 'Y')
		{
			total += (int)en_Permissions::e_DeleteClient;
		}

		cout << "\t\t\t\t\tGive this User Access To UpDate Client : ";
		cin >> ans;
		if (toupper(ans) == 'Y')
		{
			total += (int)en_Permissions::e_UpDateClient;
		}

		cout << "\t\t\t\t\tGive this User Access To Find Client : ";
		cin >> ans;
		if (toupper(ans) == 'Y')
		{
			total += (int)en_Permissions::e_FindClient;
		}

		cout << "\t\t\t\t\tGive this User Access To Transactions Menu : ";
		cin >> ans;
		if (toupper(ans) == 'Y')
		{
			total += (int)en_Permissions::e_TransactionsM;
		}

		cout << "\t\t\t\t\tGive this User Access To Manage Users : ";
		cin >> ans;
		if (toupper(ans) == 'Y')
		{
			total += (int)en_Permissions::e_ManageUsersM;
		}
		cout << "\t\t\t\t\t__________________________________________\n\n";

		return total;
	}

	static void AccessDeniedMessage()
	{
		cls_Header::Header_Print("\tError.\n\n\t\t\t\t\t\tYou Don't Have Permission");
	}

	bool CheckPermission(en_Permissions PerNum)
	{
		if (this->Permissions == (int)en_Permissions::e_fullAccess)
		{
			return true;
		}

		if (((int)PerNum & this->Permissions) == (int)PerNum)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	static void RegisterLogin() 
	{
		fstream file;

		file.open(RegisterFile, ios::out | ios::app);

		if (file.is_open())
		{

			//file << ""

		}


		//cout << CurrentUserr.Get_UserName();
	}

};