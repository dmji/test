#pragma once
#include "Point.h"

class Curve										// base class
{
protected:
	virtual double df(double t) = 0;
	double par[6] = { 0,0,0,0,0,0 };								// base curve is par[5] * x^2 + par[4] * y^2 + 2 * par[3] * x * y + 2 * par[2] * x + 2 * par[1] * y + par[0] = 0, par[5]!=0 || par[4]!=0 || par[3]!=0								
public:
	virtual Point onCurvePoint(double t) = 0;	// pure virtual method [testtask1]
	virtual bool isClosed() = 0;				// pure virtual method [testtask3]
	virtual std::string toStrParametric() = 0;			// pure virtual method [testtask3]
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
/// Вспомогательная функция для построения по точкам
/// </summary>
/// <param name="dotList"></param>
/// <param name="basPar"></param>
/// <param name="sizeX"></param>
/// <param name="sizeY"></param>
/// <returns></returns>
double** doMatr(Point** dotList,double basPar(double t, int bin), int sizeX = 3, int sizeY = 3);
double* rref(double** matr, double* kof, int sizeX = 3, int sizeY = 3);
double* doKof(Point** dotList, int size = 3);