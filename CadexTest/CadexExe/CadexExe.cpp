#include <iostream>
#include "CadexDLL.h"

int main()
{
    gm::fillRandomize(10);
    std::cout << gm::getCurArrayString();
    gm::collectFigureByType(gm::eCircle);
    gm::selectArrayByType(gm::eCircle);
    gm::sortCirclesByRad();
    std :: cout << gm::getCurArrayString();
}