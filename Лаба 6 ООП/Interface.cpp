#include "Interface.h"
#include "TeacherPartyMember.h"

template <class T>
void Interface<T>::menu()
{
	Ring<Teacher> teacherRing;
	Ring<PartyMember> PartyMemberRing;
	Ring<TeacherPartyMember> TeacherPartyMemberRing;

	int selection;

	do
	{
		system("cls");
		cout << "1 - Учителя. " << endl;
		cout << "2 - Участники партии. " << endl;
		cout << "3 - Учителя-участники партии. " << endl;
		cout << "Другое - выход" << endl;

		cin >> selection;

		switch (selection)
		{
		case 1:
		{
			Interface<Teacher> object;
			object.functions(teacherRing);
			break;
		}
		case 2:
		{
			Interface<PartyMember> object;
			object.functions(PartyMemberRing);
			break;
		}
		case 3:
		{
			Interface<TeacherPartyMember> object;
			object.functions(TeacherPartyMemberRing);
			break;
		}
		default:
			return;
		}

	} while (true);
}

template <class T>
void Interface<T>::functions(Ring<T>& ring)
{
	int selection;

	do
	{
		system("cls");
		cout << "1 - Добавить элемент" << endl;
		cout << "2 - Удалить элемент" << endl;
		cout << "3 - Удалить список" << endl;
		cout << "4 - Вывести список на экран" << endl;
		cout << "5 - Найти элемент списка по значению" << endl;
		cout << "6 - Изменить информацию" << endl;
		cout << "7 - Отсортировать список(по имени)" << endl;
		cout << "Другое - выход" << endl;

		cin >> selection;
		system("cls");

		switch (selection)
		{
		case 1:
		{
			T value;
			cin >> value;
			ring.pushback(value);

			cout << "Элемент успешно добавлен!" << endl << endl;
			system("pause");
			break;
		}
		case 2:
		{
			int choice;

			cout << "1. Первый" << endl;
			cout << "2. Последний" << endl;
			cout << "3. Из i-ой позиции" << endl;
			cout << "Другое - выход" << endl;

			cin >> choice;

			switch (choice)
			{
			case 1:
			{
				ring.popfront();
				break;
			}
			case 2:
			{
				ring.popback();
				break;
			}
			case 3:
			{
				int position;

				do
				{
					cout << "Введите позицию от 1 до " << ring.howmany_links() << ": ";
					cin >> position;
				} while (position < 1 || position > ring.howmany_links());

				position--;
				ring.popAny(position);
				break;
			}
			default: break;
			}

			cout << "Элемент успешно удалён!" << endl << endl;
			system("pause");
			break;
		}
		case 3:
		{
			ring.clear();
			cout << "Список успешно удалён!" << endl << endl;
			system("pause");
			break;
		}
		case 4:
		{
			cout << "Элементы списка: " << endl;
			ring.showList();
			cout << endl;
			system("pause");
			break;
		}
		case 5:
		{
			if (ring.isEmpty())
			{
				cout << "Список пуст!" << endl;
				break;
			}

			ring.findByValue();
			break;
		}
		case 6:
			if (ring.isEmpty())
			{
				cout << "Список пуст!" << endl;
				break;
			}
			ring.editElement();
			break;
		case 7:
		{
			cout << "Отсортированный список: " << endl;
			ring.sortlist();
			cout << endl;
			system("pause");
			break;
		}
		default:
			return;
		}

	} while (true);
}