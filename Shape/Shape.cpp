// Shape.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Shape.h"

int main()
{
	Point p;
	Rectangle r;

	Point **ppPoints = new Point*[2];

	ppPoints[0] = &p;
	ppPoints[1] = &r;

	for (int i = 0; i < 2; i++)
	{
		ppPoints[i]->WhoAreYou();
	}

    return 0;
}

