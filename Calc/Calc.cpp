// Calc.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Calculator.h"
#include "../StringCls/AString.h"
#include "../StringCls/AString.cpp"

#pragma warning(disable:4996)

using namespace cppalgo;

int main()
{
	Calculator cal;
	String strInfix1 = "(2*(3+6/2)+2)/4+3";

	String strReturn = cal.ToPostfix2(strInfix1);
	printf("%s\n", (const char*)strReturn);

	char a;
	a = getchar();

    return 0;
}