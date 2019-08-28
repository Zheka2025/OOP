#include<iostream>
#include <array>
#include<vector>
#include<deque>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
using namespace std;

#define tab "\t"
#define delimeter "\n----------------------\n"
//#define stl_array
//#define stl_vector
//#define stl_deque
//#define stl_list
//#define stl_forward_list
//#define stl_stack
#define stl_queue

void print(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}
void reverse_print(deque<int>& d)
{
	for (deque<int>::reverse_iterator it = d.rbegin(); it != d.rend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef stl_array
	//array - это контейнер, который хранит данные в виде статического массива.
	const int n = 5;
	/*	int Arr[] = { 3,5,8,13,21 };
		for (int i = 0; i < sizeof(Arr) / sizeof(int); i++)
		{
			cout << Arr[i] << tab;
		}
		cout << endl;
		//range based for:
		for (int i : Arr)
		{
			cout << i << tab;
		}
		cout << endl;
		*/
	array<int, n> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	for (int i : arr)
	{
		cout << i << tab;
	}
#endif
#ifdef stl_vector
	//vector- это контейнер, который хранит данные в виде динамического массива
	//вектор может увеличиваться и уменьшаться
	vector<char>vec = { 0,1,1,3,5,8,13,21,34,55 };
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	for (int i : vec)
	{
		cout << i << tab;
	}
	cout << endl;
	vec.push_back(89);
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	for (vector<char>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max size:\t" << vec.max_size() << endl;
#endif
#ifdef stl_deque

	deque<int> d = { 3,5,8,13,21 };
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	cout << d.size() << endl;
	cout << d.max_size() << endl;
	print(d);
	reverse_print(d);
	d.push_front(2);
	d.push_front(1);
	d.push_front(0);
	print(d);
	try
	{
		for (int i = 0; i <= d.size(); i++)
		{
			//cout << d[i] << tab;
			cout << d.at(i) << tab;
		}
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}


#endif//deque(DOuble Ended Quee-двунаправленная очередь) представляет собой двусвязный список векторов
#ifdef stl_list
	//Лист это самый обычный двусвязный список.
	list<int> l = {3,5,8,13,21};
	/*for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	int value;
	cout << "Input value: ";cin >> value;
	int index;
	cout << "Input index: ";cin >> index;
	list<int>::iterator it = l.begin();
	for (int i = 0; i < index; i++)it++;
	l.insert(it, value);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << tab;
	}*/
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); it++)
	{
		cout << *it << tab;
	}
#endif
#ifdef stl_forward_list
	forward_list<int> l = { 3,5,8,13,21 };
	for (forward_list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;

	/*int value;
	int index;
	cout << "Input value: "; cin >> value;
	cout << "Input index: "; cin >> index;
	forward_list<int>::iterator position=l.begin();
	for (int i = 0; i < index-1; i++)position++;
	l.insert_after(position, value);*/

	l.insert_after(l.before_begin(), 123);

	for (  int i:l)
	{
		cout << i << tab;
	}
	cout << endl;
#endif
#ifdef stl_stack
	//int n;cout << "Input stack size: "; cin >> n;
	stack<int>stk;
	stk.push(3);
	stk.push(5);
	stk.push(8);
	stk.push(13);
	stk.push(21);

	while (stk.size())
	{
		cout << stk.top() << endl;
		stk.pop();
	}
#endif
#ifdef stl_queue
	queue<int> fifo;
	fifo.push(3);
	fifo.push(5);
	fifo.push(8);
	fifo.push(13);
	fifo.push(21);
	
	while (fifo.size())
	{
		cout << fifo.front()<<tab;
		fifo.pop();
	}
#endif
}