#pragma once
#include<GL/freeglut.h>
#include<iostream>
#include"Vector.h"
#include "Matrix.h"
#include"Color.h"
#include"Light.h"
#include"Face.h"
#include<sstream>
#include<fstream>

class Mesh {
private:
	vector3D vertices[10000], originals[10000];
	Face face[10000], originalFace[10000];
	Ccolor color;
	int vertexCount = 0, faceCount = 0;
	double kd, ks, ka;
public:
	Mesh(double _kd = 0.7, double _ks = 0.7, double _ka = 0.7) {
		kd = _kd;
		ks = _ks;
		ka = _ka;
	}
	void ReadMesh(string fileName = "mesh.obj")
	{
		vertexCount = 0; faceCount = 0;
		string line;
		char c;
		double i, j, k;
		double x, y, z;
		string si, sj, sk;
		ifstream in(fileName);
		while (getline(in, line))
		{
			if (line.find_first_of("vVfF") == string::npos) continue;

			istringstream ss(line);
			ss >> c;
			switch (c)
			{
			case 'v':
			case 'V':
				ss >> x >> y >> z;
				vertices[vertexCount].set(x, y, z);
				originals[vertexCount].set(x, y, z);
				vertexCount++;
				break;

			case 'f':
			case 'F':
				ss >> si >> sj >> sk;
				i = stoi(si);  j = stoi(sj);  k = stoi(sk);
				face[faceCount].set(i - 1, j - 1, k - 1);
				originalFace[faceCount].set(i - 1, j - 1, k - 1);
				faceCount++;
				break;
			}
		}
		in.close();
	}
	void transform(Matrix& m)
	{
		for (int i = 0; i < vertexCount; i++)
		{
			vertices[i] = m * originals[i];
		}
	}
	void draw()
	{
		glBegin(GL_TRIANGLES);
		color.setRed(255);
		color.setGreen(255);
		color.setBlue(255);
		for (int i = 0; i < faceCount; i++)
		{
			glColor3f(color.getRed() / 255.0, color.getGreen() / 255.0, color.getBlue() / 255.0);
			glVertex3f(vertices[face[i].getA()].x(), vertices[face[i].getA()].y(), vertices[face[i].getA()].z());
			glVertex3f(vertices[face[i].getB()].x(), vertices[face[i].getB()].y(), vertices[face[i].getB()].z());
			glVertex3f(vertices[face[i].getC()].x(), vertices[face[i].getC()].y(), vertices[face[i].getC()].z());
		}
		glEnd();
	}
	void draw(Clight other)
	{
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < faceCount; i++)
		{
			Ccolor temp = ambient(other) + diffuse(vertices[face[i].getA()], vertices[face[i].getB()], vertices[face[i].getC()], other) + specular(vertices[face[i].getA()], vertices[face[i].getB()], vertices[face[i].getC()], other);
			glColor3f(temp.getRed() / 255.0, temp.getGreen() / 255.0, temp.getBlue() / 255.0);
			glVertex3f(vertices[face[i].getA()].x(), vertices[face[i].getA()].y(), vertices[face[i].getA()].z() * -1);
			glVertex3f(vertices[face[i].getB()].x(), vertices[face[i].getB()].y(), vertices[face[i].getB()].z() * -1);
			glVertex3f(vertices[face[i].getC()].x(), vertices[face[i].getC()].y(), vertices[face[i].getC()].z() * -1);
		}
		glEnd();
	}
	void draw1(Clight other)
	{
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < faceCount; i++)
		{
			Ccolor temp = ambient(other) + diffuse(vertices[face[i].getA()], vertices[face[i].getB()], vertices[face[i].getC()], other) + specular(vertices[face[i].getA()], vertices[face[i].getB()], vertices[face[i].getC()], other);
			glColor3f(temp.getRed() / 255.0, temp.getGreen() / 255.0, temp.getBlue() / 255.0);
			glVertex3f(vertices[face[i].getA()].x(), vertices[face[i].getA()].y(), vertices[face[i].getA()].z() * -1);
			glVertex3f(vertices[face[i].getB()].x(), vertices[face[i].getB()].y(), vertices[face[i].getB()].z() * -1);
			glVertex3f(vertices[face[i].getC()].x(), vertices[face[i].getC()].y(), vertices[face[i].getC()].z() * -1);
		}
		glEnd();
	}
	void draw(Clight other, vector3D *newVertex)
	{
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < faceCount; i++)
		{
			Ccolor temp = ambient(other) + diffuse(newVertex[face[i].getA()], newVertex[face[i].getB()], newVertex[face[i].getC()], other) + specular(newVertex[face[i].getA()], newVertex[face[i].getB()], newVertex[face[i].getC()], other);
			glColor3f(temp.getRed() / 255.0, temp.getGreen() / 255.0, temp.getBlue() / 255.0);
			glVertex3f(newVertex[face[i].getA()].x(), newVertex[face[i].getA()].y(), newVertex[face[i].getA()].z() * -1);
			glVertex3f(newVertex[face[i].getB()].x(), newVertex[face[i].getB()].y(), newVertex[face[i].getB()].z() * -1);
			glVertex3f(newVertex[face[i].getC()].x(), newVertex[face[i].getC()].y(), newVertex[face[i].getC()].z() * -1);
		}
		glEnd();
	}
	void setVertex(vector3D* newVertex) {
		for (int i = 0; i < vertexCount; i++) {
			vertices[i] = newVertex[i];
		} 
	}
	void setOriginalVertex(vector3D* newVertex) {
		for (int i = 0; i < vertexCount; i++) {
			originals[i] = newVertex[i];
		}
	}
	double getVertexCount() {
		return vertexCount;
	}
	vector3D getVertexIndex(int i) {
		return vertices[i];
	}
	vector3D getVertexOriginalIndex(int i) {
		return originals[i];
	}
	void setColour(Ccolor other) {
		color = other;
	}
	Ccolor ambient(Clight other) {
		Ccolor temp;
		temp = color * ka * other.getI();
		return temp;
	}
	Ccolor diffuse(vector3D a, vector3D b, vector3D c, Clight other) {
		vector3D v1 = b - a;
		vector3D v2 = c - a;
		vector3D normal = v1 * v2;
		normal = normal.unit();
		vector3D L = other.getPosition() - a;
		L = L.unit();
		double middle = normal ^ L;
		Ccolor temp;
		if (middle > 0) {
			temp = other.getColor() * middle * other.getI() * kd;
		}
		else {
			temp = other.getColor() * 0 * other.getI() * kd;
		}
		return temp;
	}
	Ccolor specular(vector3D a, vector3D b, vector3D c, Clight other) {
		vector3D eye(0, 0, 10);
		vector3D v1 = b - a;
		vector3D v2 = c - a;
		vector3D normal = v1 * v2;
		normal = normal.unit();
		vector3D L = other.getPosition() - a;
		L = L.unit();
		vector3D R = normal * 2 * (L ^ normal) - L;
		R = R.unit();
		vector3D v3 = eye - a;
		v3 = v3.unit();
		double middle = R ^ v3;
		Ccolor temp;
		if (middle > 0) {
			temp = other.getColor() * middle * ks * other.getI();
		}
		else {
			temp = other.getColor() * 0 * ks * other.getI();
		}
		return temp;
	}
	double getKa() {
		return ka;
	}
	double getKd() {
		return kd;
	}
	double getKs() {
		return ks;
	}
	void setKa(double _ka) {
		ka = _ka;
	}
	void setKd(double _kd) {
		kd = _kd;
	}
	void setKs(double _ks) {
		ks = _ks;
	}
};