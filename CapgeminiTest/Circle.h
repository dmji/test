#pragma once
#include "Ellipse.h"

class Circle :
	public Ellipse
{
public:

	Circle(double r = 1)
	{
		par[5] = 1;
		par[4] = 1;
		par[0] = r * r;
	};
};

Circle *buildCircle(Point* dotList);