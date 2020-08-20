#include "Ellipse.h"

double Ellipse::df(double t)
{
	return (sqrt(par[0] / par[4]) * cos(t)) / ( sqrt(par[0] / par[5]) * (-sin(t)));
}

Ellipse::Ellipse(double a, double b, double r)
{
	par[5] = 1/(a*a);
	par[4] = 1/(b*b);
	par[0] = r*r;
}

Point Ellipse::onCurvePoint(double t)
{
	return Point(sqrt(par[0] / par[5]) * cos(t), sqrt(par[0] / par[4]) * sin(t));
}

std::string Ellipse::toStrParametric()
{
	return std::string("(" + std::to_string(sqrt(par[5] / par[0])) + " * cos(t), " + std::to_string(sqrt(par[4] / par[0])) + " * sin(t) )");
}

bool Ellipse::isClosed()
{
	return true;
}

Ellipse* buldEllipse(Point** dotList)
{
	return nullptr;
}