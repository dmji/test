#include "Curve.h"
#include <iostream>

double* doKof(Point** dotList, double func(double t), int size)
{
	double* result = new double[size];
	for (int i = 0; i < size; i++)
		result[i] = func(dotList[i]->y);
	return result;
};

double** doMatr(Point** dotList, double basis(double t, int bin) , int sizeX, int sizeY)
{
	double** result = new double* [sizeY];
	for (int i = 0; i < sizeY; i++)
		result[i] = new double[sizeX];
	for (int i = 0; i < sizeY; i++)
		for (int j = 0; j < sizeX; j++)
			result[i][j] = basis(dotList[i]->x, j);
	return result;
};

double* rref(double** matr, double* kof, int sizeX, int sizeY)
{
	/*
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
			std::cout << matr[i][j] << ' ';
		std::cout << kof[i] << ' ' << "\n";
	}
	*/
	for (int step = 0; step < sizeY; step++)
	{
		int temp_ind = -1;
		for (int ii = 0; ii < sizeX; ii++)
			if (matr[step][ii] != 0)
			{
				temp_ind = ii;
				break;
			}
		if (temp_ind == -1 && kof[step] != 0)
			return nullptr;

		double temp = matr[step][temp_ind];
		for (int j = 0; j < sizeX; j++)
			matr[step][j] = matr[step][j] / temp;
		kof[step] = kof[step] / temp;

		for (int k = 0; k < sizeY; k++)
			if (k != step)
			{
				temp = matr[k][temp_ind];
				for (int j = 0; j < sizeX; j++)
					matr[k][j] -= matr[step][j] * temp;
				kof[k] -= kof[step] * temp;
			}
	}

	double* result = new double[sizeX];
	for (int i = 0; i < sizeX; i++)
		for (int j = 0; j < sizeY; j++)
			if (matr[i][j] == 1)
				result[j] = kof[i];
	/*
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
			std::cout << matr[i][j] << ' ';
		std::cout << kof[i] << ' ' << result[i] << "\n";
	}
	*/
	return result;
};