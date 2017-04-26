#include "List.h"
#include <stdlib.h>
//#include "testfunction.cpp"

//测试链表
void TestList()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);

	//打印l中的元素
	List<int> ::Iterator it1 = l.Begin();//定义迭代器it1为l的起始部分
	while(it1 != l.End())
	{
		cout << *it1 << " ";	//重载了解引用操作符，可以访问it1中的元素
		++it1;	//重载了++运算符，可以访问下一个元素
	}
	cout << endl;
}

void TestReverseIterator()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(1);
	l.PushBack(1);

	List<int>::ReverseIterator it = l.rBegin();	//定义反向迭代器it为反向迭代器的第一个元素
	while(it != l.rEnd())
	{
		cout << *it << " ";	//重载了解引用操作符，访问元素当前内容
		it++;	//重载了++运算符，访问后面的元素
	}
	cout << endl;
	cout << endl;
//	cout << l.Remove(1) << endl;
}

int main()
{
	TestList();

	TestReverseIterator();

	system("pause");
	return 0;
}
