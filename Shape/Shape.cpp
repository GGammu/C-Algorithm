// Shape.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

