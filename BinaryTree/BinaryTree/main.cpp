#include <iostream>
using namespace std;

#define BASE_CHECK
#define COPY_CONSTRUCTOR_CHECK

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
		{
			this->Data = Data;
			this->pLeft = pLeft;
			this->pRight = pRight;
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		bool is_leaf()
		{
			return pLeft == pRight;
		}
		friend class Tree;
	} *Root;
public:
	Element* getRoot()
	{
		return this->Root;
	}

	Tree()
	{
		Root = nullptr;
		cout << "TConstructor:\t" << this << endl;
	}
	Tree(initializer_list<int> il) :Tree()
	{
		for (int const* it = il.begin(); it != il.end(); it++)
			insert(*it);
	}
	Tree(const Tree& other)
	{
		CopyTree(this->Root, other.Root);
		cout << "TCopyConstructor:\t" << this << endl;
	}
	~Tree()
	{
		cout << "TDestructor:\t" << this << endl;
		clear();
	}

	void insert(int Data)
	{
		insert(Data, this->Root);
	}

	int getMinValue()
	{
		return getMinValue(this->Root);
	}

	int getMinValue(Element* Root)
	{
		if (Root->pLeft == nullptr) return Root->Data;
		return getMinValue(Root->pLeft);
	}

	int getMaxValue()
	{
		return getMaxValue(this->Root);
	}

	int getMaxValue(Element* Root)
	{
		if (Root->pRight == nullptr) return Root->Data;
		return getMaxValue(Root->pRight);
	}

	void CopyTree(Element*& Root, Element* Other)
	{
		if (Other == nullptr) return;
		Root = new Element(Other->Data);
		CopyTree(Root->pLeft, Other->pLeft);
		CopyTree(Root->pRight, Other->pRight);
	}

	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr) return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)
			{
				Root->pLeft = new Element(Data);
			}
			else
			{
				insert(Data, Root->pLeft);
			}
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)
			{
				Root->pRight = new Element(Data);
			}
			else
			{
				insert(Data, Root->pRight);
			}
		}
	}

	void erase(int Data, Element*& Root)
	{
		if (Root == nullptr) return;
		if (Root->Data == Data)
		{
			if (Root->is_leaf())
			{
				delete Root;
				Root = nullptr;
				return;
			}
			else
			{
				if (Root->pLeft)
				{
					Root->Data = getMaxValue(Root->pLeft);
					erase(getMaxValue(Root->pLeft), Root->pLeft);
				}
				else
				{
					Root->Data = getMinValue(Root->pRight);
					erase(getMinValue(Root->pRight), Root->pRight);
				}
			}
		}
		erase(Data, Root->pLeft);
		erase(Data, Root->pRight);
	}

	void clear()
	{
		clear(this->Root);
		this->Root = nullptr;
	}

	void clear(Element* Root)
	{
		if (Root == nullptr) return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}

	void print()
	{
		print(this->Root);
		cout << endl;
	}

	void print(Element* Root)
	{
		if (Root == nullptr) return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}

	int count()
	{
		return count(this->Root);
	}

	int count(Element* Root)
	{
		if (Root == nullptr) return 0;
		return count(Root->pLeft) + count(Root->pRight) + 1;
	}

	int sum()
	{
		return sum(this->Root);
	}

	int sum(Element* Root)
	{
		if (Root == nullptr) return 0;
		return sum(Root->pLeft) + sum(Root->pRight) + Root->Data;
	}

	double avg()
	{
		return avg(this->Root);
	}

	double avg(Element* Root)
	{
		return (double)sum() / count();
	}

	void erase(int Data)
	{
		erase(Data, this->Root);
	}

	Tree& operator=(const Tree& other)
	{
		clear();
		CopyTree(this->Root, other.Root);
		cout << "TCopyAssignment:\t" << this << endl;
		return *this; 
	}

	/*void erase(int Data, Element* Root)
	{
		Element* buffer;
		if (Root == nullptr) return;
		if (Root->Data == Data)
		{
			buffer = Root;
			Root = Root->pRight;
			Root->pLeft = buffer->pLeft;
			delete buffer;
			return;
		}
		if (Root->pLeft->Data == Data)
		{
				buffer = Root->pLeft;
				Root->pLeft = Root->pLeft->pLeft;
			delete buffer;
			return;
		}
		if (Root->pRight->Data == Data)
		{
			buffer = Root->pRight;
			Root->pRight = Root->pRight->pRight;
			delete buffer;
			return;
		}
		if (Data < Root->pLeft->Data)
		{
			erase(Data, Root->pLeft);
		}
		if (Data > Root->pRight->Data)
		{
			erase(Data, Root->pRight);
		}
	}*/
};

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	tree.print();
	cout << "Минимальное значение в дереве:\t " << tree.getMinValue() << endl;
	cout << "Максимальное значение в дереве:\t " << tree.getMaxValue() << endl;
	cout << "Количество элементов:\t " << tree.count() << "\t" << endl;
	cout << "Сумма элементов:\t " << tree.sum() << "\t" << endl;
	cout << "Среднее арифметическое: \t" << tree.avg() << "\t" << endl;
	cout << "Удалить из дерева елемент со значением: "; cin >> n;
	tree.erase(n);
	tree.print();
	/*tree.clear();
	tree.print();*/
#endif // BASE_CHECK

#ifdef COPY_CONSTRUCTOR_CHECK
	Tree tr2 = { 3, 5, 8, 13, 21 };
	tr2.print();
	Tree tr3 = tr2;
	tr3.print();
	tree.print();
	tree = tr3;
	tree.print();
#endif // COPY_CONSTRUCTOR_CHECK
}