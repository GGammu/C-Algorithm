// 8.2.Fibonacci.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

