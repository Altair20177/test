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
	cout << "Введите имя: ";
	in >> obj.name;
	cout << "Введите фамилию: ";
	in >> obj.surname;
	cout << "Введите год рождения: ";
	in >> obj.yearOfBirth;
	rewind stdin;
	cout << "Введите роль в партии: ";
	in.getline(ss, 80);
	obj.roleInParty = new char[strlen(ss) + 1];
	strcpy_s(obj.roleInParty, strlen(ss) + 1, ss);
	cout << "Введите должность: ";
	in >> obj.post;
	cout << "Введите название партии: ";
	in >> obj.partyName;
	rewind stdin;
	cout << "Введите автобиографию: ";
	in.getline(ss1, 80);
	obj.autobiography = new char[strlen(ss1) + 1];
	strcpy_s(obj.autobiography, strlen(ss1) + 1, ss1);
	rewind stdin;
	cout << "Введите достижения: ";
	in.getline(ss2, 80);
	obj.achievements = new char[strlen(ss2) + 1];
	strcpy_s(obj.achievements, strlen(ss2) + 1, ss2);
	cout << "Введите предмет: ";
	in >> obj.subject;
	return in;
}

void TeacherPartyMember::hat()
{
	cout << setw(15) << "Имя" << setw(15) << "Фамилия" << setw(15) << "Год рождения" << setw(20) << "Название партии" << setw(20) 
	<< "Автобиография" << setw(20) << "Роль в партии" << setw(20) << "Должность"  << setw(15) << "Достижения"
	<< setw(15) << "Предмет" << endl << endl;
}

void TeacherPartyMember::changeInf()
{
	int choice;

	while (true)
	{
		system("cls");
		cout << "1. Имя" << endl;
		cout << "2. Фамилию" << endl;
		cout << "3. Год рождения" << endl;
		cout << "4. Должность" << endl;
		cout << "5. Предмет" << endl;
		cout << "6. Достижения" << endl;
		cout << "7. Имя партии" << endl;
		cout << "8. Автобиография" << endl;
		cout << "9. Роль в партии" << endl;
		cout << "Другое - выход" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			string newName;

			cout << "Введите новое имя: ";
			cin >> newName;
			setName(newName);

			break;
		}
		case 2:
		{
			string newSurname;

			cout << "Введите новую фамилию: ";
			cin >> newSurname;
			setSurname(newSurname);

			break;
		}
		case 3:
		{
			int newYear;

			cout << "Введите новый год рождения: ";
			cin >> newYear;
			setYearOfBirth(newYear);

			break;
		}
		case 4:
		{
			string newPost;

			cout << "Введите новую должность: ";
			cin >> newPost;
			setPost(newPost);

			break;
		}
		case 5:
		{
			string newSubject;

			cout << "Введите новый предмет: ";
			cin >> newSubject;
			setSubject(newSubject);

			break;
		}
		case 6:
		{
			char buf[80];

			cout << "Введите новый список трудов: ";
			rewind stdin;
			cin.getline(buf, 80);
			setAchievements(buf);

			break;
		}
		case 7:
		{
			string newPartyName;

			cout << "Введите новую должность: ";
			cin >> newPartyName;
			setPartyName(newPartyName);

			break;
		}
		case 8:
		{
			char buf[100];

			cout << "Введите новую автобиографию: ";
			rewind stdin;
			cin.getline(buf, 100);
			setAutobiography(buf);

			break;
		}
		case 9:
		{
			char buf[80];

			cout << "Введите новую роль в партии: ";
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