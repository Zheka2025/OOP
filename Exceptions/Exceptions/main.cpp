#include <iostream>

using namespace std;

//#define EXCEPTION_SYNTAX
//#define DIVISION_BY_ZERO_EXCEPTION
#define FACTORIAL

long long int factorial(int n);

void main()
{
	setlocale(LC_ALL, "");
#ifdef EXCEPTION_SYNTAX
	/*try
{
	throw 123;
}
catch (int error)
{
	cout << "Error# " << error << endl;
}*/
	try
	{
		throw "Kakaya-to fignja\n";
		throw 123;
		cout << "That's OK in try block" << endl;
	}
	catch (const char* error)
	{
		cerr << "Error: " << error << endl;
	}
	catch (...)
	{
		cerr << "Something happened :-(" << endl;
	}
	cout << "Buy!" << endl;
#endif // EXCEPTION_SYNTAX

#ifdef DIVISION_BY_ZERO_EXCEPTION
	int a = 3;
	int b = 0;
	try
	{
		cout << a / b << endl;
	}
	catch (std::exception& e)
	{
		cerr << e.what() << endl;
	}
	catch (...)
	{
		cerr << "Error: Integer division by zero" << endl;
	}
#endif // DIVISION_BY_ZERO_EXCEPTION

	int n; 
	cout << "Input number to find factorial: "; cin >> n;
	try
	{
		cout << n << " ! = " << factorial(n) << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
}

long long int factorial(int n)
{
	if (n > 20)throw overflow_error("too large number");//exception("Error: too large number, 20 maximum");
	long long int f = 1; // factorial
	for (int i = 1; i <= n; i++) f *= i;
	return f;
}