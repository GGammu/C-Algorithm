#include "stdafx.h"
#include "Fibonacci.h"

using namespace cppalgo;

Fibonacci::Fibonacci()
{
}

Fibonacci::~Fibonacci()
{
}

int cppalgo::Fibonacci::fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int cppalgo::Fibonacci::fibonacci_nr(int n)
{
    int r = 0;
    int a = 1;
    int b = 1;

    if (n == 1 || n == 2)
        return 1;
    while (n-- > 2)
    {
        r = a + b;
        a = b;
        b = r;
    }
    return r;
}
