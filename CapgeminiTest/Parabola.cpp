#include "Parabola.h"

double Parabola::y(double t)
{
	return par[5] * t * t + par[2] * t + par[0];
}

double Parabola::df(double t)
{
	return 2 * par[5] * t + par[2];
}

Parabola::Parabola(double a, double b, double c)
{
	par[1] = 1 / 2;
	par[5] = a;
	par[2] = b;
	par[0] = c;
}

Point Parabola::onCurvePoint(double t)
{
	return Point(t, y(t));
}

std::string Parabola::toStrParametric()
{
	std::string checked = "";
	if (par[2] != 0)
		checked += " + " + std::to_string(par[2]) + " * t";
	if(par[0] != 0)
		checked += " + " + std::to_string(par[0]);
	return std::string("(t, " + std::to_string(par[5]) + " * t^2" + checked + ")");
}

bool Parabola::isClosed()
{
	return false;
}

Parabola * buildParabola(Point** dotList)
{
	double * kof = rref(doMatr(dotList, basisParabola), doKof(dotList, yParabola));
	if (kof == nullptr)
	{
		delete[] kof;
		return NULL;
	}
	Parabola * result = new  Parabola(kof[0], kof[1], kof[2]);
	delete[] kof;
	return result;
}

double basisParabola(double t, int bin)
{
	switch (bin)
	{
	case 1:
		return t;
		break;
	case 0:
		return t * t;
		break;
	default:
		return 1;
		break;
	}
}

double yParabola(double t)
{
	return t;
}