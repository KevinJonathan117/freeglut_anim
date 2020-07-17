#pragma once
#include"Color.h"
#include"Vector.h"
class Clight
{
private:
	vector3D position;
	Ccolor color;
	double I;
public:
	Clight(vector3D _position, Ccolor _color, double _I)
	{
		position = _position;
		color = _color;
		I = _I;
	}
	vector3D getPosition()
	{
		return position;
	}
	void setPosition(vector3D _position)
	{
		position = _position;
	}
	Ccolor getColor()
	{
		return color;
	}
	void setColor(Ccolor _color)
	{
		color = _color;
	}
	double getI()
	{
		return I;
	}
};