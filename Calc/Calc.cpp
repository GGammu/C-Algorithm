// Calc.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	String strInfix1 = "(12+(34*56))";
	String strInfix2 = "(2*(3+6/2)+2)/4+3";

	String strReturn = cal.ToPostfix1(strInfix1);
	printf("%s\n", (const char*)strReturn);

	strReturn = cal.ToPostfix2(strInfix2);
	printf("%s\n", (const char*)strReturn);

	long n = cal.CalcPostfix(strReturn);
	printf("%d\n", n);

	n = cal.CalcInfix(strInfix2);
	printf("%d\n", n);

	char a;
	a = getchar();

    return 0;
}