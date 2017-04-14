#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

#define NUM 20

int main()
{
	int i, j, e, n, m, s;
	queue<int> q1;
	stack<int> s1;

	cout << "Queue test! " << endl;

	if(q1.empty())
		cout << "queue Empty!" << endl;

	for(i = 0; i < NUM; i++)
	{
		q1.push(i);
	}

	if(!(q1.empty()))
		cout << "No empty" << endl;

	n = q1.size();
	cout << "size: " << n << endl;

	m = q1.back();
	cout << "Tail: " << m << endl;

	for(i = 0; i < NUM; i++)
	{
		e = q1.front();
		cout << "front: " << e << endl;
		q1.pop();
	}

	if(q1.empty())
		cout << "Queue empty again!" << endl;
	
	cout << endl;

	cout << "Stack test!" << endl;

	if(s1.empty())
	{
		cout << "Stack empty! " << endl;
	}

	for(i = 0; i < NUM; i++)
		s1.push(i);

	if(!s1.empty())
		cout << "stack not empty!" << endl;

	n = s1.size();
	cout << "size: " << n << endl;

	for(i = 0; i < NUM; i++)
	{
		m = s1.top();
		cout << "top: " << m << endl;
		s1.pop();
	}

	if(s1.empty())
		cout << "Stack empty again! " << endl;


	system("pause");
	return 0;
}
