#include<iostream>
using namespace std;

//#define CHECK_ALL

#define MINUS true;
#define PLUS false;

class Fraction
{
	bool minus;
	int integer;
	int numerator;
	int denominator;
public:
	bool get_minus() const
	{
		return minus;
	}
	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}
	void set_minus(bool minus)
	{
		this->minus = minus;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) throw exception("Division by zero");
		this->denominator = denominator;
	}

	//------------------------Constructors------------------------//
	Fraction()
	{
		this->minus = false;
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
	}
	Fraction(int integer)
	{
		this->minus = false;
		if (integer < 0)
		{
			this->minus = true;
			integer = -integer;
		}
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
	}
	Fraction(int numerator, int denominator)
	{
		this->minus = false;
		if (numerator < 0)
		{
			this->minus = true;
			numerator = -numerator;
		}
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator > 0 ? denominator : -denominator;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->minus = false;
		if (integer < 0)
		{
			minus = true;
			integer = -integer;
		}
		this->integer = integer;
		this->numerator = numerator > 0 ? numerator : -numerator;
		this->denominator = denominator > 0 ? denominator : -denominator;
	}

	Fraction(const Fraction& other)
	{
		this->minus = other.minus;
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}

	//-------------------------Operators---------------------------//

	Fraction& operator=(const Fraction& other)
	{
		this->minus = other.minus;
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		return *this;
	}

	Fraction& operator++()
	{
		this->integer++;
		return *this;
	}

	Fraction operator++(int)
	{
		Fraction temp = *this;
		this->integer++;
		return temp;
	}

	Fraction& operator--()
	{
		this->integer--;
		return *this;
	}

	Fraction operator--(int)
	{
		Fraction temp = *this;
		this->integer--;
		return temp;
	}

	//-------------------------Methods---------------------------//
	void to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
	}
	void to_improper()
	{
		numerator += integer * denominator;
		this->integer = 0;
	}
	void Adapting(Fraction& other)
	{
		int adapt = this->denominator;
		this->numerator *= other.denominator;
		this->denominator *= other.denominator;
		other.numerator *= adapt;
		other.denominator *= adapt;
	}

	void Reduction()
	{
		int reduct = this->numerator;
		if (reduct < 0)
		{
			reduct *= -1;
		}
		for (int i = reduct; i > 1; i--)
		{
			if (reduct % i == 0 && this->denominator % i == 0)
			{
				this->numerator /= i;
				this->denominator /= i;
				return;
			}
		}
	}

	void Print()
	{
		if (this->numerator == this->denominator) cout << numerator;
		if (this->numerator > this->denominator && this->denominator) cout << numerator;
		else cout << numerator << "/" << denominator << " ";
	}
};

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_minus() == true) os << '-';
	if (obj.get_integer() != 0) os << obj.get_integer();
	if (obj.get_numerator() != 0)
	{
		if (obj.get_integer() != 0)cout << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")";
		else cout << obj.get_numerator() << "/" << obj.get_denominator();
	}
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)
	{
		os << 0;
	}

	return os;

	/*if (obj.get_numerator() == obj.get_denominator()) os << obj.get_denominator();
	if (obj.get_numerator() > obj.get_denominator()) os << obj.get_numerator();
	else return os << obj.get_numerator() << "/" << obj.get_denominator();*/

}

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

