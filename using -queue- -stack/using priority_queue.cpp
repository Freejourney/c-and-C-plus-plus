#include <iostream>
#include <queue>
using namespace std;

class T
{
public:
	int x, y, z;
	T(int a, int b, int c):x(a), y(b), z(c){}; 
};

bool operator<(const T & t1, const T & t2)
{
	return t1.x < t2.x;// '<'返回的是Bool型 
}

int main()
{
	priority_queue<T> q;//priority_queue里面有算法比较所存元素的大小并调整顺序，故需要对大小于操作符重载 
	q.push(T(4,4,3));
	q.push(T(2,2,5));
	q.push(T(1,5,4));
	q.push(T(3,3,6));
	q.push(T(2,4,7)); 
	
	while(!q.empty())
	{
		T t = q.top();
		q.pop();//获取一个删一个，top位一直在变 
		cout << t.x << " " << t.y << " " << t.z << endl;
	}
	
	return 0;
}
