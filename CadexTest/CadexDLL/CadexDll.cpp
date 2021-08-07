#include "pch.h"
#include "CadexDll.h"
#include "Figures.h"
#include <iostream>
#include <time.h>
#include <algorithm> 
#include <iostream>
#include <vector>

using namespace std;
namespace gm
{
static std::vector<std::vector<std::shared_ptr<CFigure>>> s_aFigureVectors = std::vector<std::vector<std::shared_ptr<CFigure>>>();
static EFigureType s_selectedType = EFigureType::eAll;

void fillRandomize(const unsigned int nCountFigure, const unsigned int randomMax)
{
	srand(time(NULL));
	while(s_aFigureVectors.size() <= EFigureType::eCount)
		s_aFigureVectors.push_back(vector<shared_ptr<CFigure>>());
	for(int i = 0; i < EFigureType::eCount; i++)
	{
		if(!s_aFigureVectors[i].empty())
			s_aFigureVectors[i].clear();
	}
	int nCount = nCountFigure, checkForAll = 7;
	auto doCheck = [&checkForAll, &nCount](EFigureType cType)
	{
		if(checkForAll > 0)
		{
			int iType = cType - 1;
			auto dev = ((checkForAll >> iType) & 1) * pow(2, iType);
			checkForAll -= dev;
			if(dev != 0)
				nCount++;
		}
	};
	auto getRand = [&randomMax]() { return rand() % randomMax; };
	auto& mainVector = s_aFigureVectors[EFigureType::eAll];
	auto addCircle = [&mainVector, &getRand]() { return mainVector.push_back(std::shared_ptr<CFigure>(new CCircle(getRand()))); };
	auto addEllipse = [&mainVector, &getRand]() { return mainVector.push_back(std::shared_ptr<CFigure>(new CEllipse(getRand(), getRand()))); };
	auto addHelix = [&mainVector, &getRand]() { return mainVector.push_back(std::shared_ptr<CFigure>(new CHelix(getRand(), getRand()))); };
	for(int i=0;i<nCount - (eCount - 1);i++)
	{
		EFigureType t = EFigureType(1 + (rand() % (EFigureType::eCount - 1)));
		switch(t)
		{
		case EFigureType::eCircle: addCircle(); break;
		case EFigureType::eEllipse: addEllipse(); break;
		case EFigureType::eHelix: addHelix(); break;
		}
		doCheck(t);
	} 
	if(checkForAll != 0)
	{
		if(((checkForAll << (EFigureType::eCircle - 1)) & 1) == 0) addCircle();
		if(((checkForAll << (EFigureType::eEllipse - 1)) & 1) == 0) addEllipse();
		if(((checkForAll << (EFigureType::eHelix - 1)) & 1) == 0) addHelix();
	}
	s_selectedType = EFigureType::eAll;
};

string getCurArrayString(const double tPi)
{
	string result = "========== Array with ";
	switch(s_selectedType)
	{
	case eAll: result += "  All  "; break;
	case eCircle: result += " Circle "; break;
	case eEllipse: result += "Ellipse"; break;
	case eHelix: result += " Helix "; break;
	}
	result += " figures. ==========\n";
	if(!s_aFigureVectors.empty())
	{
		int counter = 1;
		for(auto& a : s_aFigureVectors[s_selectedType])
		{
			result += "\tItem " + to_string(counter) + ": " + typeid(*a.get()).name();
			result += "\nCoordinate : " + a.get()->onCurveLocation(tPi).toStr();
			result += "\nDerivatives: " + a.get()->onCurveGradient(tPi).toStr() + '\n';
			counter++;
		}
	}
	result += "==================================================\n";
	return result;
}

std::string sortCirclesByRad()
{
	auto comparer = [](shared_ptr<CFigure>&a, shared_ptr<CFigure>&b)
	{
		return a.get()->operator<(b.get());
	};

	auto& aCircle = s_aFigureVectors[EFigureType::eCircle];
	if(aCircle.empty())
		collectFigureByType(EFigureType::eCircle);
	sort(aCircle.begin(), aCircle.end(), comparer);
	return "OK";
};

bool selectArrayByType(EFigureType cType)
{
	if(cType < EFigureType::eCount && cType >= EFigureType::eAll)
	{
		s_selectedType = cType;
		return true;
	}
	return false;
};

std::string collectFigureByType(EFigureType cType)
{
	if(cType == eAll)
		return "Done";

	auto& aFigure = s_aFigureVectors[EFigureType::eAll];
	if(aFigure.empty())
		return "Main vector is empty";

	auto& aFigureTyped = s_aFigureVectors[cType];
	for(auto& a : aFigure)
	{
		if(a->getType() == cType)
			aFigureTyped.push_back(a);
	}
	return aFigureTyped.empty() ? "Zero figure with selected type" : "Done";
};

std::string sumRadCircles()
{

	double result = 0;
	for(auto& a : s_aFigureVectors[s_selectedType])
	{
		if(a->getType() == EFigureType::eCircle)
			result += ((CCircle*)(a.get()))->getRad();
	}
	return to_string(result);
}

;
};