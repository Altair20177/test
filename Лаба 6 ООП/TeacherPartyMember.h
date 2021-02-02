#pragma once

#include "PartyMember.h"
#include "Teacher.h"

class TeacherPartyMember :public Teacher, public PartyMember
{
protected:
	char* roleInParty;
public:
	TeacherPartyMember(const char* role = "", const char* achiev = "", const char* autobio = "", const string partyName = "",
		const string post = "", const string subject = "", const string name = "", const string surname = "", const int yearOfBirth = 0) :
		Teacher(post, subject, achiev, name, surname, yearOfBirth), PartyMember(partyName, autobio, name, surname, yearOfBirth)
	{
		int length = strlen(role);
		this->roleInParty = new char[length + 1];
		strcpy_s(this->roleInParty, length + 1, role);
	}
	
	TeacherPartyMember(const TeacherPartyMember& other)
	{
		this->name = other.name;
		this->surname = other.surname;
		this->yearOfBirth = other.yearOfBirth;
		this->post = other.post;
		this->subject = other.subject;
		this->partyName = other.partyName;

		int newLength1 = strlen(other.achievements);
		this->achievements = new char[newLength1 + 1];

		strcpy_s(this->achievements, newLength1 + 1, other.achievements);

		int newLength2 = strlen(other.autobiography);
		this->autobiography = new char[newLength2 + 1];

		strcpy_s(this->autobiography, newLength2 + 1, other.autobiography);

		int newLength3 = strlen(other.roleInParty);
		this->roleInParty = new char[newLength3 + 1];

		strcpy_s(this->roleInParty, newLength3 + 1, other.roleInParty);
	}

	~TeacherPartyMember()
	{
		delete[] this->roleInParty;
	}

	void setRoleInParty(char* role);
	char getRoleInParty();

	bool operator == (const TeacherPartyMember& other);
	TeacherPartyMember& operator =(const TeacherPartyMember& other);
	friend ostream& operator << (ostream&, TeacherPartyMember&);
	friend istream& operator >> (istream&, TeacherPartyMember&);

	void hat();
	void changeInf();
};