#pragma once

#include <iostream>
using namespace std;

//定义链表节点的结构体
template<typename T>
struct __ListNode
{
	__ListNode<T> * _next;
	__ListNode<T> * _prev;
	T _data;
	static int index;

	__ListNode():_next(NULL), _prev(NULL), _data(0){
		index++;
		cout << "a Node is created!" << endl;
	}
	__ListNode(const T & data):_next(NULL), _prev(NULL), _data(data){
		index++;
		cout << "a Node is created!" << endl;
	}	//创建节点的构造函数

	~__ListNode()
	{
		cout << "a Node is destroyed!" << endl;
		index--;
	}
};

template<typename T>
T __ListNode<T>::index = 0;

//定义迭代器，模板参数为T，T的引用，T类型的指针
template<typename T, typename Ref, typename Ptr>
struct __ListIterator
{
	typedef __ListNode<T> Node;	//将链表节点重命名为 Node
	typedef __ListIterator<T, T&, T*> self;	//将自己的类型重命名为 self, 简化命名

	Node * _node;

	__ListIterator(Node * node):_node(node){}

	bool operator != (const self & s)
	{
		return _node != s._node;
	}

	bool operator == (const self & s)
	{
		return _node == s._node;
	}

	self & operator++()
	{
		_node = _node->_next;
		return (self)_node;		//强制转换机制？
	}

	//前++的先用再加
	self operator++(int)
	{
		Node * tmp = _node;
		++_node;
		return tmp;
	}

	self & operator--()
	{
		_node = _node->_prev;
		return (self)_node;
	}

	//前--的先用再减
	self operator--(int)
	{
		Node * tmp = _node;
		--_node;
		return tmp;
	}

	Ref operator*()
	{
		return (*_node)._data;
	}

	Ref operator->()
	{
		return *_node;
	}
};

//定义反向迭代器，模板参数为T，T的引用，T类型的指针
template<typename T, typename Ref, typename Ptr>
struct __ListReverseIterator
{
	typedef __ListNode<T> Node;	//将链表节点重命名为 Node
	typedef __ListReverseIterator<T, T&, T*> self; //将自己的类型重命名为self，简化命名
	Node * _node;
	__ListReverseIterator(){}
	__ListReverseIterator(Node * node):_node(node){}

	self & operator++()
	{
		_node = _node->_prev;	//注意这里是反向迭代器，++应该指向前一个。******反向迭代器的最关键地方******
		return _node;
	}

	self operator++(int)
	{
		Node * tmp = _node;
		_node = _node->_prev;
		return tmp;
	}

	self & operator--()
	{
		_node = _node->_next;
		return _node;
	}

	self operator--(int)
	{
		Node * tmp = _node;
		_node = _node->_next;
		return tmp;
	}

	bool operator==(const self & s)
	{
		return _node->_data == s._node->_data;
	}

	bool operator!=(const self & s)
	{
		return _node->_data != s._node->_data;
	}

	Ref operator*()
	{
		return (*_node)._data;
	}

	Ref operator->()
	{
		return *_node;
	}


};

//定义链表
template<typename T>
class List
{
	typedef __ListNode<T> Node;
public:
	typedef __ListIterator<T, T &, T *> Iterator;	//重命名为迭代器
	typedef __ListReverseIterator<T, T &, T *> ReverseIterator;	//重命名为反向迭代器

	//申请一个新的节点
	Node * BuyNewNode(const T & t)
	{
		return new Node(t);
	}

	//构造函数
	List():_head(BuyNewNode(T()))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}

	//在首部插入一个元素
	void PushFront(const T & x)
	{
		Node * temp = BuyNewNode(x);
		temp->_next = _head->_next;
		temp->_prev = _head;
		_head->_next->_prev = temp;
		_head->_next = temp;
	}

	//在尾部插入一个元素
	void PushBack(const T & x)
	{
		Node * tail = _head->_prev;	//通过_head找到了尾节点
		Node * tmp = BuyNewNode(x);	//将新的尾节点接到末尾
		tail->_next = tmp;
		tmp->_prev = tail;
		tmp->_next = _head;
		_head->_prev = tmp;
	}

	//删除链表中所有值为val的值，返回值是删除的个数
	int Remove(int val)
	{
		Node * temp = _head->_next;
		int n = 0;
		while(temp != _head)
		{
			if(temp->_data == val)//			**********这是个双向环形链表！！！！
			{
				temp->_next->_prev = temp->_prev;
				temp->_prev->_next = temp->_next ;
				Node * tep = temp->_prev;
				delete temp;
				n++;
				temp = tep->_next;
			}
			else
			{
				temp = temp->_next;	
			}

		}
		return n;
	}

	//定义返回迭代器类型的Begin()和End()
	Iterator Begin() const
	{
		return Iterator(_head->_next);
	}

	Iterator End() const
	{
		return Iterator(_head);
	}

	//定义返回迭代器类型的rBegin()和rEnd()
	ReverseIterator rBegin() const
	{
		return ReverseIterator(_head->_prev);
	}

	ReverseIterator rEnd() const
	{
		return ReverseIterator(_head);
	}

	int Size() const {return Node::index;}
	bool Empty() const {return Node::index == 0;}

protected:
	Node * _head;
};
