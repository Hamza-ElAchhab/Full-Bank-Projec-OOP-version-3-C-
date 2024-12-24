#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


#include "FilesNames.h"
#include "Person.h";





class cls_CenterClients : public cls_Person
{

private :

	enum en_ClientMode
	{
		e_EmptyMode = 0, e_UpDateMode = 1, e_AddNewMode = 2
	};

	en_ClientMode _Mode;
	string _AcountNumber;
	string _PinCode;
	float  _Balance;
	bool   _MarkForDelete = false;


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

	static cls_CenterClients _Fill_Client_Object_Form_Line(string line)
	{
		vector<string> vStrings = _Split(line);
		return cls_CenterClients(en_ClientMode::e_UpDateMode, vStrings[0], vStrings[1], vStrings[2], vStrings[3], vStrings[4], vStrings[5], stof(vStrings[6]));
	}

	static cls_CenterClients _Empty_Obj()
	{
		return cls_CenterClients(en_ClientMode::e_EmptyMode, "", "", "", "", "", "", 0);
	}

	string _Convert_Object_Client_To_String(cls_CenterClients obj, string sep = "#//#")
	{
		string str = "";
		str += obj.FirstName + sep;
		str += obj.LastName + sep;
		str += obj.Email + sep;
		str += obj.Phone + sep;
		str += obj.Get_AcountNumber() + sep;
		str += obj.PinCode + sep;
		str += to_string(obj.Balance);

		return str;
	}

	static vector<cls_CenterClients> _Load_Data_OfClient_FromFile()
	{
		vector<cls_CenterClients> vData;
		fstream file;
		file.open(ClientsFile, ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				cls_CenterClients obj = _Fill_Client_Object_Form_Line(line);
				obj._MarkForDelete = false;

				vData.push_back(obj);
			}

			file.close();
		}
		return vData;
	}

	void _Save_vData_To_File(vector<cls_CenterClients> vData)
	{
		fstream file;
		file.open(ClientsFile, ios::out);

		if (file.is_open())
		{
			for (cls_CenterClients& O : vData)
			{
				if (O._MarkForDelete == false)
				{
					file << _Convert_Object_Client_To_String(O) << endl;
				}
			}
			file.close();
		}
	}

	void _Add_RecordLine_To_File(string RecLine)
	{
		fstream file;
		file.open(ClientsFile, ios::app | ios::out);

		if (file.is_open())
		{
			file << RecLine << endl;
		}
		file.close();
	}

	void _UpDate()
	{
		vector <cls_CenterClients> vData = _Load_Data_OfClient_FromFile();

		for (cls_CenterClients& O : vData)
		{
			if (this->Get_AcountNumber() == O.Get_AcountNumber())
			{
				O = *this;
				break;
			}
		}
		_Save_vData_To_File(vData);
	}

	void _AddNew()
	{
		_Add_RecordLine_To_File(_Convert_Object_Client_To_String(*this));
	}


