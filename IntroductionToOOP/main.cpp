#include<iostream>

using namespace std;

class Point //������� ��������� 'Point', ������� ����� ��������� ����� �� ���������.
{
	double x;
	double y;
public:
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	// Costructors:
	
	/*Point()
	{
		x = y = 0;
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgumetConstructor:\t" << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "FullArgumetConstructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	
	//				Operators
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	/*double distance()const
	{
	// �� 0 �� �����
		return sqrt(x * x + y * y);
	}
	*/
	
	//				Methodes
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		//double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return sqrt(pow(x_distance,2) + pow(y_distance,2));
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}

	Point& operator++()//prefix incriment
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)//Suffix increment
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}
	Point& operator()(double x, double y)
	{
		//Function-call operator
		set_x(x);
		set_y(y);
		return *this;
	}

};
Point operator+(const Point& Left, const Point& right)
{
	Point result;
	result.set_x(Left.get_x() + right.get_x());
	result.set_y(Left.get_y() + right.get_y());
	return result;
}
bool operator==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}


double distance(const Point& A, const Point& B)
{
	/*
	double Dx = A.get_x() - B.get_x();
	double Dy = A.get_y() - B.get_y();
	return sqrt(Dx * Dx + Dy * Dy);
	*/
	return (double)sqrt(pow(B.get_x() - A.get_x(),2) + pow(B.get_y() - A.get_y(),2));
}
std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	/*os << " X = " << obj.get_x() << "\tY = " << obj.get_y();
	return os;*/
	return os << " X = " << obj.get_x() << "\tY = " << obj.get_y();
}

std::istream& operator>>(std::istream& is,Point& obj)
{
	 double x, y;
	 is >> x >> y;
	 /*obj.set_x(x);
	 obj.set_y(y);*/
	 obj(x, y);
	 return is;
}
//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGMENT_CHECK
//#define OPERATORS_CHECK
void main()
{
	
	setlocale(LC_ALL, "rus");
	#ifdef STRUCT_POINT
		cout << "Hello OOP" << endl;

	int a;		//���������� ��������� 'a' ���� 'int'
	Point A;	//���������� ��������� 'a' ���� 'Point'
	//�������� ������� '�' ��������� 'Point'
	//�������� ���������� ��������� 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	cout << sizeof(Point);
	cout << sizeof(A);
	Point* pA = &A;
	cout << (*pA).x << "\t" << (*pA).y << endl;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << "��������� �� ����� � �� ����� � " << A.distance(B) << endl;
	cout << "��������� �� ����� � �� ����� � " << B.distance(A) << endl;
	cout << "��������� �� ����� � �� ����� � " << distance(A, B)<<endl;
	cout << "��������� �� ����� � �� ����� � " << distance(B, A)<<endl;


#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A;
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGMENT_CHECK
	//Point A(2, 3);
//Point B = A;//CopyConstructor
//B = A;		//CopyAssignment

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();

	/*
		Point(2, 3);����� ���� ���������� �����������, � ��������� ��������� ���������� ������.
		*/
#endif // ASSIGMENT_CHECK

#ifdef OPERATORS_CHECK
	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	C.print();
	++C;
	C.print();
	C++;
	C.print();

	Point D = C++;
	C.print();
	D.print();
	cout << (C == D) << endl;

#endif // OPERATORS_CHECK

	Point A(2, 3);
	cout << "������� ���������� �����: "; cin >> A;
	cout << A << endl;


}

/*
-------------------------------------------------------------
.  - �������� ������� �������, ������������ ��� ��������� � ����� ������� �� ����� �������;
-> - �������� ���������� �������, ������������ ��� ��������� � ����� ������� �� ������ �������;
-------------------------------------------------------------
*/

/*
-------------------------------------------------------------
1. Encapsulation - ��� �������� ������������ ����� ������ �� �������� ����;
	private:	�������� ����, ��������� ������ ������ ������;
	public:		�������� ����, ��������� � ����� ����� ���������;
	protected:	���������� ����, ��������� ������ ������, � ��� �������� �������;

	get/set-������
	get (�����, ��������) - ��������� ������ � �������� ���������� �� ������, �.�.,
							��������� �������� �������� �������� ���������� � ������.
	set (������, ����������) - ��������� ������ � �������� ���������� �� ������, �.�.,
							   ��������� ������ �������� �������� ����������.
							   ����� ����, set-������ ������������ ���������� ������,
							   �.�., ������������� ��������� ������������ ������
							   � ���������� ����� ������, ������ �������, set-������
							   ��� �� ����������� ������������ ������ ������, �� ������ �� ��,
							   ��� ������ ������ ���� ������ ������ � ����������.
2. Inheritance;
3. Polymorphism;
-------------------------------------------------------------
*/

/*
-------------------------------------------------------------
1. Constructor - ��� �����, ������� ������� ������;
	-� �����������;
	-��� ����������;
	-�� ��������� (Default constructor) - ��� �����������, ������� ����� ���� ������ ��� ����������;
	-����������� ����������� (Deep copy);
	-����������� ��������;
2. ~Destructor - ��� �����, ������� ���������� ������ �� ��������� ��� ������� �����;
3. CopyAssignment; Memory leak
-------------------------------------------------------------
*/