#pragma once
#include "BinaryTree.h"
#include "../StringCls/AString.h"

using namespace cppalgo;

	class ParseTree : public BinaryTree<String>
	{
	public:
		void BuildParseTree(const String & strPostfix);
		bool IsOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/'); }
		void PreOrderTraverse(Node * pNode = 0);
		void PostOrderTraverse(Node * pNode = 0);
		void InOrderTraverse(Node * pNode = 0);
		void LevelOrderTraverse(Node * pNode = 0);
		void Visit(Node * pNode);
	};

