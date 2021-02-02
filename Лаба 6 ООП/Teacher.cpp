#include "Teacher.h"

char* Teacher::getAchievements()
{
	return this->achievements;
}

void Teacher::setPost(string post)
{
	this->post = post;
}

void Teacher::setSubject(string subject)
{
	this->subject = subject;
}

void Teacher::setAchievements(char* achiev)
{
	if (this->achievements != nullptr)
	{
		delete[] this->achievements;
	}

	int length = strlen(achiev);
	this->achievements = new char[length + 1];
	strcpy_s(this->achievements, length + 1, achiev);
}

string Teacher::getPost()
{
	return this->post;
}

string Teacher::getSubject()
{
	return this->subject;
}

ostream& operator << (ostream& out, const Teacher& teacher)
{
	out << setw(15) << teacher.name << setw(15) << teacher.surname << setw(15) << teacher.yearOfBirth
		<< setw(15) << teacher.post << setw(15) << teacher.achievements << setw(15) << teacher.subject << endl;
	return out;
}

istream& operator >> (istream& in, Teacher& teacher)
{
	cout << "Введите имя: ";
	in >> teacher.name;

	cout << "Введите фамилию: ";
	in >> teacher.surname;

	cout << "Введите год рождения: ";
	in >> teacher.yearOfBirth;

	cout << "Введите должность: ";
	in >> teacher.post;

	cout << "Введите достижения: ";
	char ss[80];
	rewind stdin;
	in.getline(ss, 80, '\n');
	teacher.setAchievements(ss);

	cout << "Введите предмет: ";
	in >> teacher.subject;
	return in;
}

bool Teacher::operator == (const Teacher& other)
{
	if (this->name == other.name || this->name == "")
		if (this->surname == other.surname || this->surname == "")
			if (this->yearOfBirth == other.yearOfBirth || this->yearOfBirth == 0)
				if (this->post == other.post || this->post == "")
					if (this->subject == other.subject || this->subject == "")
						if (strcmp(this->achievements, other.achievements) || strcmp(this->achievements, ""))
							return true;
	return false;
}

Teacher& Teacher::operator =(const Teacher& other)
{
	if (this->achievements != nullptr)
	{
		delete[] achievements;
	}

	this->name = other.name;
	this->surname = other.surname;
	this->yearOfBirth = other.yearOfBirth;
	this->post = other.post;
	this->subject = other.subject;

	int newLength = strlen(other.achievements);
	this->achievements = new char[newLength + 1];

	strcpy_s(this->achievements, newLength + 1, other.achievements);

	return *this;
}

void Teacher::hat()
{
	cout << setw(15) << "Имя" << setw(15) << "Фамилия" << setw(15) << "Год рождения" << setw(15) << "Должность"
		<< setw(15) << "Достижения" << setw(15) << "Предмет" << endl << endl;
}

void Teacher::changeInf()
{
	int choice;

	while (true)
	{
		system("cls");
		cout << "1. Имя" << endl;
		cout << "2. Фамилия" << endl;
		cout << "3. Год рождения" << endl;
		cout << "4. Должность" << endl;
		cout << "5. Предмет" << endl;
		cout << "6. Достижения" << endl;
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

			cout << "Введите новые достижения: ";
			rewind stdin;
			cin.getline(buf, 80);
			setAchievements(buf);

			break;
		}
		default:
			return;
		}

		system("pause");
	}
}