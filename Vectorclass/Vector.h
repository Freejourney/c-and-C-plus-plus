#include <iostream>
#include <stdlib.h>
using namespace std;

template<class T>
class Vector
{
private:
	T * data;
	int size;
	int max;
	void Error(const char * cs) const
	{
		cout << cs << endl;
		exit(1);
	}
public:
	enum{SPACE_MAX = 16};
	explicit Vector(int n = 0):size(0), max(n + SPACE_MAX)			//防止隐式转换的构造函数
	{
		if(max > 0)
			data = new T[max];
	}
	Vector(const Vector<T> & v):data(NULL), max(0){operator=(v);}	//复制构造函数
	~Vector(){delete []data;}										//析构函数

	Vector & operator=(const Vector<T> & v);						//复制赋值函数

	T & operator[](int id){return data[id];}					//下标运算符函数
	const T & operator[](int id) const{return data[id];}			//常量型下标运算符函数
	
	bool Empty() const{return size == 0;}		//判空
	int Size() const{return size;}				//求数据个数
	int Max() const{return max;}				//求数据容量
	void Clear() {size = 0;}					//清空

	typedef T * iterator;
	typedef const T * const_iterator;

	iterator Begin(){return data;}
	const_iterator Begin() const{return data;}

	iterator End(){return data+size;}
	const_iterator End() const{return data+size;}

	const T & Front() const{return data[0];}
	T & Front() {return data[0];}

	const T & Back() const{return data[size-1];}
	T & Back() {return data[size-1];}

	void Push_back(const T & item){data[size++]=item;}
	void Pop_back(){size--;}
	void Reserve(int newMax);
	void Resize(int newSize, const T & item = T());

	iterator Insert(iterator itr, const T & item);
	iterator Erase(iterator itr);

	void Replace(T * first, T * last, const T & old_val, const T & new_val);
};

template<class T>
Vector<T> & Vector<T>::operator=(const Vector<T> & v)
{
	if(max != v.Max())
	{
		delete []data;
		max = v.max;
		data = new T[max];
	}
	size = v.Size();
	for(int i = 0; i < size; ++i)
		data[i] = v.data[i];

	return * this;
}

template<class T>
void Vector<T>::Reserve(int newmax)
{
	if(newmax < max)
		return;
	T * old = data;
	data = new T[newmax];
	for(int i = 0; i < size; ++i)
		data[i] = old[i];
	max = newmax;
	delete[]old;
}

template<class T>
void Vector<T>::Resize(int newSize, const T & item /* = T() */)
{
	if(newSize > max)
		Reserve(newSize*2+1);
		for(int i = size; i < newSize; ++i)
			data[i] = item;
	size = newSize;
}

template<class T>
T * Vector<T>::Insert(iterator itr, const T & item)
{
	if(size == max)
		Reserve(2 * max + 1);
	for(iterator p = data+size, q = data + size - 1; p != itr; --p, --q)
		*p = *q;
	*itr = item;
	size++;
	return itr;
}

template<class T>
T * Vector<T>::Erase(iterator itr)
{
	for(iterator p = itr, q = itr + 1; q != data + size; ++p, ++q)
		*p = *q;
	size--;
	return itr;
}

template<class T>
void Vector<T>::Replace(T * first, T * last, const T & old_val, const T & new_val)
{
	iterator temp = first;
	for(int i = 0; first + i != last; i++)
	{
		if(*(first+i) == old_val)
		{
			*(first+i) = new_val;
		}
	}
}
