#pragma once
#include "Curve.h"
/// <summary>
/// Класс для описания эллипса, наследуемый от базового класса кривых
/// </summary>
class Ellipse :
    public Curve
{
protected:
	/// <summary>
	/// Интерфейс для определения производной
	/// </summary>
	double df(double t);
public:
	/// <summary>
	/// Конструктор эллипса вида x^2 / a^2 + y^2 / b^2 = r^2
	/// </summary> 
	Ellipse(double a=1, double b=1, double r=1);
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
/// <returns>Экземляр класса эллипса если возможно построить и nullptr в обратном случае</returns>
Ellipse* buildEllipse(Point** dotList);
/// <summary>
/// Вспомогательная функция для создания параметра в метода Гаусса
/// </summary>
double basisEllipse(double t, int bin);
/// <summary>
/// Вспомогательная функция для создания параметра в метода Гаусса
/// </summary>
double yEllipse(double t);
