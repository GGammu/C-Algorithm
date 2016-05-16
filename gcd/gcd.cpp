// gcd.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int gcd_minus(int u, int v)
{
	int t;
	while (u > 0) {
		if (u < v) {
			t = u; u = v; v = t;
		}
		u = u - v;
	}
	return v;
}

int gcd_modulus(int u, int v)
{
	int t;
	while (v) 
	{
		t = u % v;
		u = v;
		v = t;
	}

	return u;
}

int gcd_recursion(int u, int v) 
{
	if (v == 0)
		return u;
	else
		return gcd_recursion(v, u%v);
}

int main()
{
	int u, v;
	int gcd;

	u = 200; 
	v = 30;

	printf("gcd_minus result : ");
	gcd = gcd_minus(u, v);
	printf("%d\n", gcd);

	printf("gcd_modulus result : ");
	gcd = gcd_modulus(u, v);
	printf("%d\n", gcd);
	
	printf("gcd-recursion result : ");
	gcd = gcd_recursion(u, v);
	printf("%d\n", gcd);

	char a;
	a = getchar();
    return 0;
}

