#include "Circle.h"

double Circle::df(double t)
{
	return (sqrt(par[0] / par[4]) * cos(t)) / ( sqrt(par[0] / par[5]) * (-sin(t)));
}

Circle::Circle(double r)
{
	par[5] = 1;
	par[4] = 1;
	par[0] = r * r;
}

Circle* buldCircle(Point** dotList)
{
	return nullptr;
}