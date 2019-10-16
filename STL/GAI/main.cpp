#include <iostream>
#include <string>
#include <map>
#include <forward_list>
#include<Windows.h>
#include<conio.h>

#include "Crime.h"

using namespace std;

void print(const map<string, forward_list<Crime>>& database);
void print(const map<string, forward_list<Crime>>& database, const string& id);
void print(const map<string, forward_list<Crime>>& database, const string& start_id, const string& second_id);
bool add(map<string, forward_list<Crime>>& database, const string& id, const string& plase, const string& crime);

void main()
{
	setlocale(LC_ALL, "");
	map<string, forward_list<Crime>> database =
	{
		pair<string, forward_list<Crime>>("BI6666BC", {Crime("��� �� ����" ,"������ � ������ ������� ������, � ���������� ���� ���� �������� ������ ������, � ������� �����")}),
		pair<string, forward_list<Crime>>("BI6667BC", {Crime("MacDonalds" ,"������ � ���� ���")}),
		pair<string, forward_list<Crime>>("BI1488CI", {Crime("��������� ����" ,"���� ����� ����� ������")})
	};

	do
	{
		cout << "=============================\n\n";

		cout << "1. ����� ���� ����;" << endl;
		cout << "2. ����� ���������� �� ������;" << endl;
		cout << "3. ����� ���������� �� ��������� �������;" << endl;
		cout << "4. ��������� ������; " << endl;

		cout << "\n\n=============================\n\n";

		char key;
		cout << "�������� ��������: "; cin >> key;

		switch (key)
		{
		case '1': system("CLS"); print(database); break;
		case '2':
		{
			system("CLS");
			string id;
			cout << "������� ����� ����������: "; cin >> id;
			print(database, id);
		}
		break;
		case '3':
		{
			system("CLS");
			string start_id, second_id;
			cout << "������� ��������� �����: ";
			cin.sync();
			cin.get();
			getline(cin, start_id);
			cout << "������� �������� �����:";
			getline(cin, second_id);
			print(database, start_id, second_id);
		}
		break;
		case '4':
		{
			string id;
			string plase;
			string crime;
			cout << "������� ����� ����������: ";
			cin.sync();
			cin.get();
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			getline(cin, id);
			SetConsoleCP(866);
			SetConsoleOutputCP(866);
			cout << "������� ����� ������������: ";
			SetConsoleCP(1251);
			//SetConsoleOutputCP(1251);
			getline(cin, plase);
			SetConsoleCP(866);
			//SetConsoleOutputCP(866);
			cout << "������� �������� ���������: ";
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			getline(cin, crime);
			SetConsoleOutputCP(866);
			SetConsoleCP(866);
			if (!add(database, id, plase, crime))
			{
				cout << "����� ��� �������� � ����, ���������� ������������ ������ �������..." << endl;
			}
			else
			{
				cout << "����� ��� ���� � ����, ���������� ������������ ������ �������..." << endl;
			}
		}
		break;
		}
		cout << "\n\n=============================\n\n";
		cout << "��� ������ ������� ESC";
	} while (getch() != 27);
}

void print(const map<string, forward_list<Crime>>& database)
{
	for (pair<string, forward_list<Crime>> i : database)
	{
		cout << i.first << ":\n";
		for (Crime j : i.second)
		{
			cout << "����� ������������: " << j.get_place() << "\n" << "���������: " << j.get_crime() << endl;
		}
	}
}

void print(const map<string, forward_list<Crime>>& database, const string& id)
{
	bool present_in_base = false;
	for (pair<string, forward_list<Crime>>i : database)
	{
		if (id == i.first)
		{
			present_in_base = true;
			for (Crime j : i.second)
			{
				cout << "����� ������������: " << j.get_place() << "\n" << "���������: " << j.get_crime() << endl;
			}
		}
	}
	if (!present_in_base) cout << "� ���� ��� ������ ������" << endl;
}

void print(const map<string, forward_list<Crime>>& database, const string& start_id, const string& second_id)
{
	bool present_in_base = false;
	for (pair<string, forward_list<Crime>>i : database)
	{
		if (i.first >= start_id && i.first <= second_id)
		{
			for (Crime j : i.second)
			{
				cout << j.get_place() << "\t" << j.get_crime() << ";\n";
			}
		}
	}
	if (!present_in_base) cout << "� ���� ��� ������ ������" << endl;
}

bool add(map<string, forward_list<Crime>>& database, const string& id, const string& place, const string& crime)
{
	/*for (pair<string, forward_list<Crime>>i : database)
	{
		if (id == i.first)
		{
			present_in_base = true;
			i.second.push_front(Crime(place, crime));
		}
	}*/
	//for (map<string, forward_list<Crime>>::iterator it = database.begin(); it != database.end(); it++)
	//{
	//	if (id == it->first)
	//	{
	//		present_in_base = true;
	//		it->second.push_front(Crime(place, crime));
	//	}
	//}
	//if (!present_in_base)
	//{
	//	database.insert(pair<string, forward_list<Crime>>(id, { Crime(place, crime) }));
	//}
	database[id].push_front(Crime(place, crime));
	for (pair<string, forward_list<Crime>>i : database)
	{
		if (id == i.first)
		{
			return true;
		}
	}
	return false;
}