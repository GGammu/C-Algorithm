// List.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "SimpleList.h"
#include "../StringCls/AString.h"
#include "../StringCls/AString.cpp"
#include "DoubleList.h"

using namespace cppalgo;

template SimpleList<int>;
template SimpleList<String>;
template DoubleList<int>;

class Person
{
private:
	String m_strName;
	int m_nAge;
public:
	Person() { m_nAge = 0; }
	Person(const String & strName, int nAge) : m_strName(strName), m_nAge(nAge) {}
	String GetName() { return m_strName; }
	int GetAge() { return m_nAge; }

	bool operator==(Person p) const { return m_strName == p.m_strName && m_nAge == p.m_nAge; }
	Person(const Person & p) { m_strName = p.m_strName; m_nAge = p.m_nAge; }
	const Person & operator=(const Person & p) { m_strName = p.m_strName; m_nAge = p.m_nAge; return *this; }
};

class Double
{
	double m_double;
public :
	Double() { m_double = 0; }
	Double(double d) { m_double = d; }
	bool operator==(const Double & d) const { return (int)m_double == (int)d.m_double; }
};

void dump_list_int(const SimpleList<int>& list)
{
	POS pos = list.GetHeadPosition();
	while (pos)
	{
		printf("%d", list.GetNext(pos));
	}

	printf("\n");
}

void dump_list_string(const SimpleList<String>& list)
{
	POS pos = list.GetHeadPosition();
	while (pos)
	{
		printf("%s", (const char*)list.GetNext(pos));
	}
	printf("\n");
}

void dump_dlist_string(const DoubleList<String> & list)
{
	POS pos;

	pos = list.GetHeadPosition();

	while (pos)
	{
		printf("%s", (const char*)list.GetNext(pos));
	}
	printf("\n");
}

void dump_dlist_person(const DoubleList<Person>& list)
{
	POS pos;
	pos = list.GetHeadPosition();

	while (pos)
	{
		Person p = list.GetNext(pos);
		printf("%s(%d)", (const char*)p.GetName(), p.GetAge());
	}
	printf("\n");
}
int main()
{
	SimpleList<int> list;

	try
	{
		list.GetHead();
	}
	catch (SimpleList<int>::Exception e)
	{
		if (e == SimpleList<int>::INVALID_POS)
		{
			printf("catched, Invalid Pointer %d\n", e);
		}
		else if (e == SimpleList<int>::EMPTY_LIST)
		{
			printf("catched, Empty List %d\n", e);
		}
	}

	list.AddHead(1);
	list.AddHead(2);
	list.AddHead(3);
	
	dump_list_int(list);
	
	POS pos = list.Find(2);

	printf("%d\n", list.GetAt(pos));

	DoubleList<Person> dlist2;
	dlist2.AddTail(Person("Jake", 33));
	dlist2.AddTail(Person("Ryu", 27));
	dlist2.AddTail(Person("Slash", 25));

	dump_dlist_person(dlist2);

	pos = dlist2.Find(Person("Jake", 33));
	printf("Found %s\n", (const char*)dlist2.GetAt(pos).GetName());

	char a;
	a = getchar();
    
	return 0;
}

