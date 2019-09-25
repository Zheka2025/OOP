#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<forward_list>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE
#define STL_FORVARD_LIST

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	int Arr[] = { 3, 5, 8, 13, 21 };
	array<int, 5> arr = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	for (int i : Arr)
	{
		cout << i << "\t";
	}
	cout << endl;

	/*int* d_arr = new int[5]{ 34,88,123 };
	for (int i : d_arr)
	{
		cout << i << "\t";
	}
	cout << endl;
	delete[] d_arr;*/

	for (int i : arr) cout << i << "\t"; cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	vector<int> vec = {0,1,1,2,3,5,8,13,21,34};
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << "\t";
	}
	cout << endl;
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;

	vec.push_back(55);
	vec.push_back(89);

	for (vector<int>::iterator it = vec.begin(); it != vec.end();it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	for (vector<int>::iterator it = vec.end()-1; /*it != vec.begin()*/; it--)
	{
		cout << *it << "\t";
		if (it == vec.begin())break;
	}
	cout << endl;
	vec.resize(8);
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	vec.shrink_to_fit();

	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;
	cout << vec.empty() << endl;
	vec.reserve(15);
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	int* vec_arr = vec.data();

	int index;
	int data;
	cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
	cout << "¬ведите значение добавл€емого элемента: "; cin >> data;
	vec.insert(vec.begin() + index, 3 ,data);
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	cout << "¬ведите индекс удал€емого Їлемента: "; cin >> index;
	vec.erase(vec.begin() + index);
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	int start, finish;
	cout << "¬ведите индекс начала удалени€: "; cin >> start;
	cout << "¬ведите индекс конца удалени€: "; cin >> finish;
	vec.erase(vec.begin() + start, vec.begin() + finish);
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	/*vec.assign(6, 100);
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;*/
	vec.assign(vec.begin() + 2, vec.begin() + 5);
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
#endif // STL_VECTOR

#ifdef STL_DEQUE
	deque<int> dq = { 3,5,8,13,21 };
	for (int i = 0; i < dq.size(); i++)
	{
		cout << dq[i] << "\t";
	}
	cout << endl;
	/*dq.push_back(34);
	dq.push_back(55);
	dq.push_front(0);
	dq.push_front(1);*/

	dq.insert(dq.begin(), {0,1,1});
	dq.insert(dq.end(), {34,55,89});
	//dq.insert()

	/*dq.emplace(dq.begin() + 3,  128, 256, 512);*/

	for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
#endif // STL_DEQUE

#ifdef STL_FORVARD_LIST
	forward_list<int> fl{3,5,8,13,21};
	for (int i : fl)cout << i << "\t"; cout << endl;
	cout << fl.max_size() << endl;
#endif // STL_FORVARD_LIST

}