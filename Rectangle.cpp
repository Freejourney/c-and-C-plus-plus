//根据长和宽来求矩形面积
#include <iostream>
using namespace std;

class Rectangle
{
public:
	Rectangle(int length = 0, int width = 0);
	~Rectangle();
	
	void SetLength(int length);
	void SetWidth(int width);
	int GetArea() const; 
private:
	int m_Length;
	int m_Width;	
};

int Rectangle::GetArea() const
{
	return m_Length * m_Width;
}

void Rectangle::SetLength(int length)
{
	m_Length = length;
}

void Rectangle::SetWidth(int width)
{
	m_Width = width;
}

Rectangle::Rectangle(int length, int width)
{
	m_Length = length;
	m_Width = width;
}

Rectangle::~Rectangle()
{
	cout << "~Rectangle() " << endl;
}

int main()
{
	Rectangle rectA(1, 5);
	Rectangle rectB(2, 4);
	Rectangle * rectC = new Rectangle(10, 20);
	 
	cout << "The area of rectA : " << rectA.GetArea() << endl;
	cout << "The area of rectB : " << rectB.GetArea() << endl;
	cout << "The area of rectC : " << rectC->GetArea() << endl;
	
	rectA.SetLength(10);
	rectA.SetWidth(50);
	rectC->SetLength(1);
	rectC->SetWidth(2);
	
	cout << "The area of rectA : " << rectA.GetArea() << endl;
	cout << "The area of rectB : " << rectB.GetArea() << endl;
	cout << "The area of rectC : " << rectC->GetArea() << endl;
	
	delete rectC;
	rectC = NULL;
	
	return 0;	
}
