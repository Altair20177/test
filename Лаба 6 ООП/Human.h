#pragma once
#include <iostream>
#include <iomanip>
#include <string.h>
#include <windows.h>
#include <cmath>

using namespace std;

class Human
{
protected:
	string name;
	string surname;
	int yearOfBirth;

public:
	Human(const string name = "", const string surname = "", const int yearOfBirth = 0)
	{
		this->name = name;
		this->surname = surname;
		this->yearOfBirth = yearOfBirth;
	}

	void setName(string name);
	void setSurname(string surname);
	void setYearOfBirth(int yearOfBirth);
	string getName() const;
	string getSurname() const;
	int getYearOfBirth() const;

	friend ostream& operator << (ostream& out, Human& obj);
	friend istream& operator >> (istream& in, Human& obj);
};