#include <iostream>
#include <string>
using namespace std;

class Human
{
	string first_name;
	string last_name;
	unsigned int age;
public:
	const string& get_first_name() const
	{
		return this->first_name;
	}
	const string& get_last_name() const
	{
		return this->last_name;
	}
	unsigned int get_age() const
	{
		return this->age;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//Constructors:
	Human(const string& first_name, const string& last_name, unsigned int age)
	{
		set_first_name(first_name);
		set_last_name(last_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}

	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//Methods:
	void info()
	{
		cout << last_name << " " << first_name << " " << age << " лет.\n";
	}
};

class Student :public Human
{
	string specialty;
	string group;
	unsigned int year; // год обучения
	unsigned int rating; // успеваемость
public:
	const string& get_specialty() const
	{
		return this->specialty;
	}
	const string& get_group() const
	{
		return this->group;
	}
	unsigned int get_year() const
	{
		return this->year;
	}
	unsigned int get_rating() const
	{
		return this->rating;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_year (unsigned int year)
	{
		this->year = year;
	}
	void set_rating(unsigned int rating)
	{
		this->rating = rating;
	}

	//Constructors:
	Student(const string& first_name, const string& last_name, unsigned int age,
		const string& specialty, const string& group, unsigned int year, unsigned int rating) : Human(first_name,last_name, age)
	{
		this->specialty = specialty;
		this->group = group;
		this->year = year;
		this->rating = rating;
		cout << "Sconstructor\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//Methods:
	void info()
	{
		Human::info();
		cout << specialty << " " << group << " " << year << " курс, успеваемость " << rating << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Human h("Василий", "Дурко", 21);
	h.info();
	Student s("Иван", "Тупенко", 18, "Девелупер", "СТ ПУ 34а", 1, 0);
	s.info();
}