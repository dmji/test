#pragma once
#include <string>
#include "ENum.h"

#ifdef GEOMETRYLIBRARY_EXPORTS
#define GEOMETRYIBRARY_API __declspec(dllexport)
#else
#define GEOMETRYLIBRARY_API __declspec(dllimport)
#endif

namespace gm
{
static double s_Pi = 3.14159265359;

/// <summary></summary>
/// <param name="nCount">Count of figure</param>
/// <param name="randomMax"></param>
/// <returns></returns>
extern "C++" GEOMETRYLIBRARY_API void fillRandomize(
	const unsigned int nCount = 3, const unsigned int randomMax = 100);

extern "C++" GEOMETRYLIBRARY_API std::string getCurArrayString(
	const double tPi = s_Pi / 4);

extern "C++" GEOMETRYLIBRARY_API std::string collectFigureByType(
	EFigureType cType);

extern "C++" GEOMETRYLIBRARY_API bool selectArrayByType(
	EFigureType cType);

extern "C++" GEOMETRYLIBRARY_API std::string sortCirclesByRad();


extern "C++" GEOMETRYLIBRARY_API std::string sumRadCircles();

};