#pragma once
#include<GL/freeglut.h>
#include"Vector.h"
#include"Matrix.h"

class Quadric
{
private:
	vector3D current[100][50], original[100][50];
	double vertRing, hortRing;
public:
	Quadric(double h = 50, double v = 25)
	{
		vertRing = v;
		hortRing = h;
	}
	void setValue(double h = 50, double v = 25) {
		vertRing = v;
		hortRing = h;
	}
	void setElips() {
		int r = 0, c = 0;
		double x, y, z;
		double sizeX = 50.0;
		double sizeY = 50.0;
		double sizeZ = 50.0;

		for (double u = -pi; u <= pi; u += pi / (hortRing / 2.0), r++)
		{
			c = 0;
			for (double v = -pi / 2.0; v <= pi / 2.0; v += pi / vertRing, c++)
			{
				x = sizeX * cos(v) * cos(u);
				y = sizeY * cos(v) * sin(u);
				z = sizeZ * sin(v);

				current[r][c].set(x, y, z);
				original[r][c].set(x, y, z);
			}
		}
	}
	void transform(Matrix& m)
	{
		for (int r = 0; r < hortRing; r++)
		{
			for (int c = 0; c < vertRing; c++)
			{
				current[r][c] = m * current[r][c];
			}
		}
	}

	void draw()
	{
		for (int r = 0; r < hortRing; r++)
		{
			glBegin(GL_LINES);
			for (int c = 1; c < vertRing - 1; c++) {
				glVertex3f(current[r][c].x(), current[r][c].y(), current[r][c].z());
				glVertex3f(current[r][c+1].x(), current[r][c+1].y(), current[r][c+1].z());
			}
			glEnd();
		}

		for (int c = 0; c < vertRing; c++)
		{
			glBegin(GL_LINE_LOOP);
			for (int r = 0; r < hortRing; r++) {
				glVertex3f(current[r][c].x(), current[r][c].y(), current[r][c].z());
				glVertex3f(current[r][c + 1].x(), current[r][c + 1].y(), current[r][c + 1].z());
			}
			glEnd();
		}
	}
};