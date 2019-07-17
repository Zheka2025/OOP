#include<iostream>
using namespace std;

//#define CONSTRUCTORS_CHECK
#define delimiter "\n-------------------------------------\n"

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;//Размер строки 
	char* str;//Адрес строки в динамической памяти
public:
	int get_size() const
	{
		return size;
	}
	const char* get_str() const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}


	//       Constructors:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}

	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}

	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}

	String(String&& other) : size{ other.size }, str(other.str)
	{
		/*this->size = other.size;
		this->str = other.str;*/
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}

	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//       Operators:

	String& operator=(const String& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}

	const char& operator[](int i)const
	{
		return this->str[i];
	}
	char& operator[](int i)
	{
		return this->str[i];
	}

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	/*String operator+(const String& other) const
	{
		int index = 0;
		String buff = (size + other.size) - 1;
		for (int i = 0; i < buff.size; i++)
		{
			if (i < this->size - 1)
			{
				buff.str[i] = this->str[i];
			}
			else
			{
				buff.str[i] = other.str[index];
				index++;
			}
		}
		return buff;
	}*/

	//       Methods:
	void print()
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}
};

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


void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str0; //Default constructor
	str0.print();
	cout << typeid("Hello").name() << endl;
	String str1 = "Hello"; // Single argument constructor
	str1.print();
	cout << str1 << endl;
	cout << "--------------------" << endl;
	String str2 = str1; // Copy Constructor
	cout << str2 << endl;
	cout << "--------------------" << endl;
	str0 = str1;
	cout << str0 << endl;
	str2 = str2;
	cout << str2 << endl;
#endif // CONSTRUCTORS_CHECK
	String str1 = "Hello";
	String str2{ "World" };
	cout << delimiter << endl;
	String str3;
	str3 = str1 + " " + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
	cout << delimiter << endl;
}