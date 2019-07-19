#pragma once
#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x() const;
	double get_y() const;
	void set_x(double x);
	void set_y(double y);

	//   Construktors 
	Point(double x = 0, double y = 0);

	Point(const Point& other);
	~Point();

	// Operators:

	Point& operator=(const Point& other);

	double distance(Point other);

	void Print();
};

class Point3D :public Point
{
	double z;
public:
	double get_z()const;
	void set_z(double z);
	double distans3d(Point3D other);
};

double Distance(Point A, Point B);
double Distans3D(Point3D A, Point3D B);