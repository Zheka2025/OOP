#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n---------------------------\n"
//#define BASE_CHECK
#define DEBUG
//#define INDEX_OPERATOR_CHECK


class ForwardList
{
class Element
{
	int Data;
	Element* pNext;
	static int count;
public:
	Element(int Data, Element* pNext = nullptr)
	{
		this->Data = Data;
		this->pNext = pNext;
		count++;
#ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Element()
	{
		count--;
#ifdef DEBUG
		cout << "Edestructor:\t" << this << endl;
#endif // DEBUG

	}

	//operators
	operator int&()
	{
		return this->Data;
	}
	operator const int&() const
	{
		return this->Data;
	}
	friend class ForwardList;
};
	Element* Head;
	unsigned int size;
public:
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{
			cout << "ItConstructor:\t" << this << endl;
		}
		~Iterator() 
		{
			cout << "ItDestructor:\t" << this << endl;
		}
		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
	};
	const int& get_size() const
	{
		return size;
	}

	Element* begin()
	{
		return Head;
	}
	Element* end()
	{
		return nullptr;
	}

	ForwardList()
	{
		this->size = 0;
		this->Head = nullptr;
#ifdef DEBUG
		cout << "LConstructor:\t" << this << endl;
#endif // DEBUG

	}

	ForwardList(int n) :ForwardList()
	{
		/*this->size = 0;
		this->Head = nullptr;*/
		for (int i = 0; i < n; i++)
		{
			push_front(0);
		}
#ifdef DEBUG
		cout << "LConstrSize\t" << this << endl;
#endif // DEBUG

	}
	ForwardList(const ForwardList& other) : ForwardList()
	{
		for (Element* Temp = other.Head; Temp != nullptr; Temp = Temp->pNext)
			push_back(Temp->Data);
#ifdef DEBUG
		cout << "LCopyConstructor\t" << this << endl;
#endif // DEBUG
	}

	ForwardList(initializer_list<int> il) :ForwardList()
	{
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
			push_back(*it);
	}

	~ForwardList()
	{
		while (Head)pop_front();
#ifdef DEBUG
		cout << "LDestructor:\t" << this << endl;
#endif // DEBUG

	}


	void push_front(int Data)
	{
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;*/
		Head = new Element(Data, Head);
		size++;
	}

	void print()
	{
		Element* Temp = Head; // Temp - Итератор
		while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext; // переход на следующий елемент
		}
		cout << "Количество элементов списка: " << size << endl;
	}

	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		while(Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);
		size++;
	} 

	void insert(unsigned int index, int Data)
	{
		if (index > size)
		{
			cout << "Eror: Out of range." << endl;
			return;
		}
		if (index == 0)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < index-1; i++)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data, Temp->pNext);
		/*Element* New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;*/
		size++;
	}

	//Удаление элементов:
	void pop_front()
	{
		Element* Temp = Head;
		Temp = Temp->pNext;
		delete Head;
		Head = Temp;
		size--;
	}
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}
	void erase(int index)
	{
		if (index > size)
		{
			cout << "Eror: Out of range." << endl;
			return;
		}
		if (index == 0)
		{
		 	return pop_front();
		}
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* buff = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete buff;
		size--;
	}

	//Operators
	int& operator[](int index)
	{
		Element* Temp = Head;
		for (int i = 0; i < index; i++) Temp = Temp->pNext;
		return Temp->Data;
    }
	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp != nullptr; Temp = Temp->pNext)
			push_back(Temp->Data);
#ifdef DEBUG
		cout << "LCopyAssignment\t" << this << endl;
#endif // DEBUG
		return *this;
	}
};	

int ForwardList::Element::count = 0;



void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;

#ifdef BASE_CHECK
	ForwardList fl;
	for (int i = 0; i < n; i++)
	{
		fl.push_front(rand() % 100);
	}
	fl.print();
	cout << delimiter;
	/*fl.push_back(77);
	fl.print();
	cout << delimiter;
	fl.pop_front();
	fl.print();
	cout << delimiter;
	fl.pop_back();
	fl.print();
	cout << delimiter;
	int index;
	int data;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "введите значение добавляемого элемента: "; cin >> data;
	fl.insert(index, data);
	fl.print();
	cout << delimiter;
	cout << "Введите индекс удаляемого елемента: "; cin >> index;
	fl.erase(index);
	fl.print();
	cout << delimiter;*/

	/*ForwardList fl2;
	fl2.push_back(3);
	fl2.push_back(5);
	fl2.push_back(8);
	fl2.print();*/
#endif // BASE_CHECK
#ifdef INDEX_OPERATOR_CHECK

	ForwardList fl(n);
	fl.print();

	for (int i = 0; i < 10; i++)
	{
		fl[i] = rand() % 100;
		cout << fl[i] << tab;
	}
	cout << endl;
#endif // INDEX_OPERATOR_CHECK
	/*ForwardList fl = { 3, 5, 6, 8, 8, 10 };
	fl.print();
	ForwardList fl2 = fl;
	fl2.print();
	fl2 = fl;
	fl2.print();
	fl = fl;
	fl.print();*/
	ForwardList fl = { 3, 4, 5, 6, 7 };
	for (int i : fl)
	{
		cout << i << tab;
	}
	cout << endl;
}