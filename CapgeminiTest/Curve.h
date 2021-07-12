#pragma once
#include "Point.h"

class Curve
{
protected:
	virtual double df(double t) = 0;
	double par[6] = { 0,0,0,0,0,0 };								
public:
	virtual Point onCurvePoint(double t) = 0;
	virtual bool isClosed() = 0;
	virtual std::string toStrParametric() = 0;
	Point findTangent(double t)
	{
		double tan = df(t);
		if (tan == INFINITY)
			return Point(0, 1);
		else if (tan == -INFINITY)
			return Point(0, -1);

		Point res = Point(1 / (1 + tan * tan), tan / (1 + tan * tan));
		double norm = sqrt(res.x * res.x + res.y * res.y);
		res.x = res.x / norm;
		res.y = res.y / norm;
		return res;
	};
};

double** doMatr(Point* dotList,double basis(double t, int bin), int sizeX = 3, int sizeY = 3);
double* rref(double** matr, double* kof, int sizeX = 3, int sizeY = 3);
double* doKof(Point* dotList, double func(double t), int size = 3);