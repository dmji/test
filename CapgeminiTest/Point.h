#pragma once
#include <string>

class Point					//	Container for storing points on a plane
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
	Point() { x = 0; y = 0; }
	Point(double X, double Y) { x = X; y = Y; } //	Constructor
}; 
