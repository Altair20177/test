#pragma once
#include "Human.h"
#include "Ring.h"

class Teacher :virtual  public Human
{
protected:
	string post;
	string subject;
	char* achievements;
public:
	Teacher(const string post = "", const string subject = "", const char* achiev = "", const string name = "", const string surname = "",
		const int yearOfBirth = 0) :Human(name, surname, yearOfBirth)
	{
		this->post = post;
		this->subject = subject;

		int length = strlen(achiev);
		this->achievements = new char[length + 1];
		strcpy_s(this->achievements, length + 1, achiev);
	}

	Teacher(const Teacher& other)
	{
		this->name = other.name;
		this->surname = other.surname;
		this->yearOfBirth = other.yearOfBirth;
		this->post = other.post;
		this->subject = other.subject;

		int newLength = strlen(other.achievements);
		this->achievements = new char[newLength + 1];

		strcpy_s(this->achievements, newLength + 1, other.achievements);
	}

	Teacher& operator=(const Teacher& other);

	~Teacher()
	{
		delete[] this->achievements;
	}

	void setPost(string post);
	void setSubject(string subject);
	void setAchievements(char* achiev);
	string getPost();
	string getSubject();
	char* getAchievements();

	bool operator == (const Teacher& other);
	friend ostream& operator << (ostream& out, const Teacher& teacher);
	friend istream& operator >> (istream& in, Teacher& teacher);

	void hat();
	void changeInf();
};