#pragma once
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
		Element(T Data, Element* pNext = nullptr);
		~Element();
		friend class ForwardList;
	};
	Element* Head;	//Óêàçàòåëü íà íà÷àëî ñïèñêà
	unsigned int size;
public:
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr);
		~Iterator();
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
		const T& operator*()const;
		T& operator*();
		bool operator==(const Iterator& other);
		bool operator!=(const Iterator& other);
	};
	const int get_size()const;

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

	ForwardList();
	ForwardList(int size);
	ForwardList(initializer_list<T> il);
	ForwardList(const ForwardList& other);
	~ForwardList();

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
	int& operator[](int index);

	//			Äîáàâëåíèå ýëåìåíòîâ â ñïèñîê:
	void push_front(T Data);
	void push_back(T Data);

	void insert(int index, T data);

	//Óäàëåíèå ýëåìåíòîâ:
	void pop_front();

	void pop_back();

	void erase(int index);

	void print();
	friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right)
	{
		ForwardList<T> cat = left;
		for (ForwardList<T>::Iterator it = right.begin(); it != right.end(); it++)
			cat.push_back(*it);
		return cat;
	}
};