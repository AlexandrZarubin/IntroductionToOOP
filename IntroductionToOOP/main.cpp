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
	double distance()const
	{
		return sqrt(x * x + y * y);
	}
};
double distance(const Point& A, const Point& B)
{
	/*
	double Dx = A.get_x() - B.get_x();
	double Dy = A.get_y() - B.get_y();
	return sqrt(Dx * Dx + Dy * Dy);
	*/

	return (double)sqrt(pow(B.get_x() - A.get_x(),2) + pow(B.get_y() - A.get_y(),2));
}

//#define STRUCT_POINT
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

	Point A;
	A.set_x(2);
	A.set_y(3);
	Point B;
	B.set_x(-5);
	B.set_y(-3);
	cout<< A.get_x() << "\t" << A.get_y() << endl;
	cout << A.distance() << endl;
	cout << distance(A, B);
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