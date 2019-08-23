#include<iostream>
using namespace std;

#define tab "\t"

class Element
{
	int Data;
	Element* pNext;
public:
	Element(int Data, Element* pNext = nullptr)
	{
		this->Data = Data;
		this->pNext = pNext;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "Edestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

class ForwardList
{
	Element* Head;
public:
	ForwardList()
	{
		this->Head = nullptr;
		cout << "LConstructor:\t"<< this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	void push_front(int Data)
	{

		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
	}

	void print()
	{
		Element* Temp = Head; // Temp - »тератор
		while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext; // переход на следующий елемент
		}
	}

	void push_back(int Data)
	{
		Element* Temp = Head;
		while(Temp != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp = new Element(Data);
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "¬ведите количество элементов: ";
	cin >> n;
	ForwardList fl;
	for (int i = 0; i < n; i++)
	{
		fl.push_front(rand() % 100);
	}
	fl.print();
	fl.push_back(77);
	fl.print();
	
}