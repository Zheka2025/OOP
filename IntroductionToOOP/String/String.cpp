#include"String.h"
int String::get_size() const
{
	return size;
}
const char* String::get_str() const
{
	return str;
}
char* String::get_str()
{
	return str;
}


//       Constructors:
String::String(int size)
{
	this->size = size;
	this->str = new char[size] {};
	cout << "DefConstructor:\t" << this << endl;
}

String::String(const char* str)
{
	this->size = strlen(str) + 1;
	this->str = new char[size] {};
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}

String::String(const String& other)
{
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:\t" << this << endl;
}

String::String(String&& other) : size{ other.size }, str(other.str)
{
	/*this->size = other.size;
	this->str = other.str;*/
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
}

String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}

//       Operators:

String& String::operator=(const String& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}

const char& String::operator[](int i)const
{
	return this->str[i];
}
char& String::operator[](int i)
{
	return this->str[i];
}

String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

//       Methods:
void String::print()
{
	cout << "size:\t" << size << endl;
	cout << "str:\t" << str << endl;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String buff = left.get_size() + right.get_size() - 1;
	for (int i = 0; left[i]; i++)
		buff[i] = left[i];
	for (int i = 0; right[i]; i++)
		buff.operator[](i + left.get_size() - 1) = right.operator[](i);
	return buff;
}