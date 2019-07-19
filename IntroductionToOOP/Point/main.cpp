#include"Point.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	/*double a;
	double b;
	double c;
	Point3D A;
	Point3D B;
	A.set_x(2);
	A.set_y(3);
	A.set_z(4);
	B.set_x(2);
	B.set_y(4);
	B.set_z(3);*/
	//cout << A.get_x() << "\t" << A.get_y() << endl;	
	//Point* pA = &A;
	//cout << pA->get_x() << "\t" << pA->get_y() << endl;
	//cout << (*pA).get_x() << "\t" << (*pA).get_y() << endl;

	//Point3D B;
	/*cout << "Введите координаты точки:"; cin >> a; cin >> b; cin >> c;
	B.set_x(a);
	B.set_y(b);
	B.set_z(c);
	cout << "Расстояне до точки - " <<A.distans3d(B) << endl;
	double result = Distans3D(A, B);
	if (result < 0) result *= -1;
	cout << "Расстояние между точками: " << result << endl;
	A.Print();*/
	
	Point A; // default constructor
	Point B(2, 3);
	Point C = 5;
	//Point D = B;
	A.Print();
	B.Print();
	//C.Print();
	////D.Print();
	//cout << A.distance(C) << endl;
	//cout << Distance(B, C);
	B = A;
	A.Print();
	B.Print();
	/*cout << C.distance(D) << endl;
	cout << B.distance(D) << endl;
	cout << B.distance(C) << endl;*/
}