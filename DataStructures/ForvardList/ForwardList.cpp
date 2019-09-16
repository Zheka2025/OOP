#include "ForwardList.h"
template <typename T>
int ForwardList<T>::Element::count = 0;

//template <typename T>
template <typename T>
ForwardList<T>::Element::Element(T Data, Element* pNext)
{
	this->Data = Data;
	this->pNext = pNext;
	count++;
	cout << "EConstructor:\t" << this << endl;
}
template <typename T>
ForwardList<T>::Element::~Element()
{
	count--;
	cout << "EDestructor:\t" << this << endl;
}

template <typename T>
ForwardList<T>::Iterator::Iterator(Element* Temp) :Temp(Temp)
{
	cout << "ItConstructor:\t" << this << endl;
}
template <typename T>
ForwardList<T>::Iterator::~Iterator()
{
	cout << "ItDestructor:\t" << this << endl;
}
template <typename T>
const T& ForwardList<T>::Iterator::operator*()const
{
	return Temp->Data;
}
template <typename T>
T& ForwardList<T>::Iterator::operator*()
{
	return Temp->Data;
}
template <typename T>
bool ForwardList<T>::Iterator::operator==(const Iterator& other)
{
	return this->Temp == other.Temp;
}
template <typename T>
bool ForwardList<T>::Iterator::operator!=(const Iterator& other)
{
	return this->Temp != other.Temp;
}

//---------------------------------------------------------//
template <typename T>
const int ForwardList<T>::get_size()const
{
	return this->size;
}
template <typename T>
ForwardList<T>::ForwardList()
{
	this->Head = nullptr;
	this->size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template <typename T>
ForwardList<T>::ForwardList(int size) :ForwardList()
{
	/*this->Head = nullptr;
	this->size = 0;*/
	while (size--)push_front(0);
}
template <typename T>
ForwardList<T>::ForwardList(initializer_list<T> il) :ForwardList()
{
	cout << typeid(il.begin()).name() << endl;
	for (T const* it = il.begin(); it != il.end(); it++)
		push_back(*it);
}
template <typename T>
ForwardList<T>::ForwardList(const ForwardList& other) :ForwardList()
{
	for (Element* Temp = other.Head; Temp != nullptr; Temp = Temp->pNext)
		push_back(Temp->Data);
	cout << "LCopyConstruct:\t" << this << endl;
}
template <typename T>
ForwardList<T>::~ForwardList()
{
	while (Head)pop_front();
	cout << "LDestructor:\t" << this << endl;
}

//			Operators:
template <typename T>
int& ForwardList<T>::operator[](int index)
{
	Element* Temp = Head;
	for (int i = 0; i < index; i++)Temp = Temp->pNext;
	return Temp->Data;
}

//			Äîáàâëåíèå ýëåìåíòîâ â ñïèñîê:
template <typename T>
void ForwardList<T>::push_front(T Data)
{
	//Data - äîáàâëÿåìîå çíà÷åíèå.
	//1) Ñîçäàåì ýëåìåíò, â êîòîðûé ìîæíî ïîëîæèòü äîáàâëÿåìîå çíà÷åíèå:
	/*Element* New = new Element(Data);
	New->pNext = Head;
	Head = New;*/
	Head = new Element(Data, Head);
	size++;
}
template <typename T>
void ForwardList<T>::push_back(T Data)
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
template <typename T>
void ForwardList<T>::insert(int index, T data)
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
template <typename T>
void ForwardList<T>::pop_front()
{
	Element* buffer = Head;
	Head = Head->pNext;
	delete buffer;
	size--;
}
template <typename T>
void ForwardList<T>::pop_back()
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
template <typename T>
void ForwardList<T>::erase(int index)
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
template <typename T>
void ForwardList<T>::print()
{
	for (Element* Temp = Head; Temp != nullptr; Temp = Temp->pNext)
		cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "Длинна списка: " << size << endl;
}