void main()
{
	setlocale(LC_ALL, "");
#ifdef CHECK_ALL
	int n;
	Fraction A(8, 13);
	Fraction B(3, 19);
	Fraction C;
	cout << "¬ведите числитель первого числа: "; cin >> n;
	A.set_numerator(n);
	cout << "¬ведите знаминатель первого числа: "; cin >> n;
	A.set_denominator(n);
	cout << "¬ведите числитель второго числа: "; cin >> n;
	B.set_numerator(n);
	cout << "¬ведите знаминатель второго числа: "; cin >> n;
	B.set_denominator(n);
	A.Print();
	B.Print();
	cout << B << " + " << A << " = " << (C = B + A) << endl;
	cout << B << " - " << A << " = " << B - A << endl;
	cout << C << " * " << A << " = " << C * A << endl;
	cout << B << " / " << A << " = " << B / A << endl;
	cout << A << " += " << B << " = " << (A += B) << endl;
	cout << A << " -= " << B << " = " << (A -= B) << endl;
	cout << A << " *= " << B << " = " << (A *= B) << endl;
	cout << A << " /= " << B << " = " << (A /= B) << endl;

	cout << A << " == " << B << " = " << (A == B) << endl;
	cout << A << " != " << B << " = " << (A != B) << endl;
	cout << A << " < " << B << " = " << (A < B) << endl;
	cout << A << " > " << B << " = " << (A > B) << endl;
	cout << A << " <= " << B << " = " << (A <= B) << endl;
	cout << A << " >= " << B << " = " << (A >= B) << endl;

	cout << A << " A++ = " << A++ << endl;
	cout << A << endl;
	cout << A << " ++A = " << ++A << endl;
	cout << A << endl;
	cout << A << " A-- = " << A-- << endl;
	cout << A << endl;
	cout << A << " --A = " << --A << endl;
	cout << A << endl;
#endif // CHECK_ALL

	Fraction A(-1, 3, 8);
	Fraction B(1, 1, 2);
	/*cout << A + B << endl;
	A.to_proper();
	cout << A << endl;
	A.to_improper();
	cout << A << endl;*/
	A.to_proper();
	B.to_proper();
	cout << A << endl;
	cout << B << endl;
	cout << A + B << endl;
	cout << A - B << endl;
	cout << A * B << endl;
	cout << A / B << endl;
}

Fraction operator+(Fraction left, Fraction right)
{
	Fraction Res;
	left.to_improper();
	right.to_improper();
	if (left.get_denominator() != right.get_denominator()) left.Adapting(right);
	if (left.get_minus() == false && right.get_minus() == true)
	{
		Res.set_numerator(right.get_numerator() - left.get_numerator());
		Res.set_denominator(left.get_denominator());
	}
	if (left.get_minus() == true && right.get_minus() == false)
	{
		Res.set_numerator(left.get_numerator() - right.get_numerator());
		Res.set_denominator(left.get_denominator());
	}
	else
	{
		Res.set_numerator(left.get_numerator() + right.get_numerator());
		Res.set_denominator(left.get_denominator());
	}
	if (Res.get_numerator() < 0)
	{
		Res.set_minus(true);
		Res.set_numerator(-Res.get_numerator());
	}
	else if (Res.get_numerator() >= 0)Res.set_minus(false);
	Res.Reduction();
	if (Res.get_numerator() > Res.get_denominator()) Res.to_proper();
	return Res;
}

Fraction operator-(Fraction left, Fraction right)
{
	Fraction Res;
	left.to_improper();
	right.to_improper();
	if (left.get_denominator() != right.get_denominator()) left.Adapting(right);
	if (left.get_minus() == false && right.get_minus() == true)
	{
		Res.set_numerator(right.get_numerator() + left.get_numerator());
		Res.set_denominator(left.get_denominator());
	}
	if (left.get_minus() == true && right.get_minus() == false)
	{
		Res.set_numerator(left.get_numerator() + right.get_numerator());
		Res.set_denominator(left.get_denominator());
		Res.set_minus(true);
	}
	if (left.get_minus() == true && right.get_minus() == true)
	{
		Res.set_numerator(right.get_numerator() - left.get_numerator());
		Res.set_denominator(left.get_denominator());
	}
	else if (left.get_minus() == false && right.get_minus() == false)
	{
		Res.set_numerator(left.get_numerator() - right.get_numerator());
		Res.set_denominator(left.get_denominator());
	}
	if (Res.get_numerator() < 0)
	{
		Res.set_minus(true);
		Res.set_numerator(-Res.get_numerator());
	}
	Res.Reduction();
	if (Res.get_numerator() > Res.get_denominator()) Res.to_proper();
	return Res;
}

Fraction operator*(Fraction left, Fraction right)
{
	Fraction Res;
	left.to_improper();
	right.to_improper();
	Res.set_numerator(left.get_numerator() * right.get_numerator());
	Res.set_denominator(left.get_denominator() * right.get_denominator());
	if (left.get_minus() == true || right.get_minus() == true) Res.set_minus(true);
	Res.Reduction();
	if (Res.get_numerator() > Res.get_denominator()) Res.to_proper();
	return Res;
}

