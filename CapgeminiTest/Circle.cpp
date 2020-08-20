#include "Circle.h"

Circle::Circle(double r)
{
	par[5] = 1;
	par[4] = 1;
	par[0] = r * r;
}

Circle* buildCircle(Point** dotList)
{
	double temp = dotList[0]->x * dotList[0]->x + dotList[0]->y * dotList[0]->y;
	for(int i = 1; i < 3;i++)
		if(dotList[i]->x * dotList[i]->x + dotList[i]->y * dotList[i]->y != temp)
			return nullptr;
	return new Circle(sqrt(temp));
}