#pragma once
#include "Curve.h"
/// <summary>
/// Класс для описания параболы, наследуемый от базового класса кривых
/// </summary>
class Parabola :
    public Curve
{
protected:
	double y(double t);
	/// <summary>
	/// Определение производной
	/// </summary>
	double df(double t);
public:
	/// <summary>
	/// Конструктор параболы вида y=a*x^2+b*x+c
	/// </summary> 
	Parabola(double a=1, double b=0, double c=0);
	/// <summary>
	/// Нахождение точки на функции с параметром
	/// </summary>
	/// <param name="t">Параметр</param>
	/// <returns>Контейнер содержащий искомую точку</returns>
	Point onCurvePoint(double t);
	/// <summary>
	/// Вывод строки с параметрическим видом функции
	/// </summary>
	/// <returns>Строка вида (x(t), y(t))</returns>
	std::string toStrParametric();
	/// <summary>
	/// Вывод информации о замкнутости функции
	/// </summary>
	/// <returns>0 - если не замкнута, 1 - замкнута</returns>
	bool isClosed();
};
/// <summary>
/// Построение параболы по трем точкам
/// </summary>
/// <param name="dotList">Список точек</param>
/// <returns>Экземляр класса парабол если возможно построить и nullptr в обратном случае</returns>
Parabola* buildParabola(Point** dotList);
/// <summary>
/// Вспомогательная функция для создания параметра в метода Гаусса
/// </summary>
double basisParabola(double t, int bin);

/// <summary>
/// Вспомогательная функция для создания параметра в метода Гаусса
/// </summary>
double yParabola(double t);