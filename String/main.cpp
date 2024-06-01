#include<iostream>

using namespace std;


class String
{
	char* str;
	int size;
public:
	void set_str(char* str)
	{
		if (this->str)delete[]str;
		size = strlen(str);
		this->str = new char[size + 1];
		strcopy(this->str, str);
		this->str[size] = '\0';
	}
	char* get_str()const
	{
		return str;
	}
	void set_size(int size)
	{
		this->size = size;
	}
	int get_size()const
	{
		return length(get_str());
	}

	String()//строка длиной 80байт +1 под \0
	{
		size = 81;
		str = new char[80 + 1];
		str[0] = '\0';
		cout << "default" << endl;

	}
	String(const char* str)
	{
		size=(length(str));
		this->str = new char[size + 1];
		strcopy(this->str, str);
		this->str[size] = '\0';
		cout << "const_one_arg" << endl;
	}
	String(const String &other)//copy constr
	{
		size = (length(other.str));
		this->str = new char[size + 1];
		strcopy(this->str, other.str);
		this->str[size] = '\0';
		cout << "CopyConstructor:\t" << this << endl;
	}

	~String()
	{
		cout << "destruct" << endl;
		delete[]str;
	}
	//			Operators:
	String& operator=(const String &other)
	{
		if (this == &other)return *this;
		if (this->str)delete[]str;
		this->size = length(other.str);
		str = new char[size + 1];
		strcopy(this->str, other.str);
		this->str[size] = '\0';
		return *this;
	}
	char& operator[](const int index)
	{
		return this->str[index];
	}
	//method
	int length(const char* str)const//size
	{
		int i = 0;
		while (str[i] != '\0')
		{
			i++;
		}
		return i;
	}
	char* strcopy(char* set, const char* str)//copy
	{
		char* Buffer = set;
		for (int i = 0; str[i] != '\0'; i++)
		{
			Buffer[i] = str[i];
		}
		return Buffer;
	}
	void Print()//show
	{
		cout << str << endl;
	}
};
String operator+(const String& left, const String& right)
{
	String Buffer;
	int size = left.get_size() + right.get_size();
	Buffer = new char[size + 1];
	Buffer.set_size(size);
	Buffer.strcopy(Buffer.get_str(), left.get_str());
	Buffer.strcopy(Buffer.get_str()+left.get_size(), right.get_str());
	Buffer[size]='\0';
	return Buffer;

}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	char buffer[256];
	//is >> buffer;
	cin.getline(buffer, 256);
	obj = String(buffer);
	return is;
}

void main()
{

	//String str;
	String str1 = "Hello";
	str1.Print();
	String str2 = "World";
	str2.Print();
	//str1 = str2;
	str1.Print();

	String str3;
	str3= str1 + str2;
	str3.Print();
	cout << str3 << endl;
	cin >> str3;
	cout << str3 << endl;

}