public :


	cls_CenterClients(en_ClientMode mode, string first, string last, string email, string phone, string Acount, string Pin, float balance)
		: cls_Person(first, last, email, phone)
	{

		this->_Mode = mode;
		this->_AcountNumber = Acount;
		this->_PinCode = Pin;
		this->_Balance = balance;

	}

	//read only
	bool Get_Mode()
	{
		return this->_Mode;
	}
	string Get_AcountNumber()
	{
		return this->_AcountNumber;
	}

	string Get_PinCode()
	{
		return this->_PinCode;
	}
	void Set_PinCode(string pin)
	{
		this->_PinCode = pin;
	}
	__declspec(property(get = Get_PinCode, put = Set_PinCode)) string PinCode;

	float Get_Balance()
	{
		return this->_Balance;
	}
	void Set_Balance(float balance)
	{
		this->_Balance = balance;
	}
	__declspec(property(get = Get_Balance, put = Set_Balance)) float Balance;

	void Print()
	{
		cout << endl << endl << "----------------------------------";
		cout << "\nFirst Name  : " << FirstName << endl;
		cout << "Last Name   : " << LastName << endl;
		cout << "Full Name   : " << FullName() << endl;
		cout << "Your Email  : " << Email << endl;
		cout << "Your Phone  : " << Phone << endl;
		cout << "Acount Num  : " << this->_AcountNumber << endl;
		cout << "Pin Code    : " << this->_PinCode << endl;
		cout << "Balance     : " << this->_Balance << endl;
		cout << "----------------------------------\n";
	}
	
	bool is_EmptyObject()
	{
		return (this->_Mode == en_ClientMode::e_EmptyMode) ? true : false;
	}



	static cls_CenterClients Find(string AcountNumber)
	{
		fstream file;
		file.open(ClientsFile, ios::in);

		if (file.is_open())
		{
			string Line;
			while (getline(file, Line))
			{
				cls_CenterClients obj = _Fill_Client_Object_Form_Line(Line);

				if (obj.Get_AcountNumber() == AcountNumber)
				{
					file.close();
					return obj;
				}
			}
			file.close();
		}
		return _Empty_Obj();
	}

	static cls_CenterClients Find(string AcountNumber, string PinCode)
	{
		fstream file;
		file.open(ClientsFile, ios::in);

		if (file.is_open())
		{
			string Line;
			while (getline(file, Line))
			{
				cls_CenterClients obj = _Fill_Client_Object_Form_Line(Line);

				if (obj.Get_AcountNumber() == AcountNumber && obj.PinCode == PinCode)
				{
					file.close();
					return obj;
				}
			}
			file.close();
		}
		return _Empty_Obj();
	}

	static cls_CenterClients Get_AddNew_Obj(string AcountNumber)
	{
		return cls_CenterClients(en_ClientMode::e_AddNewMode, "", "", "", "", AcountNumber, "", 0);
	}

	static vector<cls_CenterClients> Load_Data()
	{
		return _Load_Data_OfClient_FromFile();
	}

	static bool isClientExists(string AcountNumber)
	{
		cls_CenterClients obj = Find(AcountNumber);
		return (obj._Mode == en_ClientMode::e_UpDateMode) ? true : false;
	}

	void Delete()
	{
		vector<cls_CenterClients> vData = _Load_Data_OfClient_FromFile();

		for (cls_CenterClients& O : vData)
		{
			if (this->Get_AcountNumber() == O.Get_AcountNumber())
			{
				O._MarkForDelete = true;
				break;
			}
		}
		*this = _Empty_Obj();
		_Save_vData_To_File(vData);
	}


	enum en_SaveResult
	{
		e_SaveSuccessfully = 1, e_SaveFailedEmpty = 2, e_SaveFailed_Aleady_EXI = 3
	};

	en_SaveResult Save()
	{
		switch (this->_Mode)
		{

		case en_ClientMode::e_EmptyMode:
			return en_SaveResult::e_SaveFailedEmpty;


		case en_ClientMode::e_AddNewMode:
			if (isClientExists(this->Get_AcountNumber()))
			{
				return en_SaveResult::e_SaveFailed_Aleady_EXI;
			}
			else
			{
				_AddNew();
				return en_SaveResult::e_SaveSuccessfully;
			}


		case en_ClientMode::e_UpDateMode:
			_UpDate();
			return en_SaveResult::e_SaveSuccessfully;

		}
	}


	void Deposite(float Amount)
	{
		this->Balance += Amount;
		_UpDate();
	}

	bool WithDraw(float Amount)
	{
		if (this->Balance < Amount)
		{
			return false;
		}
		else
		{
			this->Balance -= Amount;
			_UpDate();
			return true;
		}
	}

	static float TotalBalances()
	{
		float total = 0;
		vector<cls_CenterClients> vData = cls_CenterClients::Load_Data();

		for (cls_CenterClients& O : vData)
		{
			total += O.Balance;
		}
		
		return total;
	}


};