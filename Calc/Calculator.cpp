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

String cppalgo::Calculator::ToPostfix1(const String & strInfix)
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

String cppalgo::Calculator::ToPostfix2(const String & strInfix)
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

			}
		}
	}
	return String();
}

long cppalgo::Calculator::CalcPostfix(const String & strPostfix)
{
	return 0;
}

long cppalgo::Calculator::CalcInfix(const String & strInfix)
{
	String strPostfix = ToPostfix2(strInfix);
	return CalcPostfix(strPostfix);
}

long cppalgo::Calculator::GetPercedence(char c)
{	
	if (c == '(') return 0;
	if (c == '-' || c == '+') return 1;
	if (c == '*' || c == '/') return 2;
	return 3;
}
