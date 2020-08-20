#pragma once
#include "Curve.h"

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

Ellipse* buldEllipse(Point** dotList);

