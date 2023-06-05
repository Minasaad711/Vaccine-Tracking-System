#pragma once
#include "VaccQueue.h"
#include <iostream>
using namespace std;

class User
{
public:
		static VaccQueue waiting_list;
		string name;
	int ID;
	int age;
	string pass;
	string gender;
	string governorate;
	bool Vaccine;
	int dose;
	int wait_num = 0;
	User ();
	User(string name, int ID, int age, string pass, string gender, string governorate, bool Vaccine, int dose);
	User(User&p);
	

	void Login(int&inputID, string&inputPass);
	void AdminMenu();
	int UserMenu();
	int MainMenu();
	void Edit();
	void Delete();
	void GetData();
	void DisplayData();
	void DisplayStatistics();
	~User();
};

