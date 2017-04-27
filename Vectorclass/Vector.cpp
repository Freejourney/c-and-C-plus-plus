#include "vectorclass427.h"
#include <iostream>

template<class Iterator>
void display_vector(Iterator first, Iterator last);

int main()
{
	Vector<int> V;
	int item;
	cout << "input 10 integers:\n";
	for(int i = 0; i < 10; ++i)
	{
		cin>>item;
		V.Push_back(item);
	}

	cout << "将老元素1用新元素5替换" << endl;
	V.Replace(V.Begin(), V.End(), 1, 5);

	Vector<int>::iterator itr = V.Begin();
	cout << "after operator++: " << endl;
	cout << *(++itr) << endl;
	cout << "after operator--():" << endl;
	cout << *(--itr) << endl;
	V.Erase(itr);
	cout << "after erasing the first:" << endl;
	display_vector(V.Begin(), V.End());

	V.Pop_back();
	cout << "after erasing the last: " << endl;
	display_vector(V.Begin(), V.End());

	cout << "the first and the last: " << endl;
	cout << V.Front() << endl;
	cout << V.Back() << endl;

	Vector<int> v1 = V;
	v1.Reserve(20);
	v1.Resize(20, 5);
	for(int i = 0; i < v1.Size(); ++i)
		v1[i]++;
	cout << "after reserving(20), resizing(20, 5) and adding(1): " << endl;
	display_vector(v1.Begin(), v1.End());

	
	/*display_vector(v1.Begin(), v1.End());*/
	
	system("pause");
	return 0;
}

template<class Iterator>
void display_vector(Iterator first, Iterator last)
{
	for(; first != last; ++first)
		cout << *first << '\t';
	cout << endl;
}
