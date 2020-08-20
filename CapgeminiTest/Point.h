#pragma once
#include <string>

/// <summary>
/// Контейнер для хранения точки на плоскости
/// </summary>
class Point
{
public:
	double x;
	double y;
	/// <summary>
	/// Генерирует информацию о точке
	/// </summary>
	/// <returns>Строка вида (x,y)</returns>
	std::string toStr()  
	{
		std::string X = std::to_string(x);
		std::string Y = std::to_string(y);
		std::string res = "(" + X + ", " + Y + ")";
		return res;
	};
	/// <summary>
	/// Сконструировать точку с заданными координатами
	/// </summary>
	/// <param name="X">Координата на оси абцисс</param>
	/// <param name="Y">Координата на оси ординат</param>
	Point(double X = 0, double Y = 0) 
	{ x = X; y = Y; }
}; 
