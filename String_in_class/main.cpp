#include<iostream>
using namespace std;



class String
{
	int size;//уразмер строки
	char* str;//адресс строки в динамической памяти

public:
	//Constructors:
	String(int size=80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "defaultConstructor:\t" << this << endl;
	}
	//String(const char*)
	~String()
	{
		delete[]str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << end;
	}

};
void main()
{
	setlocale(LC_ALL, "rus");

}