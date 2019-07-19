#include<iostream>
using namespace std;


class Point
{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		if (x >= -100 && x <= 100)
		{
			this->x = x;
		}
		else
		{
			throw exception("Bad x");
		}
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//   Construktors 
	/*Point()
	{
		x = y = 0;
		cout << "Constructor: " << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor: " << this << endl;
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
	}

	~Point()
	{
		cout << "Destructor " << this << endl;
	}

	// Operators:

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	double distance(Point other)
	{
		/*double result_x = this->x-other.x;
		double result_y = this->y-other.y;/
		return sqrt(result_x*result_x + result_y*result_y);*/
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}

	void Print()
	{
		cout << "x = " << x << "\ty = " << y << endl;
	}
};

class Point3D :public Point
{
	double z;
public:
	double get_z()const
	{
		return z;
	}
	void set_z(double z)
	{
		this->z = z;
	}
	 
	double distans3d(Point3D other)
	{
		return sqrt(pow(this->get_x() - other.get_x(), 2) + pow(this->get_y() - other.get_y(), 2) + pow(this->z - other.z, 2));
	}

};

double Distance(Point A, Point B);
double Distans3D(Point3D A, Point3D B);

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

double Distance(Point A, Point B)
{
	double a;
	double b;
	cout << "Укажите координаты точки \"А\": "; cin >> a; cin >> b;
	A.set_x(a);
	A.set_y(b);
	cout << "Укажите координаты точки \"B\": "; cin >> a; cin >> b;
	B.set_x(a);
	B.set_y(b);
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
}

double Distans3D(Point3D A, Point3D B)
{
	double a;
	double b;
	double c;
	cout << "Укажите координаты точки \"А\": "; cin >> a; cin >> b; cin >> c;
	A.set_x(a);
	A.set_y(b);
	A.set_z(c);
	cout << "Укажите координаты точки \"B\": "; cin >> a; cin >> b; cin >> c;
	B.set_x(a);
	B.set_y(b);
	B.set_z(c);
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2) + pow(A.get_z() - B.get_z(), 2));
}