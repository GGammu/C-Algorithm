// TreeTest.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "BinaryTree.h"
#include "ParseTree.h"
#include "../StringCls/AString.h"
#include "../StringCls/AString.cpp"

using namespace cppalgo;

int main()
{
	ParseTree tree;
	String strPostfix = "A B + C D - * E / F G * +";

	tree.BuildParseTree(strPostfix);

	tree.PreOrderTraverse();
	printf("\n");
	tree.PostOrderTraverse();
	printf("\n");
	tree.InOrderTraverse();
	printf("\n");
	tree.LevelOrderTraverse();
	printf("\n");

	char a;
	a = getchar();
}

