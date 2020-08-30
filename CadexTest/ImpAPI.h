#pragma once
#include "Helix.h"
#include "Circle.h"
#include "Ellipse.h"
#include <string>
#include <iostream>
#include <time.h>
#include <algorithm> 
#include <vector>
class ImpAPI
{
protected:
	std::vector<std::vector<std::unique_ptr<Figure>>> vect = std::vector<std::vector<std::unique_ptr<Figure>>>();
	int selectedVect = 0;
	
public:
	std::string fillRandomize(int count = 10);
	std::string getCurArrayString(double tPi = atan(1));
	std::string detachFigure(int type);
	std::string sortByRad();
	std::string selectArray(int type);
	std::string sumRadCircles();
};

bool SRad(std::unique_ptr<Figure>& a, std::unique_ptr<Figure>& b);