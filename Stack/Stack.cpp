// Stack.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "ArrayStack.h"
#include "ListStack.h"

using namespace cppalgo;

template ArrayStack<int>;
template ListStack<char>;

int main()
{
	ArrayStack<int> stack_int(5);
	stack_int.Push(1);
	stack_int.Push(2);
	stack_int.Push(3);
	stack_int.Push(4);
	stack_int.Push(5);

	int n = stack_int.GetCount();

	while (!stack_int.IsEmpty())
	{
		printf("%d ", stack_int.Pop());
	}

	printf("\n");

	ListStack<char> stack_char;
	stack_char.Push('A');
	stack_char.Push('B');
	stack_char.Push('C');
	stack_char.Push('D');
	stack_char.Push('E');

	char c = stack_char.GetTop();

	while (!stack_char.IsEmpty())
	{
		printf("%c", stack_char.Pop());
	}

	printf("\n");

	char a;
	a = getchar();
    return 0;
}

