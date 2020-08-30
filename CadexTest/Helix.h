#pragma once
#include "Circle.h"
class Helix :
	public Circle
{
protected:
	double step;
public:
	virtual std::vector<double> getPar() { std::vector<double> res = std::vector<double>(); res.push_back(radX); res.push_back(step); return res; };
	Helix(double r = 1, double stepZ = 1) : Circle(r), step(stepZ) 
	{ 
		if (r < 0) radX = 0; 
		if (stepZ < 0) step = 0; 
	};
	virtual Point onCurveGradient(double t) { return dynamic_cast<Circle*>(this)->onCurveLocation(t) + Point(0,0, t * step / (2*atan(1) * 4)); };
	virtual Point onCurveLocation(double t) { return Point(radX * cos(t), radX * sin(t), 1); };
	virtual std::string toStrParametric() { return std::string("(" + std::to_string(radX) + " * cos(t), " + std::to_string(radX) + " * sin(t), t * step / (2*Pi) )"); };
};