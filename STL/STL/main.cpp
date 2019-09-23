#include<iostream>
#include<array>
#include<vector>


using namespace std;

//#define STL_ARRAY
#define STL_VECTOR

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
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> data;
	vec.insert(vec.begin() + index, 3 ,data);
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
#endif // STL_VECTOR

}