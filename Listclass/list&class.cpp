#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
	Node * next;
	int data;
	static int index;
	int m_iIndex; 

	//Àà½áµã´îÔØ¾²Ì¬³ÉÔ±±äÁ¿ 
	Node():next(NULL), data(0)
	{
		index++;
		m_iIndex = index;
		cout << "New node is created!" << index << endl;;	
	}	
	
	~Node()
	{
		index--;
		cout << "a node is delete~~" << index << endl;
	}
};

//¾²Ì¬³ÉÔ±±äÁ¿µÄÓÃ·¨ 
int Node::index=0;

class List{
public:

	Node * head = new Node;
	
	void Inisial(){
		//Í·½áµãÁíÍâ½¨Á¢£¬Í·½áµã²»´¢´æÊý¾Ý£¬Ö»±ê¼ÇÎ»ÖÃ 
		
	
		Node * tep = head;
		
		//µ¥Á´±íºÚ¿Æ¼¼ 
		int n;
		while(cin >> n)
		{
			Node * temp = new Node;
			temp->data = n;
			tep->next = temp;
			tep = temp;
		}
		cin.clear();
	}
	
	void printinf()
	{
		Node * tep = head->next;
		
		while(tep != NULL)
		{
			cout << tep->m_iIndex << "    data: " << tep->data << endl;
			tep=tep->next;
		}
	}
	
	int searching(const int & id) const
	{
		Node * temp = head;
		while(temp->m_iIndex != id + 1 && temp != NULL)
		{
			temp = temp->next;
		}
		
		if(temp->m_iIndex == id + 1)
			cout << "The data : " << temp->data << "  of index : " << temp->m_iIndex - 1 << endl;
		else
			cout << "No such index\n";
	}
	
	int pushback(const int & item)
	{
		Node * temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		Node * newnode = new Node;
		newnode->data = item;
		temp->next = newnode;
	}
	
	void deleteNodeAll()
	{
		Node * temp = head;
		Node * tmp = temp;
		while(temp!=NULL)
		{
			tmp = temp;
			temp = temp->next;
			delete tmp;
		}
			
	}
	
	void deleteOne(const int & item)
	{
		Node * temp = head;
		Node * tmp = temp;
		while(temp->data != item)
		{
			tmp = temp;
			temp = temp -> next;
		}
		tmp->next = temp->next;
		delete temp;
	}
};


int main()
{

	List L;
	L.Inisial();
	L.pushback(100);
	L.pushback(100);
	L.pushback(1000);
	
	L.deleteOne(58);
	L.printinf();
	L.searching(4);
	L.deleteNodeAll();
	
	
	
	return 0;
}
