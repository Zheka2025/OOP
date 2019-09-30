#include<iostream>
#include<string>

#include<map>
#include<vector>

using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	map<string, vector<string>> dictionary =
	{
		pair<string, vector<string>>("pain", vector<string>{"боль","огорчение"}),
		pair<string, vector<string>>("love", vector<string>{"любовь","страсть", "илюбленность"}),
		pair<string, vector<string>>("space", vector<string>{"космос","пространство", "пробел"}),
		pair<string, vector<string>>("void", vector<string>{"пустота","вакуум", "полость"}),
		pair<string, vector<string>>("solitude", vector<string>{"одиночество","уединение"}),
		pair<string, vector<string>>("winter", vector<string>{"зима"})
	};
	

	//Standart output:
	for (map<string, vector<string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		cout << it->first << endl;
		for (vector<string>::iterator iter = it->second.begin(); iter != it->second.end(); iter++)
		{
			cout << *iter << endl;
		}
		cout << "\n-------------------------------\n";
	}

	cout << "\n\n================================\n\n";

	//short output:
	for (pair<string, vector<string>>i : dictionary)
	{
		cout << i.first << endl;
		for (string j : i.second)
		{
			cout << j << endl;
		}
		cout << "\n-----------------------------\n";
	}


}