#pragma once
#include "Point.h"
/// <summary>
/// Базовый абстрактный класс
/// </summary>
class Curve
{
protected:
	/// <summary>
	/// Интерфейс для определения производной
	/// </summary>
	virtual double df(double t) = 0;
	/// <summary>
	/// Базовая кривая имеет вид: par[5] * x^2 + par[4] * y^2 + 2 * par[3] * x * y + 2 * par[2] * x + 2 * par[1] * y + par[0] = 0, par[5]!=0 || par[4]!=0 || par[3]!=0								
	/// </summary>
	double par[6] = { 0,0,0,0,0,0 };								
public:
	/// <summary>
	/// Интерфейс для нахождения точки на функции с параметром
	/// </summary>
	/// <param name="t">Параметр</param>
	/// <returns>Контейнер содержащий искомую точку</returns>
	virtual Point onCurvePoint(double t) = 0;
	/// <summary>
	/// Интерфейс для определения замкнутости функции
	/// </summary>
	/// <returns>0 если не замкнуто, 1 если замкнута</returns>
	virtual bool isClosed() = 0;
	/// <summary>
	/// Интерфейс для вывода строки с параметрическим видом функции
	/// </summary>
	/// <returns>Строка вида (x(t), y(t))</returns>
	virtual std::string toStrParametric() = 0;
	/// <summary>
	/// Нахождение касательного вектора к кривой в точке с параметром t
	/// </summary>
	/// <param name="t">Параметр</param>
	/// <returns>Контейнер, содержащий информацию о направлении касательного вектора относительно заданной точки</returns>
	Point findTangent(double t)
	{
		double tan = df(t);
		if (tan == INFINITY)
			return Point(0, 1);
		else if (tan == -INFINITY)
			return Point(0, -1);

		return Point(1 / (1 + tan * tan), tan / (1 + tan * tan));
	};
};
/// <summary>
/// Вспомогательная функция для построения функции по точкам
/// </summary>
/// <param name="dotList">Список точек</param>
/// <param name="basis">Функция, возвращающая значение базисного элемента при некотором параметре</param>
/// <param name="sizeX">Количество базисных элементов</param>
/// <param name="sizeY">Кличество точек</param>
/// <returns>Матрица</returns>
double** doMatr(Point** dotList,double basis(double t, int bin), int sizeX = 3, int sizeY = 3);

/// <summary>
/// Вспомогательная функция для построения функции по точкам, реализует метода Гаусса для решения СЛАУ
/// </summary>
/// <param name="matr">Матрица построенная функцией doMatr</param>
/// <param name="kof">Правая часть коэффицентов метода Гаусса, построенная doKof</param>
/// <param name="sizeX">Количество базисных элементов</param>
/// <param name="sizeY">Кличество точек</param>
/// <returns>Коэффиценты для построения кривой</returns>
double* rref(double** matr, double* kof, int sizeX = 3, int sizeY = 3);

/// <summary>
/// Вспомогательная функция для построения функции по точкам
/// </summary>
/// <param name="dotList">Список точек</param>
/// <param name="func">Функция, возвращающее значение y(или y^2) в функции</param>
/// <param name="size">Кличество точек</param>
/// <returns>Коэффиценты для построения кривой</returns>
double* doKof(Point** dotList, double func(double t), int size = 3);