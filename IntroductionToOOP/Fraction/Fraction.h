#pragma once
#include<iostream>
using namespace std;

//#define CHECK_ALL

#define MINUS true;
#define PLUS false;

class Fraction;

std::ostream& operator<<(std::ostream& os, const Fraction& obj);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator+=(Fraction& left, Fraction right);
Fraction operator-=(Fraction& left, Fraction right);
Fraction operator*=(Fraction& left, Fraction right);
Fraction operator/=(Fraction& left, Fraction right);

bool operator==(Fraction left, Fraction right);
bool operator!=(Fraction left, Fraction right);
bool operator>(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator>=(Fraction left, Fraction right);
bool operator<=(Fraction left, Fraction right);

class Fraction
{
	bool minus;
	int integer;
	int numerator;
	int denominator;
public:
	bool get_minus() const;
	int get_integer() const;
	int get_numerator() const;
	int get_denominator() const;
	void set_minus(bool minus);
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//------------------------Constructors------------------------//
	Fraction();
	Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);

	Fraction(const Fraction& other);

	//-------------------------Operators---------------------------//

	Fraction& operator=(const Fraction& other);

	Fraction& operator++();

	Fraction operator++(int);

	Fraction& operator--();

	Fraction operator--(int);

	//-------------------------Methods---------------------------//
	void to_proper();
	void to_improper();
	void Adapting(Fraction& other);

	void Reduction();
	void Print();
};