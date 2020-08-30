#include "ImpAPI.h"

using namespace std;



string ImpAPI::fillRandomize(int arrSizeDef)
{
	int cirCounter = 0,
		ellCounter = 0,
		helCounter = 0;
	srand(time(NULL));
	if (vect.empty() == true) vect.push_back(vector<unique_ptr<Figure>>());
	for (int i = 0; i < arrSizeDef; i++)
		switch (rand() % 3)
		{
		case 0:
			vect[0].push_back(move(make_unique<Circle>(rand() % 100)));
			cirCounter++;
			break;
		case 1:
			vect[0].push_back(move(make_unique<Ellipse>(rand() % 100, rand() % 100)));
			ellCounter++;
			break;
		case 2:
			vect[0].push_back(move(make_unique<Helix>(rand() % 100, rand() % 100)));
			helCounter++;
			break;
		}

	if (cirCounter == 0) vect[0].push_back(move(make_unique<Circle>(rand() % 100)));
	if (ellCounter == 0) vect[0].push_back(move(make_unique<Ellipse>(rand() % 100, rand() % 100)));
	if (helCounter == 0) vect[0].push_back(move(make_unique<Helix>(rand() % 100, rand() % 100)));
	selectedVect = 0;
	return "OK";
};

string ImpAPI::getCurArrayString(double tPi)
{
	string result = "";
	if (vect.empty() != true)
	{
		int counter = 0;
		for (auto& a : vect[selectedVect])
		{
			result += "\tItem " + to_string(counter) + ": " + typeid(*a.get()).name();
			result += "\nCoordinate : " + a.get()->onCurveLocation(tPi).toStr();
			result += "\nDerivatives: " + a.get()->onCurveGradient(tPi).toStr() + '\n';
			counter++;
		}
	}
	return result;
};

std::string ImpAPI::detachFigure(int type)
{
	while (vect.size() < type + 1)	vect.push_back(vector<unique_ptr<Figure>>());
	selectedVect = type;
	if (vect[0].empty() != true)
	{
		int counter = 0;
		for (auto& a : vect[0])
			switch (type)
			{
			case 1:
				if (typeid(*a.get()) == typeid(Circle))
					vect[selectedVect].push_back(move(make_unique<Circle>(a.get()->getPar()[0])));
				break;
			case 2:
				if (typeid(*a.get()) == typeid(Ellipse))
					vect[selectedVect].push_back(move(make_unique<Ellipse>(a.get()->getPar()[0], a.get()->getPar()[1])));
				break;
			case 3:
				if (typeid(*a.get()) == typeid(Helix))
					vect[selectedVect].push_back(move(make_unique<Helix>(a.get()->getPar()[0], a.get()->getPar()[1])));
				break;
			default:
				break;
			}
	}
	else
		return "No value to detach";
	return "OK";
};


bool SRad(unique_ptr<Figure>& a, unique_ptr<Figure>& b)
{
	return (a.get()->getPar()[0] < b.get()->getPar()[0]);
};

std::string ImpAPI::sortByRad()
{
	sort(vect[selectedVect].begin(), vect[selectedVect].end(),SRad);
	return "OK";
};

std::string ImpAPI::selectArray(int type = 0)
{
	if (type < vect.capacity())
	{
		selectedVect = type;
		return "OK";
	}
	return "Not exist";
};

std::string ImpAPI::sumRadCircles()
{
	if(vect.size() < 2)	return "Not exist";
	if(vect[1].capacity() == 0)	return "Array is empty";
	
	double result = 0;
	for (auto& a : vect[1])
		result += a.get()->getPar()[0];
	return to_string(result);
};