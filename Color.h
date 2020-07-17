#pragma once
class Ccolor
{
private:
	double _red, _green, _blue;
public:
	Ccolor(double red = 0, double green = 0, double blue = 0)
	{
		if (red >= 0 && red <= 255 && green >= 0 && green <= 255 && blue >= 0 && blue <= 255)
		{
			_red = red;
			_green = green;
			_blue = blue;
		}
	}
	double getRed()
	{
		return _red;
	}
	void setRed(double red)
	{
		if (red >= 0 && red <= 255)
		{
			_red = red;
		}
	}
	double getGreen()
	{
		return _green;
	}
	void setGreen(double green)
	{
		if (green >= 0 && green <= 255)
		{
			_green = green;
		}
	}
	double getBlue()
	{
		return _blue;
	}
	void setBlue(double blue)
	{
		if (blue >= 0 && blue <= 255)
		{
			_blue = blue;
		}
	}
	Ccolor operator + (Ccolor color)
	{
		if (_red + color.getRed() >= 0 && _red + color.getRed() <= 255 && _green + color.getGreen() >= 0 && _green + color.getGreen() <= 255 && _blue + color.getBlue() >= 0 && _blue + color.getBlue() <= 255)
		{
			Ccolor temp;
			temp.setRed(_red + color.getRed());
			temp.setGreen(_green + color.getGreen());
			temp.setBlue(_blue + color.getBlue());
			return temp;
		}
	}
	Ccolor operator - (Ccolor color)
	{
		if (_red - color.getRed() >= 0 && _red - color.getRed() <= 255 && _green - color.getGreen() >= 0 && _green - color.getGreen() <= 255 && _blue - color.getBlue() >= 0 && _blue - color.getBlue() <= 255)
		{
			Ccolor temp;
			temp.setRed(_red - color.getRed());
			temp.setGreen(_green - color.getGreen());
			temp.setBlue(_blue - color.getBlue());
			return temp;
		}
	}
	Ccolor operator * (double num)
	{
		if (_red * num >= 0 && _red * num <= 255 && _green * num >= 0 && _green * num <= 255 && _blue * num >= 0 && _blue * num <= 255)
		{
			Ccolor temp;
			temp.setRed(_red * num);
			temp.setGreen(_green * num);
			temp.setBlue(_blue * num);
			return temp;
		}
	}
};