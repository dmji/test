#pragma once
#include "Ellipse.h"
/// <summary>
/// Класс для описания , наследуемый от класса эллипса
/// </summary>
class Circle :
    public Ellipse
{
public:
	/// <summary>
	/// Конструктор эллипса вида x^2 + y^2 = r^2
	/// </summary> 
	Circle(double r=1);
};
/// <summary>
/// Построение параболы по трем точкам
/// </summary>
/// <param name="dotList">Список точек</param>
/// <returns>Экземляр класса окружностей если возможно построить и nullptr в обратном случае</returns>
Circle* buildCircle(Point** dotList);