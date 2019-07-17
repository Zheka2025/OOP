#pragma once
#include<iostream>
using namespace std;

//#define CONSTRUCTORS_CHECK
#define delimiter "\n-------------------------------------\n"

class String;
ostream& operator<<(ostream& os, const String& obj);
String operator+(const String& left, const String& right);

class String
{
	int size;//Размер строки 
	char* str;//Адрес строки в динамической памяти
public:
	int get_size() const;
	const char* get_str() const;
	char* get_str();


	//       Constructors:
	String(int size = 80);

	String(const char* str);

	String(const String& other);

	String(String&& other);

	~String();

	//       Operators:

	String& operator=(const String& other);

	String& operator=(String&& other);

	const char& operator[](int i)const;
	char& operator[](int i);

	String& operator+=(const String& other);

	//       Methods:
	void print();
};