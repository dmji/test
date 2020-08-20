#include "Parabola.h"

/// <summary>
/// 
/// </summary>
/// <param name="t"></param>
/// <returns></returns>
double Parabola::y(double t)
{
	return par[5] * t * t + par[2] * t + par[0];
}

/// <summary>
/// 
/// </summary>
/// <param name="t"></param>
/// <returns></returns>
double Parabola::df(double t)
{
	return 2 * par[5] * t + par[2];
}

/// <summary>
/// 
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
Parabola::Parabola(double a, double b, double c)
{
	par[5] = a;
	par[2] = b;
	par[0] = c;
}

/// <summary>
/// 
/// </summary>
/// <param name="t"></param>
/// <returns></returns>
Point Parabola::onCurvePoint(double t)
{
	return Point(t, y(t));
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
std::string Parabola::toStrParametric()
{
	std::string checked = "";
	if (par[2] != 0)
		checked += " + " + std::to_string(par[2]) + " * t";
	if(par[0] != 0)
		checked += " + " + std::to_string(par[0]);
	return std::string("(t, " + std::to_string(par[5]) + " * t^2" + checked + ")");
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
bool Parabola::isClosed()
{
	return false;
}

/// <summary>
/// 
/// </summary>
/// <param name="dotList"></param>
/// <returns></returns>
Parabola* buldParabola(Point** dotList)
{
	double * kof = rref(doMatr(dotList, basisParabola), doKof(dotList));
	if (kof == nullptr)
		return nullptr;
	Parabola* result = new Parabola(kof[0], kof[1], kof[2]);
	return result;
}

/// <summary>
/// 
/// </summary>
/// <param name="t"></param>
/// <param name="bin"></param>
/// <returns></returns>
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