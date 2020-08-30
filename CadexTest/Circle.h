#pragma once
#include "Figure.h"
class Circle :
	public Figure
{
protected:
	double radX = 0;
public:
	virtual std::vector<double> getPar() { std::vector<double> res = std::vector<double>(); res.push_back(radX); return res; };
	Circle(double r = 1) : radX(r) { if (r < 0) radX = 0; };
	virtual Point onCurveGradient(double t) { return Point(radX * (-sin(t)), radX * cos(t), 0); };
	virtual Point onCurveLocation(double t) { return Point(radX * cos(t), radX * sin(t), 0); };
	virtual std::string toStrParametric() {	return std::string("(" + std::to_string(radX) + " * cos(t), " + std::to_string(radX) + " * sin(t), 0)"); };
};