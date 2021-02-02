#include "TeacherPartyMember.h"

void TeacherPartyMember::setRoleInParty(char* role)
{
	if (this->roleInParty != nullptr)
	{
		delete[] this->autobiography;
	}

	int length = strlen(role);
	this->roleInParty = new char[length + 1];
	strcpy_s(this->roleInParty, length + 1, role);
}

char TeacherPartyMember::getRoleInParty()
{
	return *this->roleInParty;
}

bool TeacherPartyMember::operator == (const TeacherPartyMember& other)
{
	if (this->name == other.name || this->name == "")
		if (this->surname == other.surname || this->surname == "")
			if (this->yearOfBirth == other.yearOfBirth || this->yearOfBirth == 0)
				if (this->post == other.post || this->post == "")
					if (this->subject == other.subject || this->subject == "")
						if (strcmp(this->achievements, other.achievements) || strcmp(this->achievements, ""))
							if (this->partyName == other.partyName || this->partyName == "")
								if (strcmp(this->autobiography, other.autobiography) || strcmp(this->autobiography, ""))
									if (strcmp(this->roleInParty, other.roleInParty) || strcmp(this->roleInParty, ""))
										return true;
	return false;
}

TeacherPartyMember& TeacherPartyMember::operator =(const TeacherPartyMember& other)
{
	if (this->achievements != nullptr)
	{
		delete[] achievements;
	}

	if (this->autobiography != nullptr)
	{
		delete[] autobiography;
	}

	if (this->roleInParty != nullptr)
	{
		delete[] roleInParty;
	}

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

	return *this;
}

ostream& operator << (ostream& out, TeacherPartyMember& obj)
{
	out << dynamic_cast<PartyMember&>(obj);
	out << setw(10) << obj.roleInParty << setw(10) << obj.post << setw(10) << obj.achievements << setw(10) << obj.subject << endl;
	return out;
}

istream& operator >> (istream& in, TeacherPartyMember& obj)
{
	char ss[80];
	char ss1[80];
	char ss2[80];
	cout << "������� ���: ";
	in >> obj.name;
	cout << "������� �������: ";
	in >> obj.surname;
	cout << "������� ��� ��������: ";
	in >> obj.yearOfBirth;
	rewind stdin;
	cout << "������� ���� � ������: ";
	in.getline(ss, 80);
	obj.roleInParty = new char[strlen(ss) + 1];
	strcpy_s(obj.roleInParty, strlen(ss) + 1, ss);
	cout << "������� ���������: ";
	in >> obj.post;
	cout << "������� �������� ������: ";
	in >> obj.partyName;
	rewind stdin;
	cout << "������� �������������: ";
	in.getline(ss1, 80);
	obj.autobiography = new char[strlen(ss1) + 1];
	strcpy_s(obj.autobiography, strlen(ss1) + 1, ss1);
	rewind stdin;
	cout << "������� ����������: ";
	in.getline(ss2, 80);
	obj.achievements = new char[strlen(ss2) + 1];
	strcpy_s(obj.achievements, strlen(ss2) + 1, ss2);
	cout << "������� �������: ";
	in >> obj.subject;
	return in;
}

void TeacherPartyMember::hat()
{
	cout << setw(15) << "���" << setw(15) << "�������" << setw(15) << "��� ��������" << setw(20) << "�������� ������" << setw(20) 
	<< "�������������" << setw(20) << "���� � ������" << setw(20) << "���������"  << setw(15) << "����������"
	<< setw(15) << "�������" << endl << endl;
}

void TeacherPartyMember::changeInf()
{
	int choice;

	while (true)
	{
		system("cls");
		cout << "1. ���" << endl;
		cout << "2. �������" << endl;
		cout << "3. ��� ��������" << endl;
		cout << "4. ���������" << endl;
		cout << "5. �������" << endl;
		cout << "6. ����������" << endl;
		cout << "7. ��� ������" << endl;
		cout << "8. �������������" << endl;
		cout << "9. ���� � ������" << endl;
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
			string newPost;

			cout << "������� ����� ���������: ";
			cin >> newPost;
			setPost(newPost);

			break;
		}
		case 5:
		{
			string newSubject;

			cout << "������� ����� �������: ";
			cin >> newSubject;
			setSubject(newSubject);

			break;
		}
		case 6:
		{
			char buf[80];

			cout << "������� ����� ������ ������: ";
			rewind stdin;
			cin.getline(buf, 80);
			setAchievements(buf);

			break;
		}
		case 7:
		{
			string newPartyName;

			cout << "������� ����� ���������: ";
			cin >> newPartyName;
			setPartyName(newPartyName);

			break;
		}
		case 8:
		{
			char buf[100];

			cout << "������� ����� �������������: ";
			rewind stdin;
			cin.getline(buf, 100);
			setAutobiography(buf);

			break;
		}
		case 9:
		{
			char buf[80];

			cout << "������� ����� ���� � ������: ";
			rewind stdin;
			cin.getline(buf, 80);
			setRoleInParty(buf);

			break;
		}
		default:
			return;
		}

		system("pause");
	}
}