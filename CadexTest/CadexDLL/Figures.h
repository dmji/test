#pragma once
#include "ENum.h"
#include <string>
#include <vector>

/// <summary>3D Point (x, y, z)</summary>
struct SPoint
{
	SPoint(double X = 0, double Y = 0, double Z = 0) : x(X), y(Y), z(Z) {};
	SPoint operator+(SPoint src) { return SPoint(x + src.x, y + src.y, z + src.z); };
	std::string toStr()	{ return  "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")"; };

	double x = 0;
	double y = 0;
	double z = 0;
};

/// <summary>Abstract interface for figures</summary>
class CFigure
{
public:
	virtual gm::EFigureType getType() = 0;
	virtual SPoint onCurveGradient(double t) = 0;
	virtual SPoint onCurveLocation(double t) = 0;
	virtual std::string toStrParametric() = 0;
	virtual bool operator<(CFigure* obj) { return true; };
};

/// <summary>Trivial circle with radius X</summary>
class CCircle: public CFigure
{
public:
	CCircle(double r = 1) : radX(r < 0 ? 0 : r) {};
	virtual gm::EFigureType getType() { return gm::eCircle; };
	virtual SPoint onCurveGradient(double t) { return SPoint(radX * (-sin(t)), radX * cos(t), 0); };
	virtual SPoint onCurveLocation(double t) { return SPoint(radX * cos(t), radX * sin(t), 0); };
	virtual std::string toStrParametric() { return std::string("(" + std::to_string(radX) + " * cos(t), " + std::to_string(radX) + " * sin(t), 0)"); };
	virtual bool operator<(CFigure* obj) { if(obj->getType() == getType()) { return radX < ((CCircle*)obj)->radX; } else return true; };
	double getRad() { return radX; }
protected:
	double radX = 0;
};

/// <summary>Trivial ellipse with radius X and Y</summary>
class CEllipse: public CCircle
{
public:
	CEllipse(double rX = 1, double rY = 1) : CCircle(rX), radY(rY < 0 ? 0 : rY) {};
	virtual gm::EFigureType getType() { return gm::eEllipse; };
	virtual SPoint onCurveGradient(double t) { return SPoint(radX * (-sin(t)), radY * cos(t), 0); };
	virtual SPoint onCurveLocation(double t) { return SPoint(radX * cos(t), radY * sin(t), 0); };
	virtual std::string toStrParametric() { return std::string("(" + std::to_string(radX) + " * cos(t), " + std::to_string(radY) + " * sin(t), 0)"); };
protected:
	double radY;
};

/// <summary>Trivial helix with radius X and step Z</summary>
class CHelix: public CCircle
{
public:
	CHelix(double r = 1, double stepZ = 1) : CCircle(r), step(stepZ < 0 ? 0 : stepZ) {};
	virtual gm::EFigureType getType() { return gm::eHelix; };
	virtual SPoint onCurveGradient(double t) { return CCircle::onCurveGradient(t) + SPoint(0, 0, t * step / (2 * gm::s_Pi)); };
	virtual SPoint onCurveLocation(double t) { return CCircle::onCurveLocation(t) + SPoint(0, 0, step / (2 * gm::s_Pi)); };
	virtual std::string toStrParametric() { return std::string("(" + std::to_string(radX) + " * cos(t), " + std::to_string(radX) + " * sin(t), t * step / (2*Pi) )"); };
protected:
	double step;
};