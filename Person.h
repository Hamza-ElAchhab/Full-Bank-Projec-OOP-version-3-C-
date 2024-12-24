#pragma once
#include <iostream>
#include <string>
using namespace std;







class cls_Person
{

private:

	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;



public :

	cls_Person(string first, string last, string email, string phone)
	{
		this->_FirstName = first;
		this->_LastName = last;
		this->_Email = email;
		this->_Phone = phone;
	}



	string Get_FirstName()
	{
		return _FirstName;
	}
	void Set_FirstName(string first)
	{
		_FirstName = first;
	}
	__declspec(property(get = Get_FirstName, put = Set_FirstName)) string FirstName;


	string Get_LastName()
	{
		return _LastName;
	}
	void Set_LastName(string last)
	{
		_LastName = last;
	}
	__declspec(property(get = Get_LastName, put = Set_LastName)) string LastName;


	string Get_Email()
	{
		return _Email;
	}
	void Set_Email(string email)
	{
		_Email = email;
	}
	__declspec(property(get = Get_Email, put = Set_Email)) string Email;


	string Get_Phone()
	{
		return _Phone;
	}
	void Set_Phone(string phone)
	{
		_Phone = phone;
	}
	__declspec(property(get = Get_Phone, put = Set_Phone)) string Phone;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

};