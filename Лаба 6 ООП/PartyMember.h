#pragma once

#include "Human.h"

class PartyMember : virtual public Human
{
protected:
	string partyName;
	char* autobiography;
public:
	PartyMember(const string partyName = "", const char* autobio = "", const string name = "", const string surname = "",
		const int yearOfBirth = 0) :Human(name, surname, yearOfBirth)
	{
		this->partyName = partyName;

		int length = strlen(autobio);
		this->autobiography = new char[length + 1];
		strcpy_s(this->autobiography, length + 1, autobio);
	}

	PartyMember(const PartyMember& other)
	{
		this->name = other.name;
		this->surname = other.surname;
		this->yearOfBirth = other.yearOfBirth;
		this->partyName = other.partyName;

		int newLength = strlen(other.autobiography);
		this->autobiography = new char[newLength + 1];

		strcpy_s(this->autobiography, newLength + 1, other.autobiography);
	}

	PartyMember& operator =(const PartyMember& other);

	~PartyMember()
	{
		delete[] this->autobiography;
	}

	void setPartyName(string partyName);
	void setAutobiography(char* autobio);
	string getPartyName();
	char getAutobiography();

	bool operator == (const PartyMember& other);
	friend ostream& operator << (ostream&, PartyMember&);
	friend istream& operator >> (istream&, PartyMember&);

	void hat();
	void changeInf();
};