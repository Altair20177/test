#include "PartyMember.h"

char PartyMember::getAutobiography()
{
	return *this->autobiography;
}

void PartyMember::setPartyName(string partyName)
{
	this->partyName = partyName;
}

void PartyMember::setAutobiography(char* autobio)
{
	if (this->autobiography != nullptr)
	{
		delete[] this->autobiography;
	}

	int length = strlen(autobio);
	this->autobiography = new char[length + 1];
	strcpy_s(this->autobiography, length + 1, autobio);
}

string PartyMember::getPartyName()
{
	return this->partyName;
}

bool PartyMember::operator == (const PartyMember& other)
{
	if (this->name == other.name || this->name == "")
		if (this->surname == other.surname || this->surname == "")
			if (this->yearOfBirth == other.yearOfBirth || this->yearOfBirth == 0)
				if (this->partyName == other.partyName || this->partyName == "")
					if (strcmp(this->autobiography, other.autobiography) || strcmp(this->autobiography, ""))
						return true;
	return false;
}

PartyMember& PartyMember::operator =(const PartyMember& other)
{
	if (this->autobiography != nullptr)
	{
		delete[] autobiography;
	}

	this->name = other.name;
	this->surname = other.surname;
	this->yearOfBirth = other.yearOfBirth;
	this->partyName = other.partyName;

	int newLength = strlen(other.autobiography);
	this->autobiography = new char[newLength + 1];

	strcpy_s(this->autobiography, newLength + 1, other.autobiography);

	return *this;
}

ostream& operator << (ostream& out, PartyMember& obj)
{
	out << dynamic_cast<Human&>(obj);
	out << setw(20) << obj.partyName << setw(20) << obj.autobiography << endl;
	return out;
}

istream& operator >> (istream& in, PartyMember& obj)
{
	char ss[80];

	in >> dynamic_cast<Human&>(obj);

	cout << "������� �������� ������: ";
	in >> obj.partyName;

	rewind stdin;
	cout << "������� �������������: ";
	in.getline(ss, 80);
	obj.autobiography = new char[strlen(ss) + 1];
	strcpy_s(obj.autobiography, strlen(ss) + 1, ss);
	return in;
}

void PartyMember::hat()
{
	cout << setw(15) << "���" << setw(15) << "�������" << setw(15) << "��� ��������" << setw(20) << "�������� ������"
		<< setw(20) << "�������������" << endl << endl;
}

void PartyMember::changeInf()
{
	int choice;

	while (true)
	{
		system("cls");
		cout << "1. ���" << endl;
		cout << "2. �������" << endl;
		cout << "3. ��� ��������" << endl;
		cout << "4. ��� ������" << endl;
		cout << "5. �������������" << endl;
		cout << "������ - �����" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			string newName;

			cout << "������� ����� ���: ";
			cin >> newName;
			setName(newName);

			break;
		}
		case 2:
		{
			string newSurname;

			cout << "������� ����� �������: ";
			cin >> newSurname;
			setSurname(newSurname);

			break;
		}
		case 3:
		{
			int newYear;

			cout << "������� ����� ��� ��������: ";
			cin >> newYear;
			setYearOfBirth(newYear);

			break;
		}
		case 4:
		{
			string newPartyName;

			cout << "������� ����� ��� ������: ";
			cin >> newPartyName;
			setPartyName(newPartyName);

			break;
		}
		case 5:
		{
			char buf[80];

			cout << "������� ����� �������������: ";
			rewind stdin;
			cin.getline(buf, 80);
			setAutobiography(buf);

			break;
		}
		default:
			return;
		}

		system("pause");
	}
}