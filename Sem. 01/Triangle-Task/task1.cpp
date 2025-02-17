﻿#include "pch.h"
#include "Triangle.h"
#include "swap.h"

#include <iostream>

double getDist(const Point&, const Point&);

double Area(const Triangle&);

void calculateAreas(const Triangle*, double*, size_t);

void selectionSort(Triangle*, double*, size_t);

int main()
{
	int N;
	std::cin >> N;

	Triangle* triangles = new Triangle[N];
	readTriangles(triangles, N);

	double *areas = new double[N];
	calculateAreas(triangles, areas, N);

	selectionSort(triangles, areas, N);

	print(triangles,N);

	delete[] triangles;
	delete[] areas;
}

double getDist(const Point& f, const Point& s)
{
	double dx = f.x - s.x;
	double dy = f.y - s.y;

	return sqrt(dx * dx + dy * dy);
}

double Area(const Triangle& t)
{
	double sideA = getDist(t.B, t.C);
	double sideB = getDist(t.A, t.C);
	double sideC = getDist(t.A, t.B);

	double p = (sideA + sideB + sideC) / 2;

	return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}

void calculateAreas(const Triangle* ts, double* areas, size_t size)
{
	for (size_t i = 0; i < size; i++)
		areas[i] = Area(ts[i]);
}

void selectionSort(Triangle* ts, double* areas, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		size_t min_i = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (areas[j] < areas[min_i])
				min_i = j;
		}

		if (min_i != i)
		{
			swap(areas[min_i], areas[i]);
			swap(ts[min_i], ts[i]);
		}
	}
}
