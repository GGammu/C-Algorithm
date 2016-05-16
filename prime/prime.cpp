// prime.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "math.h"

int is_prime(int n)
{
	int i;
	for (i = 2; i < n; i++)
	{
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int is_Prime_sqrt(int n)
{
	int i, sqrn;
	sqrn = (int)sqrt(n);
	for ( i = 2; i < sqrn; i++)
	{
		if (sqrn % i == 0) { 
			return false;
		}
	}

	return true;
}

int main()
{
	printf("%d\n", is_prime(13));

	printf("%d\n", is_Prime_sqrt(13));

	char a;
	a = getchar();
	return 0;
}

