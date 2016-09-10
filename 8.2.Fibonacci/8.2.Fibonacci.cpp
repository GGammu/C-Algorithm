// 8.2.Fibonacci.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

using namespace cppalgo;

int fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    printf("%d\n", fibonacci(10));

    char a;
    a = getchar();

    return 0;
}

