// PrimeList.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "stdlib.h"


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Usage : prime [integer]\n");
		return 0;
	}

	int n = atoi(argv[1]);
	if (n < 2)
	{
		printf("Error : n must be greater than 1\n");
		return 0;
	}

	int *parray;

	parray = new int[n + 1];
	if (parray == 0)
	{
		printf("Error: memory allocation failed\n");
		return 0;
	}

	memset(parray, 0, sizeof(int)*(n + 1));
	
	int i, j;
	
	for ( i = 2; i <= n ; i++)
	{
		if (parray[i] == 1)
		{
			continue;
		}

		j = i;
		while ((j += i) <= n)
		{
			parray[j] = 1;
		}
	}

	for ( i = 2; i <= n; i++)
	{
		if (parray[i] == 0) 
		{
			printf("%d ", i);
		}
	}

	printf("\n");

	delete[] parray;

    return 0;
}

