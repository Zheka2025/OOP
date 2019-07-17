#include"String.h"

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