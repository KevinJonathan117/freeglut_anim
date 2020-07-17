#pragma once
#include"Vector.h"

const double pi = 3.1428571428571;
double deg2rad(double deg)
{
	return deg * pi / 180.0;
}

class Matrix {
private:
	double data[4][4];
public:
	Matrix() {
		/*for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (i == j)
				{
					data[i][j] = 1;
				}
				else
				{
					data[i][j] = 0;
				}
			}
		}*/
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				data[i][j] = 0;
			}
		}
	}
	void create() {
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				data[i][j] = 0;
			}
		}
	}
	void setElement(int i, int j, int value)
	{
		data[i][j] = value;
	}
	void setIdentity()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (i == j)
				{
					data[i][j] = 1;
				}
				else
				{
					data[i][j] = 0;
				}
			}
		}
	}
	Matrix transpose() {
		Matrix temp;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				temp.setElement(i, j, data[j][i]);
			}
		}
		return temp;
	}
	Matrix operator * (Matrix m)
	{
		Matrix temp;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					temp.data[i][j] += data[i][k] * m.data[k][j];
				}
			}
		}
		return temp;
	}
	vector3D operator * (vector3D other)
	{
		vector3D temp;
		double x = 0, y = 0, z = 0, w = 0;

		x = data[0][0] * other.x() + data[0][1] * other.y() + data[0][2] * other.z() + data[0][3] * other.w();
		y = data[1][0] * other.x() + data[1][1] * other.y() + data[1][2] * other.z() + data[1][3] * other.w();
		z = data[2][0] * other.x() + data[2][1] * other.y() + data[2][2] * other.z() + data[2][3] * other.w();
		w = data[3][0] * other.x() + data[3][1] * other.y() + data[3][2] * other.z() + data[3][3] * other.w();

		temp.set(x, y, z, w);
		return temp;
	}
	void operator = (Matrix m)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				data[i][j] = m.data[i][j];
			}
		}
	}
	void translate(vector3D other)
	{
		//create();
		data[0][0] = 1;
		data[1][1] = 1;
		data[2][2] = 1;
		data[0][3] = other.x();
		data[1][3] = other.y();
		data[2][3] = other.z();
		data[3][3] = 1;
	}
	void translate(double x, double y, double z)
	{
		//create();
		data[0][0] = 1;
		data[1][1] = 1;
		data[2][2] = 1;
		data[0][3] = x;
		data[1][3] = y;
		data[2][3] = z;
		data[3][3] = 1;
	}
	void rotateX(double deg)
	{
		//create();
		data[0][0] = 1;
		data[1][1] = cos(deg2rad(deg));
		data[1][2] = sin(deg2rad(deg));
		data[2][1] = -sin(deg2rad(deg));
		data[2][2] = cos(deg2rad(deg));
		data[3][3] = 1;
	}
	void rotateY(double deg)
	{
		//create();
		data[0][0] = cos(deg2rad(deg));
		data[0][2] = -sin(deg2rad(deg));
		data[1][1] = 1;
		data[2][0] = sin(deg2rad(deg));
		data[2][2] = cos(deg2rad(deg));
		data[3][3] = 1;
	}
	void rotateZ(double deg)
	{
		//create();
		data[0][0] = cos(deg2rad(deg));
		data[0][1] = -sin(deg2rad(deg));
		data[1][0] = sin(deg2rad(deg));
		data[1][1] = cos(deg2rad(deg));
		data[2][2] = 1;
		data[3][3] = 1;
	}
	void scaling(double x, double y, double z)
	{
		//create();
		data[0][0] = x;
		data[1][1] = y;
		data[2][2] = z;
		data[3][3] = 1;
	}
	void scaling(vector3D other)
	{
		//create();
		data[0][0] = other.x();
		data[1][1] = other.y();
		data[2][2] = other.z();
		data[3][3] = 1;
	}
};
