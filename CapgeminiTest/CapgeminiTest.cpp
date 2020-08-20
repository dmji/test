#include "CapgeminiTest.h"

using namespace std;

int main()
{
	Point** dotList = new Point*[3];
	dotList[0] = new Point(-10, -10);
	dotList[1] = new Point(0, 0);
	dotList[2] = new Point(1, 10);

	

	int t = 3 * acos(0.0);
	cout << "\nELL DEBUG\n";
	Ellipse ell{};
	cout << ell.onCurvePoint(t).toStr() << '\n';
	cout << ell.findTangent(t).toStr();
	cout << "\nClosed: " << ell.isClosed();
	cout << '\n';
	cout << "\nPAR DEBUG\n";
	Parabola* par = buldParabola(dotList);
	if (par != nullptr)
	{
		cout << par->onCurvePoint(t).toStr() << '\n';
		cout << par->findTangent(t).toStr();
		cout << "\nClosed: " << par->isClosed();
		cout << '\n';
	}
	cout << "\nCIR DEBUG\n";
	Circle cir{};
	cout << cir.onCurvePoint(t).toStr() << '\n';
	cout << cir.findTangent(t).toStr();
	cout << "\nClosed: " << cir.isClosed();
	cout << '\n';
}