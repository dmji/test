#pragma once
#include "Circle.h"
class Ellipse :
    public Circle
{
protected:
	double radY;
public:
	virtual std::vector<double> getPar() { std::vector<double> res = std::vector<double>(); res.push_back(radX); res.push_back(radY); return res; };
	Ellipse(double rX = 1, double rY = 1) : Circle(rX), radY(rY) { if (rY < 0) radY = 0; };
	virtual Point onCurveGradient(double t) { return Point(radX * (-sin(t)), radY * cos(t), 0); };
	virtual Point onCurveLocation(double t) { return Point(radX * cos(t), radY * sin(t), 0); };
	virtual std::string toStrParametric() { return std::string("(" + std::to_string(radX) + " * cos(t), " + std::to_string(radY) + " * sin(t), 0)"); };
};