Fraction operator/(Fraction left, Fraction right)
{
	Fraction Res;
	left.to_improper();
	right.to_improper();
	int Buff;
	Buff = right.get_numerator();
	right.set_numerator(right.get_denominator());
	right.set_denominator(Buff);
	Res.set_numerator(left.get_numerator() * right.get_numerator());
	Res.set_denominator(left.get_denominator() * right.get_denominator());
	if (left.get_minus() == true || right.get_minus() == true) Res.set_minus(true);
	Res.Reduction();
	if (Res.get_numerator() > Res.get_denominator()) Res.to_proper();
	return Res;
}

Fraction operator+=(Fraction& left, Fraction right)
{
	left = left + right;
	return left;
}

Fraction operator-=(Fraction& left, Fraction right)
{
	left = left - right;
	return left;
}

Fraction operator*=(Fraction& left, Fraction right)
{
	left = left * right;
	return left;
}

Fraction operator/=(Fraction& left, Fraction right)
{
	left = left / right;
	return left;
}

bool operator==(Fraction left, Fraction right)
{
	if (left.get_integer() != 0) left.to_improper();
	if (right.get_integer() != 0) right.to_improper();
	left.Reduction();
	right.Reduction();
	if (left.get_numerator() == right.get_numerator())
	{
		return(left.get_denominator() == right.get_denominator());
	}
	if (left.get_denominator() != right.get_denominator())
	{
		left.Adapting(right);
		return(left.get_numerator() == right.get_numerator());
	}
}

bool operator!=(Fraction left, Fraction right)
{
	if (left.get_integer() != 0) left.to_improper();
	if (right.get_integer() != 0) right.to_improper();
	left.Reduction();
	right.Reduction();
	if (left.get_numerator() == right.get_numerator())
	{
		return(left.get_denominator() != right.get_denominator());
	}
	if (left.get_denominator() != right.get_denominator())
	{
		left.Adapting(right);
		return(left.get_numerator() != right.get_numerator());
	}
}

bool operator>(Fraction left, Fraction right)
{
	if (left.get_integer() != 0) left.to_improper();
	if (right.get_integer() != 0) right.to_improper();
	left.Reduction();
	right.Reduction();
	if (left.get_numerator() == right.get_numerator())
	{
		return(left.get_denominator() <= right.get_denominator());
	}
	if (left.get_denominator() != right.get_denominator())
	{
		left.Adapting(right);
		return(left.get_numerator() > right.get_numerator());
	}
}

bool operator<(Fraction left, Fraction right)
{
	if (left.get_integer() != 0) left.to_improper();
	if (right.get_integer() != 0) right.to_improper();
	left.Reduction();
	right.Reduction();
	if (left.get_numerator() == right.get_numerator())
	{
		return(left.get_denominator() >= right.get_denominator());
	}
	if (left.get_denominator() != right.get_denominator())
	{
		left.Adapting(right);
		return(left.get_numerator() < right.get_numerator());
	}
}

bool operator>=(Fraction left, Fraction right)
{
	if (left.get_integer() != 0) left.to_improper();
	if (right.get_integer() != 0) right.to_improper();
	left.Reduction();
	right.Reduction();
	if (left.get_numerator() == right.get_numerator())
	{
		return(left.get_denominator() <= right.get_denominator());
	}
	if (left.get_denominator() != right.get_denominator())
	{
		left.Adapting(right);
		return(left.get_numerator() > right.get_numerator() || left.get_numerator() == right.get_numerator());
	}
}

bool operator<=(Fraction left, Fraction right)
{
	if (left.get_integer() != 0) left.to_improper();
	if (right.get_integer() != 0) right.to_improper();
	left.Reduction();
	right.Reduction();
	if (left.get_numerator() == right.get_numerator())
	{
		return(left.get_denominator() >= right.get_denominator());
	}
	if (left.get_denominator() != right.get_denominator())
	{
		left.Adapting(right);
		return(left.get_numerator() < right.get_numerator() || left.get_numerator() == right.get_numerator());
	}
}