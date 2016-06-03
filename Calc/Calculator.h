#pragma once

#include "../StringCls/AString.h"

namespace cppalgo
{
	class Calculator
	{
	public:
		Calculator();
		~Calculator();

		String ToPostfix1(const String & strInfix);
		String ToPostfix2(const String & strInfix);

		long CalcPostfix(const String & strPostfix);
		long CalcInfix(const String& strInfix);

	protected:
		bool IsOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/'); }
		long GetPercedence(char c);
	};

}

