#pragma once
#include <string>

/// <summary>
/// Контейнер для хранения точки в пространстве
/// </summary>
class Point
{
public:
	double x=0;
	double y=0;
	double z=0;
	std::string toStr()  
	{
		return  "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
	};
	Point(double X = 0, double Y = 0, double Z = 0) : x(X), y(Y), z(Z) {};
	Point operator+(Point src) { return Point(x + src.x, y + src.y, z + src.z); };
}; 
