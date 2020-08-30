#pragma once
#include "Point.h"
#include <vector>
class Figure
{
public:
	virtual std::vector<double> getPar() = 0;
	virtual Point onCurveGradient(double t) = 0;
	virtual Point onCurveLocation(double t) = 0;
	virtual std::string toStrParametric() = 0;
};