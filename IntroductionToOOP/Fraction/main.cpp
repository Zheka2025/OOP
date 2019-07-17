#include"Fraction.h"

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