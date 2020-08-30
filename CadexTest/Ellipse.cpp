#include "Ellipse.h"


Ellipse::Ellipse(double rX, double rY)
{
}

Point Ellipse::onCurveLocation(double t)
{
	return Point();
}

Point Ellipse::onCurveGradient(double t)
{
	return Point();
}

std::string Ellipse::toStrParametric()
{
	return std::string("(" + std::to_string(sqrt(par[0] / par[5])) + " * cos(t), " + std::to_string(sqrt(par[0] / par[4])) + " * sin(t) ) a=" + std::to_string(1/sqrt(par[5])) + " b=" + std::to_string(1/sqrt(par[4])) + " R=" + std::to_string(par[0]));
}