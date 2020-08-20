#pragma once
#include "Ellipse.h"

class Circle :
    public Ellipse
{
protected:
	double df(double t);
public:
	Circle(double r=1);
};

Circle* buldCircle(Point** dotList);

