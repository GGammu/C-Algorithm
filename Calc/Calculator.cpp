#include "stdafx.h"
#include "Calculator.h"
#include "../Stack/ListStack.h"

using namespace cppalgo;

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

String Calculator::ToPostfix1(const String & strInfix)
{
	String strPostfix;
	ListStack<char> stack;
	char c;
	int i = 0;
	
	while (strInfix[i])
	{
		c = strInfix[i];
		if (c == ')')
		{
			strPostfix += stack.Pop();
			strPostfix += ' ';
			i++;
		}
		else if (String(c).FindOneOf("+-*/") == 0)
		{
			stack.Push(c);
			i++;
		}
		else if (c >= '0' && c <= '9')
		{
			do
			{
				strPostfix += c;
				i++;
				c = strInfix[i];
			} while (c >= '0' && c <= '9');

			strPostfix += ' ';
		}
		else
		{
			i++;
		}
	}	

	return strPostfix;
}

String Calculator::ToPostfix2(const String & strInfix)
{
	String strPostfix;
	ListStack<char> stack;
	char c;
	int i = 0;

	while (strInfix[i])
	{
		c = strInfix[i];
		if (c == '(')
		{
			stack.Push(c);
			i++;
		}
		else if (c == ')')
		{
			while (!stack.IsEmpty() && stack.GetTop() != '(')
			{
				strPostfix += stack.Pop();
				strPostfix += ' ';
			}
			stack.Pop();
			i++;
		}
		else if (IsOperator(c))
		{
			while (!stack.IsEmpty() && GetPercedence(stack.GetTop()) >= GetPercedence(c) )
			{
				strPostfix += stack.Pop();
				strPostfix += ' ';
			}
			stack.Push(c);
			i++;
		}
		else if (c >= '0' && c <= '9')
		{
			do
			{
				strPostfix += c;
				c = strInfix[++i];
			} while (c >= '0' && c <= '9');
			strPostfix += ' ';
		}
		else
		{
			i++;
		}
	}
	while (!stack.IsEmpty())
	{
		strPostfix += stack.Pop();
		strPostfix += ' ';
	}

	return strPostfix;
}

long Calculator::CalcPostfix(const String & strPostfix)
{
	long n;
	ListStack<long> stack;
	int i = 0;
	char c;

	while (strPostfix[i])
	{
		c = strPostfix[i];

		if (c >= '0' && c <= '9')
		{
			n = 0;

			do
			{
				n = n * 10 + c - '0';
				c = strPostfix[++i];
			} while (c >= '0' && c <= '9');
			stack.Push(n);
		}
	}

	return 0;
}

long Calculator::CalcInfix(const String & strInfix)
{
	String strPostfix = ToPostfix2(strInfix);
	return CalcPostfix(strPostfix);
}

long Calculator::GetPercedence(char c)
{	
	if (c == '(') return 0;
	if (c == '-' || c == '+') return 1;
	if (c == '*' || c == '/') return 2;
	return 3;
}
