#include "Human.h"


int Human::getYearOfBirth() const
{
	return this->yearOfBirth;
}

void Human::setName(string name)
{
	this->name = name;
}

void Human::setSurname(string surname)
{
	this->surname = surname;
}

void Human::setYearOfBirth(int yearOfBirth)
{
	this->yearOfBirth = yearOfBirth;
}

string Human::getName() const
{
	return this->name;
}

string Human::getSurname() const
{
	return this->surname;
}

ostream& operator << (ostream& out, Human& obj)
{
	out << setw(15) << obj.name << setw(15) << obj.surname << setw(15) << obj.yearOfBirth;
	return out;
}

istream& operator >> (istream& in, Human& obj)
{
	cout << "¬ведите им€: ";
	in >> obj.name;
	cout << "¬ведите фамилию: ";
	in >> obj.surname;
	cout << "¬ведите год рождени€: ";
	in >> obj.yearOfBirth;

	return in;
}