#include "Circle.h"

Circle * buildCircle(Point* dotList)
{
	double temp = dotList[0].x * dotList[0].x + dotList[0].y * dotList[0].y;
	for(int i = 1; i < 3;i++)
		if(dotList[i].x * dotList[i].x + dotList[i].y * dotList[i].y != temp)
			return NULL;
	return new Circle(sqrt(temp));
}