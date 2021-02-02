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
		cout << "1 - �������. " << endl;
		cout << "2 - ��������� ������. " << endl;
		cout << "3 - �������-��������� ������. " << endl;
		cout << "������ - �����" << endl;

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
		cout << "1 - �������� �������" << endl;
		cout << "2 - ������� �������" << endl;
		cout << "3 - ������� ������" << endl;
		cout << "4 - ������� ������ �� �����" << endl;
		cout << "5 - ����� ������� ������ �� ��������" << endl;
		cout << "6 - �������� ����������" << endl;
		cout << "7 - ������������� ������(�� �����)" << endl;
		cout << "������ - �����" << endl;

		cin >> selection;
		system("cls");

		switch (selection)
		{
		case 1:
		{
			T value;
			cin >> value;
			ring.pushback(value);

			cout << "������� ������� ��������!" << endl << endl;
			system("pause");
			break;
		}
		case 2:
		{
			int choice;

			cout << "1. ������" << endl;
			cout << "2. ���������" << endl;
			cout << "3. �� i-�� �������" << endl;
			cout << "������ - �����" << endl;

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
					cout << "������� ������� �� 1 �� " << ring.howmany_links() << ": ";
					cin >> position;
				} while (position < 1 || position > ring.howmany_links());

				position--;
				ring.popAny(position);
				break;
			}
			default: break;
			}

			cout << "������� ������� �����!" << endl << endl;
			system("pause");
			break;
		}
		case 3:
		{
			ring.clear();
			cout << "������ ������� �����!" << endl << endl;
			system("pause");
			break;
		}
		case 4:
		{
			cout << "�������� ������: " << endl;
			ring.showList();
			cout << endl;
			system("pause");
			break;
		}
		case 5:
		{
			if (ring.isEmpty())
			{
				cout << "������ ����!" << endl;
				break;
			}

			ring.findByValue();
			break;
		}
		case 6:
			if (ring.isEmpty())
			{
				cout << "������ ����!" << endl;
				break;
			}
			ring.editElement();
			break;
		case 7:
		{
			cout << "��������������� ������: " << endl;
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