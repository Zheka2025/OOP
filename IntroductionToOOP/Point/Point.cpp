#include"Point.h"
double Point::get_x() const
{
	return x;
}
double Point::get_y() const
{
	return y;
}
void Point::set_x(double x)
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
void Point::set_y(double y)
{
	this->y = y;
}

//   Construktors 
Point::Point(double x = 0, double y = 0)
{
	this->x = x;
	this->y = y;
	cout << "Constructor: " << this << endl;
}

Point::Point(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyConstructor: " << this << endl;
}

Point::~Point()
{
	cout << "Destructor " << this << endl;
}

// Operators:

Point& Point::operator=(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

double Point::distance(Point other)
{
	/*double result_x = this->x-other.x;
	double result_y = this->y-other.y;/
	return sqrt(result_x*result_x + result_y*result_y);*/
	return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
}

void Point::Print()
{
	cout << "x = " << x << "\ty = " << y << endl;
}


double Point3D::get_z()const
{
	return z;
}
void Point3D::set_z(double z)
{
	this->z = z;
}

double Point3D::distans3d(Point3D other)
{
	return sqrt(pow(this->get_x() - other.get_x(), 2) + pow(this->get_y() - other.get_y(), 2) + pow(this->z - other.z, 2));
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