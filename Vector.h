#pragma once
#include<iostream>
using namespace std;

class vector2D
{
protected:
	double _x, _y;

public:
	vector2D(double x = 0, double y = 0)
	{
		_x = x;
		_y = y;
	}
	double operator ^ (vector2D v) //dot product
	{
		double hasil;

		hasil = _x * v._x + _y * v._y;
		return hasil;
	}
	vector2D operator * (double bil) //scalar multiplier
	{
		vector2D temp;

		temp._x = _x * bil;
		temp._y = _y * bil;

		return temp;
	}

	vector2D operator + (vector2D v) //addition
	{
		vector2D temp;

		temp._x = _x + v._x;
		temp._y = _y + v._y;

		return temp;
	}
	vector2D operator - (vector2D v) //subtraction
	{
		vector2D temp;

		temp._x = _x - v._x;
		temp._y = _y - v._y;
	}
	vector2D operator / (double bil) // scalar multiplier
	{
		vector2D temp;
		temp._x = _x / bil;
		temp._y = _y / bil;

		return temp;
	}
	double magnitude() //length calculation
	{
		double hasil;

		hasil = sqrt(_x * _x + _y * _y);

		return hasil;
	}
	vector2D unit() //vector with length of 1
	{
		double mag = magnitude();

		vector2D temp;
		temp._x = _x / mag;
		temp._y = _y / mag;

		return temp;
	}

	double y()
	{
		return _y;
	}

	double x()
	{
		return _x;
	}
};

class vector3D : public vector2D
{
	double _z, _w;

public:

	vector3D(double x = 0, double y = 0, double z = 0, double w = 1) :vector2D(x, y)
	{
		_z = z;
		_w = w;
	}

	void set(double x, double y, double z = 0, double w = 1)
	{
		_x = x;
		_y = y;
		_z = z;
		_w = w;
	}
	double operator ^ (vector3D v)
	{
		double hasil;
		hasil = _x * v._x + _y * v._y + _z * v._z;

		return hasil;
	}
	vector3D operator * (double bil)
	{
		vector3D temp;
		temp._x = _x * bil;
		temp._y = _y * bil;
		temp._z = _z * bil;

		return temp;
	}
	vector3D operator * (vector3D v)
	{
		vector3D temp;
		temp._x = _y * v._z - v._y * _z;
		temp._y = _z * v._x - v._z * _x;
		temp._z = _x * v._y - v._x * _y;

		return temp;
	}
	vector3D operator + (vector3D v)
	{
		vector3D temp;
		temp._x = _x + v._x;
		temp._y = _y + v._y;
		temp._z = _z + v._z;

		return temp;
	}
	vector3D operator - (vector3D v)
	{
		vector3D temp;
		temp._x = _x - v._x;
		temp._y = _y - v._y;
		temp._z = _z - v._z;

		return temp;
	}
	vector3D operator / (double bil)
	{
		vector3D temp;
		temp._x = _x / bil;
		temp._y = _y / bil;
		temp._z = _z / bil;

		return temp;
	}
	void operator = (const vector3D& v)
	{
		_x = v._x;
		_y = v._y;
		_z = v._z;
		_w = v._w;
	}
	double magnitude()
	{
		double hasil;

		hasil = sqrt(_x * _x + _y * _y + _z * _z);

		return hasil;
	}
	vector3D unit()
	{
		double mag = magnitude();

		vector3D temp;
		temp._x = _x / mag;
		temp._y = _y / mag;
		temp._z = _z / mag;

		return temp;
	}

	double z()
	{
		return _z;
	}
	double w()
	{
		return _w;
	}
	void display()
	{
		cout << _x << "x " << _y << "y " << _z << "z\n";
	}
};