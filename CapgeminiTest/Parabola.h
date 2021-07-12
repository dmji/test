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
	double df(double t);
public:
	Parabola(double a=1, double b=0, double c=0);
	Point onCurvePoint(double t);
	std::string toStrParametric();
	bool isClosed();
};

Parabola* buildParabola(Point* dotList);
double basisParabola(double t, int bin);
double yParabola(double t);