//usett1.cpp -- using base class and derived class
#include <iostream>
#include "tabtenn1.h"

void Show(const TableTennisPlayer & rt); 

int main(void)
{
	using std::cout;
	using std::endl;
	
	TableTennisPlayer player1("Tara", "Boomdea", false);
		player1.Name();
	if(player1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";
		
		
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	
	rplayer1.Name();
	
	if(rplayer1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";
		
	cout << "Name: ";
	rplayer1.Name();
	cout << "; Rating: " << rplayer1.Rating() << endl;
	
	//基类指针可以在不进行显式类型转换的情况下指向派生类对象
	//基类引用可以在不进行显式类型转换的情况下引用派生类对象
	cout << "基类指针可以在不进行显式类型转换的情况下指向派生类对象,基类引用可以在不进行显式类型转换的情况下引用派生类对象" << endl;
	TableTennisPlayer & rt = rplayer1;
	TableTennisPlayer * pt = & rplayer1;
	//基类指针或引用只能用于调用基类方法，不能调用派生类方法 
	
	//不能将基类对象和地址赋给派生类引用和指针
//	TableTennisPlayer player("Betsy", "Bloop", true);
//	RatedPlayer & rr = player; //Not allowed
//	RatedPlayer * pr = & player;  //Not allowed
	
	rt.Name();
	pt->Name(); 
		

	
	RatedPlayer rplayer2(1212, player1);
	cout << "Name: ";
	rplayer2.Name();
	cout << "; Rating: " << rplayer2.Rating() << endl;
	
	TableTennisPlayer player2("Tara", "Boomdea", false);
	RatedPlayer rplayer3(1140, "Mallory", "Duck", true);
	Show(player2);
	Show(rplayer3);
	cout << "基类指针或引用只能用于调用基类方法，不能调用派生类方法 " << endl;
	
	RatedPlayer olaf1(1840, "Olaf", "Loaf", true);
	TableTennisPlayer olaf2(olaf1);
	cout << "隐式复制构造函数将基类对象初始化为嵌套在派生类对象中的基类对象(只使用派生类对象的基类成分)" << endl; 

	RatedPlayer olaf3(1840, "Olaf", "Loaf", true);
	TableTennisPlayer winner;
	winner = olaf3;
	cout << "隐式重载赋值运算符将派生类对象赋给基类对象(只赋值派生类对象的基类成分)" << endl;
	
	
	return 0; 
}

void Show(const TableTennisPlayer & rt)
{
	using std::cout;
	cout << "Name: ";
	rt.Name();
	cout << "\nTable: ";
	if(rt.HasTable())
		cout << "yes\n";
	else
		cout << "no\n";
}
