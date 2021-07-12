#pragma once
#include <string>

class Point
{
public:
	double x;
	double y;
	std::string toStr()  
	{
		std::string X = std::to_string(x);
		std::string Y = std::to_string(y);
		std::string res = "(" + X + ", " + Y + ")";
		return res;
	};
	Point(double X = 0, double Y = 0) 
	{ x = X; y = Y; }
}; 
