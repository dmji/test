#pragma once
#include "Curve.h"
/// <summary>
/// Класс для описания эллипса, наследуемый от базового класса кривых
/// </summary>
class Ellipse :
    public Curve
{
protected:
	double df(double t);
public:
	Ellipse(double a=1, double b=1, double r=1);
	Point onCurvePoint(double t);
	std::string toStrParametric();
	bool isClosed();
};

Ellipse* buildEllipse(Point* dotList);
double basisEllipse(double t, int bin);
double yEllipse(double t);
