#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//#define BASE_CHECK
//#define INDEX_OPERATOR_CHECK
//#define CONSTRUCTORS_CHECK


template <typename T>
class ForwardList
{
	class Element
	{
		T Data;		//Çíà÷åíèå ýëåìåíòà
		Element* pNext;	//Àäðåñ ñëåäóþùåãî ýëåìåíòà
		static int count;
	public:
		Element(T Data, Element* pNext = nullptr)
		{
			this->Data = Data;
			this->pNext = pNext;
			count++;
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			count--;
			cout << "EDestructor:\t" << this << endl;
		}
		operator const T&()const
		{
			return this->Data;
		}
		operator T&()
		{
			return this->Data;
		}
		friend class ForwardList;
	};
	Element* Head;	//Óêàçàòåëü íà íà÷àëî ñïèñêà
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
		const int& operator*()const
		{
			return Temp->Data;
		}
		int& operator*()
		{
			return Temp->Data;
		}
		bool operator==(const Iterator& other)
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other)
		{
			return this->Temp != other.Temp;
		}
	};
	const int get_size()const
	{
		return this->size;
	}

	const Iterator begin()const
	{
		return Head;
	}
	Iterator begin()
	{
		return Head;
	}

	const Iterator end() const
	{
		return nullptr;
	}
	Iterator end()
	{
		return nullptr;
	}

	ForwardList()
	{
		this->Head = nullptr;
		this->size = 0;
		cout << "LConstructor:\t" << this << endl;
	} 
	ForwardList(int size) :ForwardList()
	{
		/*this->Head = nullptr;
		this->size = 0;*/
		while (size--)push_front(0);
	}
	ForwardList(initializer_list<T> il) :ForwardList()
	{
		cout << typeid(il.begin()).name() << endl;
		for (T const* it = il.begin(); it != il.end(); it++)
			push_back(*it);
	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		for (Element* Temp = other.Head; Temp != nullptr; Temp = Temp->pNext)
			push_back(Temp->Data);
		cout << "LCopyConstruct:\t" << this << endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

	//			Operators:
	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp != nullptr; Temp = Temp->pNext)
			push_back(Temp->Data);
		cout << "LCopyAssignment:\t" << this << endl;
		return *this;
	}
	int& operator[](int index)
	{
		Element* Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
		return Temp->Data;
	}

	//			Äîáàâëåíèå ýëåìåíòîâ â ñïèñîê:
	void push_front(T Data)
	{
		//Data - äîáàâëÿåìîå çíà÷åíèå.
		//1) Ñîçäàåì ýëåìåíò, â êîòîðûé ìîæíî ïîëîæèòü äîáàâëÿåìîå çíà÷åíèå:
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;*/
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(T Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		while (Temp->pNext != nullptr)Temp = Temp->pNext;
		Temp->pNext = new Element(Data);
		size++;
	}

	void insert(int index, T data)
	{
		if (index == 0)
		{
			push_front(data);
			return;
		}
		if (index > size)
		{
			cout << "Error: Out of range." << endl;
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		/*Element* New = new Element(data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;*/
		Temp->pNext = new Element(data, Temp->pNext);
		size++;
	}

	//Óäàëåíèå ýëåìåíòîâ:
	void pop_front()
	{
		Element* buffer = Head;
		Head = Head->pNext;
		delete buffer;
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
		if (index == 0)
		{
			pop_front();
			return;
		}
		if (index >= size)
		{
			cout << "Error: out of range" << endl;
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
		Element* buffer = Temp->pNext;

		Temp->pNext = Temp->pNext->pNext;
		delete buffer;
		size--;
	}

	void print()
	{
		//Element* Temp = Head;//Temp - Èòåðàòîð.
		////Èòåðàòîð - ýòî óêàçàòåëü, ïðè ïîìîùè êîòîðîãî ìîæíî ïîëó÷èòü äîñòóï
		////ê ýëåìåíòàì ñòðóêòóðû äàííûõ.
		//while (Temp != nullptr)
		//{
		//	cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		//	Temp = Temp->pNext;	//Ïåðåõîä íà ñëåäóþùèé ýëåìåíò.
		//}

		for (Element* Temp = Head; Temp != nullptr; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "Длинна списка: " << size << endl;
	}
	friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right)
	{
		ForwardList<T> cat = left;
		for (ForwardList<T>::Iterator it = right.begin(); it != right.end(); it++)
			cat.push_back(*it);
		return cat;
	}
};

template <typename T>
int ForwardList<T>::Element::count = 0;

//template <typename T>

void main()
{
	setlocale(LC_ALL, "");
	int n;		//Êîëè÷åñòâî ýëåìåíòîâ
	//cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ: ";	cin >> n;
#ifdef BASE_CHECK
	ForwardList fl;
	for (int i = 0; i < n; i++)
	{
		fl.push_front(rand() % 100);
	}
	fl.print();
	fl.push_back(123);	fl.print();
	fl.pop_back();	fl.print();

	int index;
	int data;
	cout << "Ââåäèòå èíäåêñ äîáàâëÿåìîãî ýëåìåíòà: "; cin >> index;
	cout << "Ââåäèòå çíà÷åíèå äîáàâëÿåìîãî ýëåìåíòà: "; cin >> data;
	fl.insert(index, data);
	fl.print();

	cout << "Ââåäèòå èíäåêñ óäàâëÿåìîãî ýëåìåíòà: "; cin >> index;
	fl.erase(index);
	fl.print();

	/*ForwardList fl2;
	fl2.push_back(3);
	fl2.push_back(5);
	fl2.push_back(8);
	fl2.print();*/
#endif // BASE_CHECK

#ifdef INDEX_OPERATOR_CHECK
	//TODO: exception handling in []
	ForwardList fl(n);
	fl.print();

	cout << int() << endl;
	for (int i = 0; i < fl.get_size(); i++)
	{
		fl[i] = rand() % 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << fl[i] << tab;
	}
	cout << endl;
#endif // INDEX_OPERATOR_CHECK

#ifdef CONSTRUCTORS_CHECK
	ForwardList fl = { 3, 5, 8, 13, 21 };
	fl.print();
	fl = fl;
	fl.print();
#endif

	int Arr[] = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < sizeof(Arr) / sizeof(int); i++)
	{
		cout << Arr[i] << tab;
	}
	cout << endl;

	for (int i : Arr)
	{
		cout << i << tab;
	}
	cout << endl;

	char str[] = "Hello";
	for (char i : str)
		cout << i << tab;
	cout << endl;

	ForwardList <int>fl = { 3, 5, 8, 13, 21 };
	system("COLOR 0A");
	for (int i : fl)
	{
		cout << i << tab;
	}
	cout << endl;
	//cout << sizeof(ForwardList::Element) << endl;
	ForwardList <int>fl2 = { 34, 55, 89 };
	ForwardList <int>fl3 = fl + fl2;
	for (int i : fl3)
	{
		cout << i << tab;
	}
	cout << endl;

	ForwardList <double> lst_dbl = { 2.5 , 4.6, 8.9, 1.5 };
	lst_dbl.print();
}